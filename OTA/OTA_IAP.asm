;------------------------------------------------------------------------------
; File name: OTA_IAP.asm
; Version: v7
;------------------------------------------------------------------------------
#include "OTA_IAP.inc"
EXTRN CODE (STARTUP1)

;------------------------------------------------------------------------------
; DATA memory
;   0x00~0x1F - BANK 0~3
;   0x20~0x2F - Bit accessable
;   0x30~0x4F - general use direct memory
;   0x60~0x7F - stack (48bytes)
;------------------------------------------------------------------------------
#define GLOBAL_DATA_START   0x30
    SourceDPH   equ     GLOBAL_DATA_START+0
    SourceDPL   equ     GLOBAL_DATA_START+1
    SourceBank  equ     GLOBAL_DATA_START+2
    TargetDPH   equ     GLOBAL_DATA_START+3
    TargetDPL   equ     GLOBAL_DATA_START+4
    TargetBank  equ     GLOBAL_DATA_START+5
    UpdateDPH   equ     GLOBAL_DATA_START+6
    BDCountL    equ     GLOBAL_DATA_START+7     ; Battery Detect Count L
    BDCountH    equ     GLOBAL_DATA_START+8     ; Battery Detect Count H
    TryCount    equ     GLOBAL_DATA_START+9
    ReadData    equ     GLOBAL_DATA_START+10
    Buffer      equ     GLOBAL_DATA_START+16

;------------------------------------------------------------------------------
; SST flash control
#define FNOP                0x00
#define WRITE_BYTE          0x01
#define SECTOR_ERASE        0x04
#define MCU_XTAL            16

;------------------------------------------------------------------------------
; OTA define
#define OTA_CODE_ADDRESS        0xFFFE
#define OTA_CODE_L              0x5A
#define OTA_CODE_H              0xA5
#define OTA_START_DPH           (INTERRUPT_OFFSET>>8)
#define OTA_STOP_DPH            0xFF
#define TRY_COUNT               10
#define OTA_ERROR_RECODE        0xFFF8

;------------------------------------------------------------------------------
; Battery detect define
#define BATTERY_DETECT_COUNT    27273    /* echo battery detect about 55us, 100ms/55us = 1818 */

sfr CODEBANK    = 0x94;
sfr TA          = 0xEB;
sfr FLASHCTRL   = 0x9A;
sfr FLASHTMR    = 0x9B;
sfr EIE         = 0xE8;
sfr EIF         = 0x91;
;sfr PCON        = 0x87;
sfr P0OE        = 0xD1;
sfr P0PUN       = 0xD2;
sfr RSFLAG      = 0xBA;
sfr WDCON       = 0xD8;

        CSEG    AT      IAP_PROCESS_ADDRESS

OTA_BEGIN:
        mov     SP, #0x60
        mov     CODEBANK,#0
        mov     IE,#0
        mov     R3,#0
        
        mov     A, #FNOP
        call    F_FlashControl
        
        mov     BDCountL, #(BATTERY_DETECT_COUNT mod 256)
        mov     BDCountH, #(BATTERY_DETECT_COUNT /   256)
_OTA_BatteryDetect:
        call    F_BatteryDetect                 ; run bettery detect (PASS: return A=1, NOT PASS: return A=0)
        jz      _OTA_PROCESS_Reset              ; if A==0, jump to 0x0000 (reset MCU)
        djnz    BDCountL, _OTA_BatteryDetect
        mov     a, BDCountH
        jz      _OTA_START
        djnz    BDCountH, _OTA_BatteryDetect     ; if bettery detect pass with BDCount times, OTA START
        jmp     _OTA_BatteryDetect

