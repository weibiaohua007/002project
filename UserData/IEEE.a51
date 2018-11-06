;/*****************************************************************************
;**               AMICCOM Electronics Corporation Document                   **
;**          Copyright (c) 2011-2014 AMICCOM Electronics Corporation         **
;**                                                                          **
;**      A3,1F,No.1, Li-Hsin 1th Road, Science_Based Industrid Park,         **
;**                       Hsin_Chu City, 300, Taiwan, ROC.                   **
;**                 Tel: 886-3-5785818   Fax: 886-3-5785819                  **
;**         E-mail:info@amiccom.com.tw  http: //www.amiccom.com.tw           **
;*****************************************************************************/
NAME    IEEEE_ADDRESS

CSEG AT 0x02F8

DB  0xFF, 0xFF

;================================================ User Modify =================================================

    ; IEEE Address
        ; for ICE 
            DB  0x18, 0x7A, 0x93, 0x85, 0x08, 0x01  ;Test
            ;DB  0xD0, 0x39, 0x72, 0xA5, 0xEF, 0x24	;WeChat
            ;DB  0x18, 0x7A, 0x93, 0x15, 0x08, 0x2D	;TaoBao
        ; for Writer
            ;DB  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF

;================================================= Modify END =================================================

END