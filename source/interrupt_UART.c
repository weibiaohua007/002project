 /*****************************************************************************
**               AMICCOM Electronics Corporation Document                   **
**          Copyright (c) 2011-2015 AMICCOM Electronics Corporation         **
**                                                                          **
**      A3,1F,No.1, Li-Hsin 1th Road, Science_Based Industrid Park,         **
**                       Hsin_Chu City, 300, Taiwan, ROC.                   **
**                 Tel: 886-3-5785818   Fax: 886-3-5785819                  **
**         E-mail:info@amiccom.com.tw  http: //www.amiccom.com.tw           **
*****************************************************************************/
#include "define.h"
#include "A8107.h"
#include "LibFunction.h"

uint8_t xdata BLE_INT_FLAG;

extern void Uart1IRQ(void);
extern void Timer1IRQ(void);

/*********************************************************************
** INT1_ISR
*********************************************************************/
void INT1_ISR(void) interrupt 2
{
    // User can add code
    _nop_();
}

/*********************************************************************
** Timer1_ISR
*********************************************************************/
void Timer1_ISR(void) interrupt 3
{
    // User can add code
    Timer1IRQ();//_nop_();
}

/*********************************************************************
** Uart0Isr
*********************************************************************/
void Uart0Isr(void) interrupt 4
{
    // User can add code
    Uart1IRQ();//_nop_();
}

/*********************************************************************
** Timer2_ISR
*********************************************************************/
void Timer2_ISR(void) interrupt 5
{
    // User can add code
    _nop_();
}

/*********************************************************************
** INT2_ISR
*********************************************************************/
void INT2_ISR(void) interrupt 7
{
    // User can add code
    _nop_();
}

/*********************************************************************
** INT3_ISR
*********************************************************************/
void SleepTimer1_ISR(void) interrupt 8
{
    // User can add code
    _nop_();
}

/*********************************************************************
** INT4_ISR
*********************************************************************/
void RTC_ISR(void) interrupt 9
{
    // User can add code
    _nop_();
}

/*********************************************************************
** RFISR
*********************************************************************/
void RFISR(void) interrupt 10
{
    PCON |= 0x01;
    EIF = 0x08;

    if((XBYTE[TMR0CTL_REG]&0x20) == 0x20)
    {        
        BLE_SLAVE_PROCESS();
    }
		
    /* -------- RF_Timer500ms -------- */
    if(XBYTE[VCOC_REG]&0x80)
    {
        XBYTE[VCOC_REG] = rf_config_w[VCOC_REG-0x2000]|0x80;
        Timer500ms_flag = 1;
    }
    /* ------------------------------- */
}

/*********************************************************************
** INT4_ISR
*********************************************************************/
void KeyINT_ISR(void) interrupt 11
{
    // User can add code
    _nop_();
}
