/*--------------------------------------------------------------------------*/
/* A8107.H                                                                  */
/*                                                                          */
/* Header file for A8107 RF SoC microcontroller.                            */
/* Copyright (c) 2014 AMICCOM Electronics Corp.                             */
/*                                                                          */
/* All rights reserved.                                                     */
/*--------------------------------------------------------------------------*/
#ifndef __A8107_H__
#define __A8107_H__

//--------------------------------------------------------------------------
// 8051 SFR
//--------------------------------------------------------------------------

/*  BYTE Registers  */
sfr P0      = 0x80;
sfr P1      = 0x90;
sfr P2      = 0xA0;
sfr P3      = 0xB0;
sfr PSW     = 0xD0;
sfr ACC     = 0xE0;
sfr B       = 0xF0;
sfr SP      = 0x81;
sfr DPL     = 0x82;
sfr DPH     = 0x83;
sfr DPL1    = 0x84;
sfr DPH1    = 0x85;
sfr PCON    = 0x87;
sfr TCON    = 0x88;
sfr TMOD    = 0x89;
sfr TL0     = 0x8A;
sfr TL1     = 0x8B;
sfr TH0     = 0x8C;
sfr TH1     = 0x8D;
sfr CKCON   = 0x8E;
sfr EIF     = 0x91;
sfr CODEBANK = 0x94;
sfr SCON    = 0x98;
sfr SBUF    = 0x99;
sfr FLASHCTRL = 0x9A;
sfr TERASE_ID  = 0x9B;
sfr CHIP_TERASE_ID = 0x9C;
sfr PROG_ID = 0x9D;
sfr SBRG0H  = 0x9E;
sfr SBRG0L  = 0x9F;
sfr IE      = 0xA8;
sfr PWM0CON = 0xA9;
sfr PWM0H   = 0xAA;
sfr PWM0L   = 0xAB;
sfr PWM2CON = 0xAC;
sfr PWM2H   = 0xAD;
sfr PWM2L   = 0xAE;
sfr PWM1CON = 0xB1;
sfr PWM1H   = 0xB2;
sfr PWM1L   = 0xB3;
sfr PWM3CON = 0xB4;
sfr PWM3H   = 0xB5;
sfr PWM3L   = 0xB6;
sfr IP      = 0xB8;
sfr PCONE   = 0xB9;
sfr RSFLAG  = 0xBA;
sfr IOSEL   = 0xBB;
sfr T2CON   = 0xC8;
sfr T2IF    = 0xC9;
sfr RCAP2L  = 0xCA;
sfr RCAP2H  = 0xCB;
sfr TL2     = 0xCC;
sfr TH2     = 0xCD;
sfr WDCON   = 0xD8;
sfr EIE     = 0xE8;
sfr TA      = 0xEB;
sfr SPCR    = 0xEC;
sfr SPSR    = 0xED;
sfr SPDR    = 0xEE;
sfr SSCR    = 0xEF;
sfr I2CSADR = 0xF1;
sfr I2CSCR  = 0xF2;
sfr I2CSSR  = 0xF2;
sfr I2CSBUF = 0xF3;
sfr I2CMSA  = 0xF4;
sfr I2CMCR  = 0xF5;
sfr I2CMBUF = 0xF6;
sfr I2CMTP  = 0xF7;
sfr EIP     = 0xF8;

sfr P0OE    = 0xD1;
sfr P0PUN   = 0xD2;
sfr P0WUN   = 0xD3;

sfr P1OE    = 0xD9;
sfr P1PUN   = 0xDA;
sfr P1WUN   = 0xDB;

sfr P2OE    = 0xA1;
sfr P2PUN   = 0xA2;
sfr P2WUN   = 0xA3;

sfr P3OE    = 0xE1;
sfr P3PUN   = 0xE2;
sfr P3WUN   = 0xE3;

/*  BIT Registers  */
/*  PSW  */
sbit CY     = PSW^7;
sbit AC     = PSW^6;
sbit F0     = PSW^5;
sbit RS1    = PSW^4;
sbit RS0    = PSW^3;
sbit OV     = PSW^2;
sbit P      = PSW^0;

/*  TCON  */
sbit TF1    = TCON^7;
sbit TR1    = TCON^6;
sbit TF0    = TCON^5;
sbit TR0    = TCON^4;
sbit IE1    = TCON^3;
sbit IT1    = TCON^2;
sbit IE0    = TCON^1;
sbit IT0    = TCON^0;

/*  IE  */
sbit EA     = IE^7;
sbit ET2    = IE^5;
sbit ES     = IE^4;
sbit ET1    = IE^3;
sbit EX1    = IE^2;
sbit ET0    = IE^1;
sbit EX0    = IE^0;