_OTA_START:
        mov     DPTR, #OTA_CODE_ADDRESS
    _OTA_PROCESS_CHECK_CODE_L:
        clr     a
        movc    a, @a+DPTR
        cjne    a, #0xFF, _OTA_PROCESS_END

    _OTA_PROCESS_CHECK_CODE_H:
        mov     a, #1
        movc    a, @a+DPTR
        cjne    A, #0xFF, _OTA_PROCESS_END

    _OTA_PROCESS_CHECK_BANK_CODE_LH:
        mov     CODEBANK,#2
        mov     DPTR, #OTA_CODE_ADDRESS
        clr     a
        movc    a, @a+DPTR
        cjne    a, #0x5A, _OTA_PROCESS_END
        mov     a, #1
        movc    a, @a+DPTR
        cjne    A, #0xA5, _OTA_PROCESS_END
        mov     R3,#0x5A
        mov     CODEBANK,#0
		
        jmp     _OTA_PROCESS

_OTA_PROCESS_END:
        call    F_ClrPWE
        jmp     OTA_END

_OTA_PROCESS_Reset:
_OTA_PROCESS_FINISH:
        jmp     0x0000  ; reset

_OTA_PROCESS:
        call    F_FlashSetting
        mov     UpdateDPH, #OTA_START_DPH

    _OTA_PROCESS_Loop:
        mov     TryCount, #TRY_COUNT
    _OTA_PROCESS_Loop_ReTry:
        djnz    TryCount, _OTA_PROCESS_Erase
        jmp     _OTA_PROCESS_FAIL
    
    _OTA_PROCESS_Erase:
        mov     DPH, UpdateDPH
        mov     DPL, #0x00
        call    F_SetPWE
        call    F_EraseSector

        ; if (UpdateDPH >= 0x80)
        ;   { SourceBank=2; SourceDPH=UpdateDPH;      TargetBank=0; TargetDPH=UpdateDPH; }
        ; else
        ;   { SourceBank=1; SourceDPH=UpdateDPH+0x80; TargetBank=0; TargetDPH=UpdateDPH; }
        mov     a, UpdateDPH
        clr     C
        subb    a, #0x80
        jc      _OTA_PROCESS_UPDATE_0000_7F00

    _OTA_PROCESS_UPDATE_8000_FF00:
        mov     SourceBank, #2
        mov     SourceDPH, UpdateDPH
        mov     TargetBank, #0
        mov     TargetDPH, UpdateDPH
        jmp     _OTA_PROCESS_UPDATE

    _OTA_PROCESS_UPDATE_0000_7F00:
        mov     SourceBank, #1
        mov     a, #0x80
        add     a, UpdateDPH
        mov     SourceDPH, a
        mov     TargetBank, #0
        mov     TargetDPH, UpdateDPH

    _OTA_PROCESS_UPDATE:
        call    F_Update256Bytes
        jnz     _OTA_PROCESS_Loop_ReTry

        mov     a, UpdateDPH
        cjne    a, #OTA_STOP_DPH, _OTA_PROCESS_NEXT
        mov     A, #FNOP
        call    F_FlashControl		        
        jmp     _OTA_PROCESS_FINISH

    _OTA_PROCESS_NEXT:
        inc     UpdateDPH
        jmp     _OTA_PROCESS_Loop
        
    _OTA_PROCESS_FAIL:
        mov     Buffer+0, @R0
        mov     Buffer+1, R0
        mov     Buffer+2, DPH
        mov     Buffer+3, DPL
        mov     a, #0
        movc    a, @a+DPTR
        mov     Buffer+4, a
        mov     Buffer+5, #0x00
        mov     Buffer+6, #0xEE
        mov     Buffer+7, #0x11
        mov     DPTR, #OTA_ERROR_RECODE
        mov     a, #8
        call    F_SetPWE
        call    F_Write_A_Bytes
        jmp     $

