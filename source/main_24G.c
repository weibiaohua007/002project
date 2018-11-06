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
#include "mcufunction.h"
#include "IAP.h"
#include "servicegen.h"
#include "OTA.h"
#include "Proprietary.h"

uint8_t     xdata   Auto24G_Mode;
uint8_t     xdata   Timer1Flag;
uint16_t    xdata   Timer1Cnt;


void WriteTxFIFO(uint8_t* pu8Data, uint8_t u8Len)
{
    uint8_t i;

    for (i = 0; i < u8Len; i++)
    {
        XBYTE[TXFIFO_REG + i] = *(pu8Data + i);
    }
}

void ReadRxFIFO(uint8_t* pu8Data, uint8_t u8Len)
{
    uint8_t i;

    for (i = 0; i < u8Len; i++)
        *(pu8Data + i) = XBYTE[RXFIFO_REG + i];
}

/*****************************************************************************
**  ROUTINE NAME: Disable Timer0                                            **
**  FUNCTION    : Disable Timer0                                            **
*****************************************************************************/
void DisableTimer1(void)
{
    Timer1Flag = DISABLE;
    TR1        = DISABLE;
    ET1        = DISABLE;
}

/*****************************************************************************
**  ROUTINE NAME: Enable Timer0                                             **
**  FUNCTION    : Enable Timer0                                             **
*****************************************************************************/
void EnableTimer1(void)
{
//    P0_3 ^=1;
    Timer1Flag = ENABLE;
    TR1        = ENABLE;
    ET1        = ENABLE;
}

/*****************************************************************************
**  FUNCTION    : Start 2.5ms timer0                                        **
*****************************************************************************/
void Set_Timer1_N_ms(uint8_t value)
{
    uint32_t t;

    t=(uint32_t)value*2000;
    
    TL1 = t^0xFF;
    TH1 = (t>>8)^0xFF;
    Timer1Cnt=t>>16;
    EnableTimer1();
}

const uint8_t code Prop_ID_Tab[0x04] = {0x54, 0x75, 0xC5, 0x2A};

const uint8_t code Prop_Tx_Tab[20] = {0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA,
    	                     0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA  };

/*******************************************************************
 *
 * main - main function
 * Description:
 *      The function is the system entry point. The whole system is
 *      start from here.
 *
 ******************************************************************/