/*  IP  */
sbit PT2    = IP^5;
sbit PS     = IP^4;
sbit PT1    = IP^3;
sbit PX1    = IP^2;
sbit PT0    = IP^1;
sbit PX0    = IP^0;

/*  P3  */
sbit RD     = P3^7;
sbit WR     = P3^6;
sbit T1     = P3^5;
sbit T0     = P3^4;
sbit INT1   = P3^3;
sbit INT0   = P3^2;
sbit TXD    = P3^1;
sbit RXD    = P3^0;

/*  SCON  */
sbit SM0    = SCON^7;
sbit SM1    = SCON^6;
sbit SM2    = SCON^5;
sbit REN    = SCON^4;
sbit TB8    = SCON^3;
sbit RB8    = SCON^2;
sbit TI     = SCON^1;
sbit RI     = SCON^0;

/*  P1  */
sbit T2EX   = P1^1;
sbit T2     = P1^0;

/*  T2CON  */
sbit TF2    = T2CON^7;
sbit EXF2   = T2CON^6;
sbit RCLK   = T2CON^5;
sbit TCLK   = T2CON^4;
sbit EXEN2  = T2CON^3;
sbit TR2    = T2CON^2;
sbit C_T2   = T2CON^1;
sbit CP_RL2 = T2CON^0;

/*  P0  */
sbit P0_7   = P0^7;
sbit P0_6   = P0^6;
sbit P0_5   = P0^5;
sbit P0_4   = P0^4;
sbit P0_3   = P0^3;
sbit P0_2   = P0^2;
sbit P0_1   = P0^1;
sbit P0_0   = P0^0;

/*  P1  */
sbit P1_7   = P1^7;
sbit P1_6   = P1^6;
sbit P1_5   = P1^5;
sbit P1_4   = P1^4;
sbit P1_3   = P1^3;
sbit P1_2   = P1^2;
sbit P1_1   = P1^1;
sbit P1_0   = P1^0;

/*  P2  */
sbit P2_7   = P2^7;
sbit P2_6   = P2^6;
sbit P2_5   = P2^5;
sbit P2_4   = P2^4;
sbit P2_3   = P2^3;
sbit P2_2   = P2^2;
sbit P2_1   = P2^1;
sbit P2_0   = P2^0;

/*  P3  */
sbit P3_7   = P3^7;
sbit P3_6   = P3^6;
sbit P3_5   = P3^5;
sbit P3_4   = P3^4;
sbit P3_3   = P3^3;
sbit P3_2   = P3^2;
sbit P3_1   = P3^1;
sbit P3_0   = P3^0;

/* EIE */
sbit EX2    = EIE^0;
sbit EX3    = EIE^1;
sbit EX4    = EIE^2;
sbit EX5    = EIE^3;
sbit EX6    = EIE^4;
sbit EWDI   = EIE^5;
sbit EI2CM  = EIE^6;
sbit EI2CS  = EIE^7;
sbit ESPI   = EIE^7;