;------------------------------------------------------------------------------
; Function: Update 256bytes SourceBank:SourceDPH:00 -> TargetBank:TargetDPH:00
;   R6: count
;   R5: DPL
;------------------------------------------------------------------------------
F_Update256Bytes:
        mov     R5, #0x00
        mov     R6, #(256/16)

    _F_Update256Bytes_Loop:
        mov     DPH, SourceDPH
        mov     DPL, R5
        mov     CODEBANK, SourceBank
        call    F_Read16Bytes

        mov     DPH, TargetDPH
        mov     DPL, R5
        mov     CODEBANK, TargetBank
        call    F_SetPWE
        call    F_Write16Bytes
        
        mov     DPH, TargetDPH
        mov     DPL, R5
        mov     CODEBANK, TargetBank
        call    F_Verify16Bytes
        jnz     _F_Update256Bytes_FAIL

        mov     a, R5
        add     a, #16
        mov     R5, a

        djnz    R6, _F_Update256Bytes_Loop
    _F_Update256Bytes_PASS:
        mov     a, #0x00
        ret
    _F_Update256Bytes_FAIL:        
        mov     a, #0xFF
        ret

;------------------------------------------------------------------------------
; Function: Read flash @DPTR 16bytes -> Buffer
;   R7: read count
;------------------------------------------------------------------------------
F_Read16Bytes:
        mov     R0, #Buffer
        mov     R7, #16
    _F_Read16Bytes_Loop:
        mov     a, #0
        movc    a, @a+DPTR
        mov     @R0, a
        inc     DPTR
        inc     R0
        djnz    R7, _F_Read16Bytes_Loop
        ret
        
;------------------------------------------------------------------------------
; Function: Verify flash Buffer<->@DPTR 16bytes
;   R7: read count
;------------------------------------------------------------------------------
F_Verify16Bytes:
        mov     R0, #Buffer
        mov     R7, #16
    _F_Verify16Bytes_Loop:
        mov     ReadData, @R0
        mov     a, #0
        movc    a, @a+DPTR
        cjne    a, ReadData, _F_Verify16Bytes_FAIL
        inc     DPTR
        inc     R0
        djnz    R7, _F_Verify16Bytes_Loop
    _F_Verify16Bytes_PASS:
        mov     a, #0x00
        ret

    _F_Verify16Bytes_FAIL:
        mov     a, #0xFF
        ret

;------------------------------------------------------------------------------
; Function: Write ACC bytes Buffer -> @DPTR
;   R7: program count
;------------------------------------------------------------------------------
F_Write_A_Bytes:
        mov     R7, a
        jmp     _F_Write_A_Bytes_Start

;------------------------------------------------------------------------------
; Function: Write 16 bytes Buffer -> @DPTR
;   R7: program count
;------------------------------------------------------------------------------
F_Write16Bytes:
        mov     A, #WRITE_BYTE
        call    F_FlashControl

        mov     a, DPH                  ;
        clr     C                       ;
        subb    a, #OTA_START_DPH       ;
        jc      _F_Write16Bytes_end     ; if (DPH<OTA_START_DPH) exit

        mov     a,RSFLAG
        anl     a,#0x07
        jz      _CHECK_WDT2_
;        jmp     _OTA_PROCESS_END
        jmp     _CHECK_R3_OTA_DATA2_

    _CHECK_WDT2_:
        mov     a,WDCON
        anl     a,#0x04
        jnz     _F_Write_START
        jmp     _CHECK_R3_OTA_DATA2_
        
    _F_Write16Bytes_STOP:
        jmp     _OTA_PROCESS_END

    _CHECK_R3_OTA_DATA2_:
        mov     a, #0x5A
        clr     c
        subb    a,R3
        jnz     _F_Write16Bytes_STOP    

    _F_Write_A_Bytes_Start:
    _F_Write_START:               
        mov     R7, #16
        mov     R0, #Buffer
    _F_Write16Bytes_Loop:
        mov     a, @R0
        cjne    a, #0xFF, _F_Write16Bytes_Write
        jmp     _F_Write16Bytes_Next
    _F_Write16Bytes_Write:
        movx    @dptr,a
    _F_Write16Bytes_Next:
        inc     dptr
        inc     R0
        djnz    R7, _F_Write16Bytes_Loop

    _F_Write16Bytes_end:
        call    F_ClrPWE
        ret

