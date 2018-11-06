/*****************************************************************************
**               AMICCOM Electronics Corporation Document                   **
**          Copyright (c) 2011-2014 AMICCOM Electronics Corporation         **
**                                                                          **
**      A3,1F,No.1, Li-Hsin 1th Road, Science_Based Industrid Park,         **
**                       Hsin_Chu City, 300, Taiwan, ROC.                   **
**                 Tel: 886-3-5785818   Fax: 886-3-5785819                  **
**         E-mail:info@amiccom.com.tw  http: //www.amiccom.com.tw           **
*****************************************************************************/
#include "define.h"
#include "A8107.h"
#include "LibFunction.h"

void InitMCU(void);
/*********************************************************************
** InitMCU
*********************************************************************/
void InitMCU(void)
{
    uint16_t idata i;

    P0 	  = 0xFF;
    P0OE  = 0x00;
    P0PUN = 0x00;
    P0WUN = 0xFF;
    
    P1 	  = 0xFF;
    P1OE  = 0x00;
    P1PUN = 0x00;
    P1WUN = 0xFF;

    P2 	  = 0xFF;
    P2OE  = 0x00;
    P2PUN = 0x00;
    P2WUN = 0xFF;
    
    P3 	  = 0xFF;
    P3OE  = 0x00;
    P3PUN = 0x00;
    P3WUN = 0xFF;

    //clear XData RAM
    for (i = 0x0000; i < 0x2000; i++)
        XBYTE[i] = 0x00;

    /*********************************************/
    /*    MCU Frequency setting (Dont Modify)    */
    PCONE |= 0x01;  //SYSCLK = 16MHz / 2 = 8MHz  */
    PCON  = (PCON&0xEF) | 0x01;  //Enable CKSE   */  
    RSFLAG = 0x07;  //CLEAR PORF,RESETNF         */
    /*********************************************/

    check_stable = 0x5AA5;
}