//--------------------------------------------------------------------------
// RF Register
//--------------------------------------------------------------------------
#define RST_REG         0x2000
#define STROBE_REG      0x2001
#define MODECTRL_REG    0x2002
#define CALIBRATION_REG 0x2003
#define FIFO1_REG       0x2004
#define FIFO2_REG       0x2005
#define RCOSC1_REG      0x2006
#define RCOSC2_REG      0x2007
#define RCOSC3_REG      0x2008
#define RCOSC4_REG      0x2009
#define RCOSC5_REG      0x200A
#define RCOSC6_REG      0x200B
#define RCOSC7_REG      0x200C
#define RCOSC8_REG      0x200D
#define CKO_REG         0x200E
#define GIO1_REG        0x200F
#define GIO2_REG        0x2010
#define CLOCK_REG       0x2011
#define DATARATE_REG    0x2012
#define PLL1_REG        0x2013
#define PLL2_REG        0x2014
#define PLL3_REG        0x2015
#define PLL4_REG        0x2016
#define PLL5_REG        0x2017
#define TX1_REG         0x2018
#define TX2_REG         0x2019
#define DELAY1_REG      0x201A
#define DELAY2_REG      0x201B
#define RX_REG          0x201C
#define RXGAIN1_REG     0x201D
#define RXGAIN2_REG     0x201E
#define RXGAIN3_REG     0x201F
#define RXGAIN4_REG     0x2020
#define RSSI_REG        0x2021
#define ADC_REG         0x2022
#define CODE1_REG       0x2023
#define CODE2_REG       0x2024
#define CODE3_REG       0x2025
#define IFCAL1_REG      0x2026
#define IFCAL2_REG      0x2027
#define VCOC_REG        0x2028
#define VCOBAND1_REG    0x2029
#define VCOBAND2_REG    0x202A
#define BATTERY_REG     0x202B
#define TXTEST_REG      0x202C
#define RXDEM1_REG      0x202D
#define RXDEM2_REG      0x202E
#define CPC1_REG        0x202F
#define CRYSTAL_REG     0x2030
#define PLLTEST_REG     0x2031
#define VCOTEST1_REG    0x2032
#define VCOTEST2_REG    0x2033
#define IFAT_REG        0x2034
#define RFTEST1_REG     0x2035
#define RFTEST2_REG     0x2036
#define RFTEST3_REG     0x2037
#define RFTEST4_REG     0x2038
#define RFTEST5_REG     0x2039
#define CHINDEX_REG     0x203A
#define CRCINIT_REG     0x203B  // 0x083B ~ 0x083D = 3 Bytes
#define CRCINIR_REG     0x203E  // 0x083E ~ 0x0840 = 3 Bytes
#define VCOBAND3_REG    0x2041
#define VCODEV1_REG     0x2042
#define VCODEV2_REG     0x2043
#define VCODEV3_REG     0x2044
#define ADCCONTROL_REG  0x2045
#define WOT_REG         0x2046
#define CHGROUP1_REG    0x2047
#define CHGROUP2_REG    0x2048
#define CPC2_REG        0x2049
#define VCOMODDELAY_REG 0x204A
#define INC_REG         0x204B
#define DET_REG         0x204C
#define BLEHEADER_REG   0x204D  // 0x084D ~ 0x084E = 2 Bytes
#define ID_REG          0x204F  // 0x084F ~ 0x0852 = 4 Bytes
#define USID_REG        0x2053  // 0x0853 ~ 0x0856 = 4 Bytes
#define EXT1_REG        0x2057
#define EXT2_REG        0x2058
#define EXT3_REG        0x2059
#define ADCCTL_REG      0x205A
#define ADCAVG1_REG     0x205B
#define ADCAVG2_REG     0x205C
#define ADCAVG3_REG     0x205D
#define TMR0ITV_REG     0x205E  // 0x205E ~ 0x205F = 2 Bytes
#define RFAR_REG        0x2060
#define TMR0WOR1_REG    0x2061
#define TMR0CTL_REG     0x2062
#define PWRCTL0_REG     0x2063
#define PWRCTL1_REG     0x2064
#define PWRCTL2_REG     0x2065
#define PWRCTL3_REG     0x2066
#define PWRCTL4_REG     0x2067
#define DCSHIFT_REG     0x2068
#define TX5DLY_REG      0x2069
#define ACKART_REG      0x207C
#define NONCE_REG       0x207D  // 0x207D ~ 0x2084 = 8 Bytes
#define AESKEY_REG      0x2085  // 0x2085 ~ 0x2094 = 16 Bytes
#define AESDATA_REG     0x2095  // 0x2095 ~ 0x20A4 = 16 Bytes
#define AESCTL_REG      0x20A5
#define TXPKTNUM_REG    0x20A6  // 0x20A6 ~ 0x20A9 = 4 Bytes
#define RXPKTNUM_REG    0x20AA  // 0x20AA ~ 0x20AD = 4 Bytes
#define TMR1ITV_REG     0x20B0
#define TMR1CTL_REG     0x20B2
#define RTCH_REG        0x20B3
#define RTCM_REG        0x20B4
#define RTCS_REG        0x20B5
#define ALARMH_REG      0x20B6
#define ALARMM_REG      0x20B7
#define RTCCTL_REG      0x20B8
#define TCKG0_REG       0x20FE
#define TCKG1_REG       0x20FF

#define TXDATA_REG      0x2200  // 0x2100~0x213F = 64 bytes
#define TXFIFO_REG      TXDATA_REG
#define RXDATA_REG      0x2280  // 0x2180~0x21BF = 64 bytes
#define RXFIFO_REG      RXDATA_REG

//--------------------------------------------------------------------------
// Strobe and Reset Command
//--------------------------------------------------------------------------
/* RF Strobe command */
#define CMD_SLEEP       0x80    // SLEEP mode
#define CMD_IDLE        0x90    // IDLE mode
#define CMD_STBY        0xA0    // Standby mode
#define CMD_PLL         0xB0    // PLL mode
#define CMD_RX          0xC0    // RX mode
#define CMD_TX          0xD0    // TX mode

/* RF Reset command */
#define RF_RST          0x80
#define TXPOINT_RST     0x40
#define RXPOINT_RST     0x20
#define ADC_RST         0x10
#define TXFIFO_RST      0x08
#define BFC_RST         0x04
#define RCADC_RST       0x02

#endif