;------------------------------------------------------------------------------
; Function: Erase Sector @DPTR
;------------------------------------------------------------------------------
F_EraseSector:
        mov     A, #SECTOR_ERASE
        call    F_FlashControl

        mov     a, DPH              ;
        clr     C                   ;
        subb    a, #OTA_START_DPH   ;
        jc      _F_EraseSector_end  ; if (DPH<OTA_START_DPH) exit
        
        mov     a,RSFLAG
        anl     a,#0x07
        jz      _CHECK_WDT_
        jmp     _CHECK_R3_OTA_DATA_

    _CHECK_WDT_:
        mov     a,WDCON
        anl     a,#0x04
        jnz     _EraseSector_START
        jmp     _CHECK_R3_OTA_DATA_

    _F_EraseSector_STOP:
        jmp     _OTA_PROCESS_END
        
    _CHECK_R3_OTA_DATA_:
        mov     a, #0x5A
        clr     c
        subb    a,R3
        jnz     _F_EraseSector_STOP  

    _EraseSector_START:                
        movx    @dptr,a
    _F_EraseSector_end:
        call    F_ClrPWE
        ret

;------------------------------------------------------------------------------
; Function: Flash setting
;------------------------------------------------------------------------------
F_FlashSetting:
        mov     ta, #0xaa
        mov     ta, #0x55
        mov     flashtmr, #MCU_XTAL
        ret

;------------------------------------------------------------------------------
; Function: write A to Flash control SFR
;------------------------------------------------------------------------------
F_FlashControl:
        mov     ta, #0xaa
        mov     ta, #0x55
        mov     flashctrl, a
        ret

;------------------------------------------------------------------------------
; Function: PWE = 1
;------------------------------------------------------------------------------
F_SetPWE:
        mov     a,pcon
        setb    acc.4
        mov     pcon,a
        ret

;------------------------------------------------------------------------------
; Function: PWE = 0
;------------------------------------------------------------------------------
F_ClrPWE:
        mov     a,pcon
        clr     acc.4
        mov     pcon,a
        ret
        
;------------------------------------------------------------------------------
; Function: Battery Detect (wait, until REGI high then 2.5V)
; 0x202B:
;   BIT7  BIT6  BIT5  BIT4  BIT3  BIT2  BIT1  BIT0
;   RGS   RGV1  RGV0  BDF   BVT2  BVT1  BVT0  BDS
; BVT[2:0] = 001 for 2.1V
; BVT[2:0] = 101 for 2.5V
; BVT[2:0] = 110 for 2.6V
;------------------------------------------------------------------------------
F_BatteryDetect:
        mov     DPTR, #0x2038 ; RFT Test Register IV
        mov     a, #0x90      ; DSB=1, FBG=16
        movx    @DPTR, a
        mov     DPTR, #0x202B ; Battery detect Register
        mov     a, #0x25      ; RGS=0b(VDDS=1.8V), RGV=01b(VDD_D,VDD_A=2.0V), BVT=001b(2.1V), BDS=1
        movx    @DPTR, a
    _F_BatteryDetectLoop:
        movx    a, @DPTR
        jb      acc.0, _F_BatteryDetectLoop
        jb      acc.4, _F_BatteryDetect_BDF_1
    _F_BatteryDetect_BDF_0:       
        call    F_short_delay
        mov     a, #0
        ret
		
    _F_BatteryDetect_BDF_1:
        call    F_short_delay
        mov     a, #1
        ret

F_short_delay:
        mov     R4, #25
    _F_short_delay_loop:
        djnz    R4, _F_short_delay_loop
        ret

;------------------------------------------------------------------------------
; OTA END
;------------------------------------------------------------------------------
                CSEG    at       INTERRUPT_OFFSET
OTA_END:
        LJMP    STARTUP1

        end