void main(void)
{
    ADV_InitDef ADV_InitStructure;

    uint8_t xdata   Temp;
    uint8_t xdata   UpdateOTASpeed;
    uint8_t xdata   DataLen;
    uint8_t xdata   AdvFastSpeed = ENABLE;
    uint8_t xdata   *ptrChar = NULL;

    uint16_t xdata   Time_value;

	   void* pvHandle = NULL;
    uint8_t Prop_ID[0x04] = {0x54, 0x75, 0xC5, 0x2A};
    uint8_t Prop_Tx[20] = {0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA,
    	                     0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA  };
    uint8_t Prop_Rx[20];
    
    TS_PR_Param    PropParm;    

//    while(~P0_4);

    InterruptDisable();
    InitMCU();
    
    for (Temp=0;Temp<4;Temp++)
        Prop_ID[Temp] = Prop_ID_Tab[Temp];
        
    for (Temp=0;Temp<20;Temp++)
        Prop_Tx[Temp] = Prop_Tx_Tab[Temp];

    internalRC = 0; //0 :Using External RC 32.768KHz ; 1:Using internal RC 32.000KHz
    
    Auto24G_Mode = 0; //0:Using Customer Tx Rx 1:Using library Tx Rx
    
    InitCrystalCL(0x32);  //AMICCOM CrystalCL 0x32(MD8107-A05)(18pF)/ 0x14(MD8107-A06)(12pF)/ 0x0D(9pF)
    
    InitRF();    
    IAP_Initialize();
    OTA_Initialize();
    
    InitBLE();
    BLE_SetTxPower(6); //level 0 ~ 7 : 0 => -17dBm; 1 => -15dBm; 2 => -10dBm; 3 => -5dBm; 4 => 0dBm; 5 => 2dBm; 6 => 4dBm; 7 => 7dBm
    InterruptEnable();
    
    Prop_Initialize();
    PropParm.Prop_ID = &Prop_ID;
    PropParm.Prop_DR.Prop_DRI = DR1MB_DV250K; 
    PropParm.Prop_DR.Prop_SDR = 1;
    PropParm.Prop_DR.Prop_Ext = 0x00;
    PropParm.Prop_TxWait = 1500;
    PropParm.Prop_RxWS = 5;
    Prop_Create(&PropParm, &pvHandle);    
    memset(Prop_Rx, 0x00, 0x0A);

    while(1)
    {
        OTA_Process();
        
        /* User Can Add Code */
        
        if(ble_state == STANDBY_STATE)
        {
            if (Auto24G_Mode)
            {
                Prop_Start(pvHandle, 50);
                Prop_RunRx(pvHandle, Prop_Rx, 10);
                Prop_RunTx(pvHandle, Prop_Tx, 10);
                Prop_Stop(pvHandle);
            }
            else
            {
                Prop_Start(pvHandle, 50);

                XBYTE[STROBE_REG] = CMD_PLL;
                Time_value = Get_Interval_Time_Left(); //Time_value*0.000152587890625
                //if (Time_value>100)//>15ms
                {
                    WriteTxFIFO(Prop_Tx, 20);
                    XBYTE[FIFO1_REG] = (20 - 1);
                    XBYTE[STROBE_REG] = CMD_TX;
                    while(((XBYTE[STROBE_REG]&0x80) == 0x80) || ((XBYTE[RST_REG]&0x03)==0x03));  //wait WTR go High

                    Set_Timer1_N_ms(5);
                    XBYTE[FIFO1_REG] = (20 - 1);
                    XBYTE[STROBE_REG] = CMD_RX;
                    while((XBYTE[STROBE_REG]&0x80)==0x00)
                        _nop_();
                    
                    while ((Timer1Flag) && (XBYTE[STROBE_REG]&0x80))
                        _nop_();
                    if (XBYTE[STROBE_REG]&0x80)
                        XBYTE[STROBE_REG] = CMD_PLL;
                    else
                    {	
                        ReadRxFIFO(Prop_Rx ,20);
                    }    
                    Set_Timer1_N_ms(5);
                    WriteTxFIFO(Prop_Tx, 20);
                    XBYTE[FIFO1_REG] = (20 - 1);
                    while (Timer1Flag)
                    {
                        XBYTE[STROBE_REG] = CMD_TX;
                        while(((XBYTE[STROBE_REG]&0x80) == 0x80) || ((XBYTE[RST_REG]&0x03)==0x03));  //wait WTR go High
                        for (Temp=0;Temp<200;Temp++)
                        {
                            _nop_();
                            _nop_();
                            _nop_();
                            _nop_();
                            _nop_();
                        }
                    }
                }

                Prop_Stop(pvHandle);
            }

            ADV_InitStructure.ADV_Timing = 0; // ADV Interval = (20ms + 0.625ms*ADV_Timing) = 20ms
            ADV_InitStructure.ADV_TO = 1500;  // ADV Timeout = ADV Interval * ADV_TO = 20ms*1500 = 30 sec
            ADV_InitStructure.ADV_Channel = (TE_ADVCHANNEL)(ADV_CH37);// | ADV_CH38 | ADV_CH39);
            ADV_InitStructure.ADV_Type = ADV_IND;
            ADV_InitStructure.ADV_RndEnable = DISABLE;
            ADV_InitStructure.ADV_TOEnable = ENABLE;
            ADV_InitStructure.ADV_Run = ENABLE;    
            BLE_ADV_Cmd(&ADV_InitStructure);
        }
        else if(ble_state == ADV_STATE)
        {

            if (Auto24G_Mode)
            {
                Prop_Start(pvHandle, 50);
                Prop_RunRx(pvHandle, Prop_Rx, 10);
                Prop_RunTx(pvHandle, Prop_Tx, 10);
                Prop_Stop(pvHandle);
            }
            else
            {
                Prop_Start(pvHandle, 50);

                XBYTE[STROBE_REG] = CMD_PLL;
                Time_value = Get_Interval_Time_Left(); //Time_value*0.000152587890625
                if (Time_value>100)//>15ms
                {
                    WriteTxFIFO(Prop_Tx, 20);
                    XBYTE[FIFO1_REG] = (20 - 1);
                    XBYTE[STROBE_REG] = CMD_TX;
                    while(((XBYTE[STROBE_REG]&0x80) == 0x80) || ((XBYTE[RST_REG]&0x03)==0x03));  //wait WTR go High

                    Set_Timer1_N_ms(5);
                    XBYTE[FIFO1_REG] = (20 - 1);
                    XBYTE[STROBE_REG] = CMD_RX;
                    P0_0 ^=1;
                    while((XBYTE[STROBE_REG]&0x80)==0x00)
                        _nop_();
                    
                    while ((Timer1Flag) && (XBYTE[STROBE_REG]&0x80))
                        _nop_();
                    P0_0 ^=1;
                    if (XBYTE[STROBE_REG]&0x80)
                        XBYTE[STROBE_REG] = CMD_PLL;
                    else
                    {	
                        ReadRxFIFO(Prop_Rx ,20);
                    }    
                        
                    Set_Timer1_N_ms(5);
                    WriteTxFIFO(Prop_Tx, 20);
                    XBYTE[FIFO1_REG] = (20 - 1);
                    while (Timer1Flag)
                    {
                        XBYTE[STROBE_REG] = CMD_TX;
                        while(((XBYTE[STROBE_REG]&0x80) == 0x80) || ((XBYTE[RST_REG]&0x03)==0x03));  //wait WTR go High
                        for (Temp=0;Temp<200;Temp++)
                        {
                            _nop_();
                            _nop_();
                            _nop_();
                            _nop_();
                            _nop_();
                        }
                    }
                }

                Prop_Stop(pvHandle);
            }


            UpdateOTASpeed = ENABLE;
        }
        else if(ble_state == CONNECT_ESTABLISH_STATE)
        {

            if (Auto24G_Mode)
            {
                Prop_Start(pvHandle, 50);
                Prop_RunRx(pvHandle, Prop_Rx, 10);
                Prop_RunTx(pvHandle, Prop_Tx, 10);
                Prop_Stop(pvHandle);
            }
            else
            {
                Prop_Start(pvHandle, 50);

                XBYTE[STROBE_REG] = CMD_PLL;
                Time_value = Get_Interval_Time_Left(); //Time_value*0.000152587890625
                if (Time_value>100)//>15ms
                {
                    WriteTxFIFO(Prop_Tx, 20);
                    XBYTE[FIFO1_REG] = (20 - 1);
                    XBYTE[STROBE_REG] = CMD_TX;
                    while(((XBYTE[STROBE_REG]&0x80) == 0x80) || ((XBYTE[RST_REG]&0x03)==0x03));  //wait WTR go High

                    Set_Timer1_N_ms(5);
                    XBYTE[FIFO1_REG] = (20 - 1);
                    XBYTE[STROBE_REG] = CMD_RX;
                    while((XBYTE[STROBE_REG]&0x80)==0x00)
                        _nop_();
                    
                    while ((Timer1Flag) && (XBYTE[STROBE_REG]&0x80))
                        _nop_();
                    if (XBYTE[STROBE_REG]&0x80)
                        XBYTE[STROBE_REG] = CMD_PLL;
                    else
                    {	
                        ReadRxFIFO(Prop_Rx ,20);
                    }    
                        
                    Set_Timer1_N_ms(5);
                    WriteTxFIFO(Prop_Tx, 20);
                    XBYTE[FIFO1_REG] = (20 - 1);
                    while (Timer1Flag)
                    {
                        XBYTE[STROBE_REG] = CMD_TX;
                        while(((XBYTE[STROBE_REG]&0x80) == 0x80) || ((XBYTE[RST_REG]&0x03)==0x03));  //wait WTR go High
                        for (Temp=0;Temp<200;Temp++)
                        {
                            _nop_();
                            _nop_();
                            _nop_();
                            _nop_();
                            _nop_();
                        }
                    }
                }

                Prop_Stop(pvHandle);
            }

            if (UpdateOTASpeed)
            {
                Temp = (uint8_t)OTA_UpdataSpeed();
               
                if ((OTA_SUCCESSFUL == Temp) || (OTA_COUNT_MAX == Temp))
                    UpdateOTASpeed = DISABLE;
            } /* Changing OTA download speeds */

            if (BLE_writeEventFlag)
            {
                ptrChar = BLE_GetWriteEvent();
                DataLen = BLE_GetWriteEvent_Length();
                
                if (ptrChar == &att_HDL_OTA_OTA_DATA)
                {
                    OTA_SetReceiveData((uint16_t)att_HDL_OTA_OTA_DATA, DataLen);
                    OTA_Process();
                } /* Characteristic Data below the OTA Service */
                else if (ptrChar == &att_HDL_OTA_OTA_CMD_CONTROL_POINT)
                {
                    OTA_SetReceiveData((uint16_t)att_HDL_OTA_OTA_CMD_CONTROL_POINT, DataLen);
                    OTA_Process();
                } /* Characteristic Command below the OTA Service */
                else
                {
                
                }            	
            }

        }
        
        BLE_AutoPwrDown_Enable();
    }
}
