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

#include "..\Uart_OTA\UartOTAFunction.h"

uint8_t xdata		auth_req;
uint8_t xdata		init_req;
uint8_t xdata		index;
uint8_t xdata		auth_init_finish;
uint8_t xdata		scale_index;
uint8_t xdata		KeyWakeup;
uint8_t xdata	sendscaledata;
uint8_t xdata	waitpacket;

#ifdef _PROFILE_TAOBAO_
uint8_t xdata	sendscaledata;
uint8_t xdata scalebuf[10];
uint16_t xdata weightvalue;
uint32_t xdata	datevalue;
#endif

#ifdef _PROFILE_HOGP_
#ifdef _PROFILE_HOGP_MOUSE_
uint8_t xdata HID_report_MS_key_temp;
uint8_t xdata mousedata;
#endif
#ifdef _PROFILE_HOGP_KEYBOARD_
uint8_t xdata HID_report_KB_key_temp;
uint8_t xdata presskey07;
#endif
#ifdef _PROFILE_HOGP_COMSUMER_
uint8_t xdata presskey06; 
#endif
#endif


#ifdef _PROFILE_HOGP_
#ifdef _PROFILE_HOGP_MOUSE_
void MouseDemo(void);
#endif
#endif

#ifdef _PROFILE_TAOBAO_
uint8_t toascii(uint32_t in, uint8_t unit);
void Prcss_Weight(void);
#endif

#ifdef _PROFILE_HOGP_
#ifdef _PROFILE_HOGP_COMSUMER_
#define HDL_HIDS_REPORT_TAB_CSKEY_L                             0
#define HDL_HIDS_REPORT_TAB_CSKEY_H                             1
#endif

#ifdef _PROFILE_HOGP_MOUSE_
#define HDL_HIDS_REPORT_TAB_KEY_L_R                             0
#define HDL_HIDS_REPORT_TAB_DIR_L_R_L                           1
#define HDL_HIDS_REPORT_TAB_DIR_L_R_H                           2
#define HDL_HIDS_REPORT_TAB_DIR_U_D_L                           3
#define HDL_HIDS_REPORT_TAB_DIR_U_D_H                           4
#define HDL_HIDS_REPORT_TAB_ROL_U_D                             5
#endif

#ifdef _PROFILE_HOGP_KEYBOARD_
#define HDL_HIDS_REPORT_TAB_KEY_CTRL                            0
#define HDL_HIDS_REPORT_TAB_KEY_DATA0                           2
#define HDL_HIDS_REPORT_TAB_KEY_DATA1                           3
#define HDL_HIDS_REPORT_TAB_KEY_DATA2                           4
#define HDL_HIDS_REPORT_TAB_KEY_DATA3                           5
#define HDL_HIDS_REPORT_TAB_KEY_DATA4                           6
#define HDL_HIDS_REPORT_TAB_KEY_DATA5                           7
#endif
#endif

#ifdef _PROFILE_HOGP_
#ifdef _PROFILE_HOGP_COMSUMER_
const uint8_t code HID_RPT_CS_KEY_DEMO[][2] =
{
    {0xE9, 0x00,},  //vol+
    {0xEA, 0x00,},  //vol-
    {0xE2, 0x00,},  //Mute
    {0xB0, 0x00,},  //Play
    {0xB1, 0x00,},  //Pause
    //{0xB2, 0x00,},  //Record
    {0xB3, 0x00,},  //Fast forward
    {0xB4, 0x00,},  //Rewind
    {0xB5, 0x00,},  //Scan next track
    {0xB6, 0x00,},  //Scan previous track
    {0xB7, 0x00,},  //Stop
    {0xB8, 0x00,},  //Eject
    {0x8A, 0x01,},  //Email reader
    {0x96, 0x01,},  //Internet browser
    {0x9E, 0x01,},  //Terminal lock/screensaver
    {0xC6, 0x01,},  //Research/search browser
    {0x2D, 0x02,},  //Zoom in
};
#endif
#endif

#ifdef _PROFILE_TAOBAO_
const uint8_t code auth_data_taobao[60]=
{
    0x03, 0x00, 0x26, 0xFE, 0x01, 0x00, 0x26, 0x27,
    0x11, 0x00, 0x01, 0x0A, 0x00, 0x12, 0x10, 0x8A,
    0xB7, 0x40, 0x66, 0x48,                   
    0x7C, 0x9A, 0xDE, 0x17, 0x5B, 0x80, 0xD7, 0xD7,
    0x0C, 0x83, 0x0B, 0x18, 0x83, 0x80, 0x04, 0x20,
    0x01, 0x28, 0x01, 0x32,                   
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

const uint8_t code init_data_taobao[20]=
{
    0x03, 0x00, 0x0D, 0xFE, 0x01, 0x00, 0x0D, 0x27,
    0x13, 0x00, 0x02, 0x0A, 0x00, 0x12, 0x01, 0x7F,
    0x00, 0x00, 0x00, 0x00
};

const uint8_t code send_test_data_taobao[60]=
{
    0x03, 0x00, 0x36, 0xFE, 0x01, 0x00, 0x36, 0x27,
    0x12, 0x00, 0x03, 0x0A, 0x00, 0x12, 0x2A, 0x43,
    0x43, 0x30, 0x37, 0x39,                   
    0x36, 0x37, 0x34, 0x32, 0x34, 0x45, 0x46, 0x45,
    0x39, 0x33, 0x31, 0x33, 0x30, 0x33, 0x38, 0x32,
    0x30, 0x30, 0x30, 0x34,                   
    0x31, 0x33, 0x30, 0x33, 0x31, 0x33, 0x36, 0x34,
    0x31, 0x33, 0x30, 0x33, 0x30, 0x33, 0x31, 0x30,
    0x38, 0x00, 0x00, 0x00
};

const uint8_t code scale_data_init[10]=
{
    0x01, 0x30, 0x30, 0x30, 0x30, 0x42, 0x46, 0x38,
    0x33, 0x43,
};

static const char ascii[] = "0123456789ABCDEF";

const uint8_t code send_scale_data[60]=
{
    0x03, 0x00, 0x34, 0xFE, 0x01, 0x00, 0x34, 0x27,
    0x12, 0x00, 0x00, 0x0A, 0x00, 0x12, 0x26, 0x43,
    0x33, 0x46, 0x45, 0x30,                   
    0x30, 0x30, 0x36, 0x45, 0x30, 0x35, 0x35, 0x44,
    0x36, 0x42, 0x34, 0x43, 0x41, 0x46, 0x46, 0x30,
    0x30, 0x30, 0x30, 0x30,                   
    0x30, 0x46, 0x46, 0x30, 0x30, 0x30, 0x30, 0x30,
    0x30, 0x30, 0x30, 0x30, 0x39, 0x18, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};
#endif

#ifdef _PROFILE_WECHAT_
const uint8_t code auth_data_wechat[26]=
{
    0xFE, 0x01, 0x00, 0x1A, 0x27, 0x11, 0x00, 0x01,
    0x0A, 0x00, 0x18, 0x80, 0x80, 0x04, 0x20, 0x01,
    0x28, 0x02, 0x3A, 0x06, 0xD0, 0x39, 0x72, 0xA5,
    0xEF, 0x24
};

const uint8_t code init_data_wechat[19]=
{
    0xFE, 0x01, 0x00, 0x13, 0x27, 0x13, 0x00, 0x02,
    0x0A, 0x00, 0x1A, 0x04, 0x30, 0x37, 0x31, 0x35,
    0x12, 0x01, 0x41
};

const uint8_t code send_test_data_wechat[19]=
{
    0xFE, 0x01, 0x00, 0x13, 0x27, 0x12, 0x00, 0x02,
    0x0A, 0x00, 0x1A, 0x04, 0x30, 0x37, 0x31, 0x35,
    0x12, 0x01, 0x41
};

#ifdef _PROFILE_WECHAT_SIMPLE_MODE_
const uint8_t code current_step_data[4] =
{
    0x01, 0x10, 0x27, 0x00
};

const uint8_t code current_total_data[10]=
{
    0x07, 0x10, 0x27, 0x00, 0x70, 0x17, 0x00, 0x00,
    0x22, 0x33
};

const uint8_t code target_data[19]=
{
    0xFE, 0x01, 0x00, 0x13, 0x27, 0x12, 0x00, 0x02,
    0x0A, 0x00, 0x1A, 0x04, 0x30, 0x37, 0x31, 0x35,
    0x12, 0x01, 0x41
};
#endif
#endif
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
    uint8_t xdata   result, i;
    uint16_t xdata  waitpacket_tmp=0, waitpacket_tmp1=0, waitpacket_tmp2=0;
    
    uint8_t xdata   Uart_OTA_Flag;
    uint8_t xdata   Uart_OTA_Start;


		//while(~P0_4);

    InterruptDisable();
    InitMCU();
    
    internalRC = 0; //0 :Using External RC 32.768KHz ; 1:Using internal RC 32.000KHz

    InitCrystalCL(0x32);  //AMICCOM CrystalCL 0x32(MD8107-A05)(18pF)/ 0x14(MD8107-A06)(12pF)/ 0x0D(9pF)
    InitRF();
    IAP_Initialize();
    OTA_Initialize();

    InitBLE();
    BLE_SetTxPower(6); //level 0 ~ 7 : 0 => -17dBm; 1 => -15dBm; 2 => -10dBm; 3 => -5dBm; 4 => 0dBm; 5 => 2dBm; 6 => 4dBm; 7 => 7dBm
    InterruptEnable();

#ifdef _PROFILE_TAOBAO_
    for(i=0;i<10;i++)
        scalebuf[i]=scale_data_init[i];

    weightvalue=0;
    datevalue=559240;
    datevalue=788888;
#endif
  		RF_Timer500ms(ENABLE);

    OTA_RECONNECT_FLAG = DISABLE;
    Uart_OTA_Flag = 0;
    Uart_OTA_Start = 0;

    while(1)
    {
        if (Uart_OTA_Flag==0)
        {
            OTA_Process();
    
            /* User Can Add Code */
    
            if(ble_state == STANDBY_STATE)
            {
                ADV_InitStructure.ADV_Timing = 0; // ADV Interval = (20ms + 0.625ms*ADV_Timing) = 20ms
                ADV_InitStructure.ADV_TO = 1500;  // ADV Timeout = ADV Interval * ADV_TO = 20ms*1500 = 30 sec
                ADV_InitStructure.ADV_Channel = (TE_ADVCHANNEL)(ADV_CH37);// | ADV_CH38 | ADV_CH39);
                ADV_InitStructure.ADV_Type = ADV_IND;
                ADV_InitStructure.ADV_RndEnable = DISABLE;
                ADV_InitStructure.ADV_TOEnable = ENABLE;
                ADV_InitStructure.ADV_Run = ENABLE;
                BLE_ADV_Cmd(&ADV_InitStructure);
    
#ifdef _PROFILE_HOGP_
#ifdef _PROFILE_HOGP_MOUSE_
                HID_report_MS_key_temp = 0x00;
                mousedata = 0;
#endif
#ifdef _PROFILE_HOGP_KEYBOARD_
                presskey07 = 0;
#endif
#ifdef _PROFILE_HOGP_COMSUMER_
                presskey06 = 0;
#endif
#endif

#ifdef _PROFILE_WECHAT_
#ifdef _PROFILE_WECHAT_SIMPLE_MODE_
                for(i=0;i<10;i++)
                    att_HDL_WECHAT_SIMPLEMODE_DATRWI[i] = current_total_data[i];
                att_HDL_WECHAT_SIMPLEMODE_DATRWI[20] = 10;
#endif
#endif
                auth_req = FAIL;
                init_req = FAIL;
                auth_init_finish = FAIL;
                index = 0;
                scale_index = 0;
                KeyWakeup = 0;
                sendscaledata = FAIL;
                waitpacket=0;
            }
            else if(ble_state == ADV_STATE)
            {
                UpdateOTASpeed = ENABLE;
            }
            else if(ble_state == CONNECT_ESTABLISH_STATE)
            {
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
#ifdef _PROFILE_TAOBAO_
                    else if(ptrChar == &att_HDL_TAOBAO_DATW)
                    {
                        if(waitpacket==0)
                        {
                            if(att_HDL_TAOBAO_DATW[7]==0x4E)
                            {
                                waitpacket_tmp1=att_HDL_TAOBAO_DATW[1];
                                waitpacket_tmp2=att_HDL_TAOBAO_DATW[2];
                                waitpacket_tmp=((waitpacket_tmp1<<8)|(waitpacket_tmp2))+3;
                                
                                if((waitpacket_tmp%20)==0)
                                    waitpacket=((waitpacket_tmp)/20)-1;
                                else if((waitpacket_tmp%20)!=0)
                                    waitpacket=((waitpacket_tmp+3)/20);
                                else
                                    ;
                                
                                switch(att_HDL_TAOBAO_DATW[8])
                                {
                                    case 0x21:
                                        auth_req = PASS;
                                        break;
                                    
                                    case 0x22:
                                        auth_init_finish = PASS;
                                        break;
                                    
                                    case 0x23:
                                        init_req = PASS;
                                        break;
                                    
                                    default:
                                        break;
                                }
                            }
                            else
                            	   ;
                        }
                        else
                        {
                            waitpacket--;
                        }
                    }
#endif
#ifdef _PROFILE_WECHAT_
#ifndef _PROFILE_WECHAT_SIMPLE_MODE_
                    else if(ptrChar == &att_HDL_WECHAT_DATW)//WeChat
                    {
                        if(waitpacket==0)
                        {
                            if(att_HDL_WECHAT_DATW[4]==0x4E)
                            {
                                waitpacket_tmp1=att_HDL_WECHAT_DATW[2];
                                waitpacket_tmp2=att_HDL_WECHAT_DATW[3];
                                waitpacket_tmp=((waitpacket_tmp1<<8)|(waitpacket_tmp2));
                                
                                if((waitpacket_tmp%20)==0)
                                    waitpacket=((waitpacket_tmp)/20)-1;
                                else if((waitpacket_tmp%20)!=0)
                                    waitpacket=((waitpacket_tmp)/20);
                                else
                                    ;
                                
                                switch(att_HDL_WECHAT_DATW[5])
                                {
                                    case 0x21:
                                        auth_req = PASS;
                                        break;
                                
                                    case 0x22:
                                        auth_init_finish = PASS;
                                        break;
                                
                                    case 0x23:
                                        init_req = PASS;
                                        break;
                                
                                    default:
                                        break;
                                }
                            }
                            else if(att_HDL_WECHAT_DATW[4]==0x75)
                            {
                                waitpacket_tmp1=att_HDL_WECHAT_DATW[2];
                                waitpacket_tmp2=att_HDL_WECHAT_DATW[3];
                                waitpacket_tmp=((waitpacket_tmp1<<8)|(waitpacket_tmp2));
                                
                                if((waitpacket_tmp%20)==0)
                                    waitpacket=((waitpacket_tmp)/20)-1;
                                else if((waitpacket_tmp%20)!=0)
                                    waitpacket=((waitpacket_tmp)/20);
                                else
                                    ;
                                
                                switch(att_HDL_WECHAT_DATW[5])
                                {
                                    case 0x31:
                                        _nop_();
                                        break;
                                        
                                    case 0x32:
                                        _nop_();
                                        break;
                                        
                                    case 0x33:
                                        _nop_();
                                        break;
                                        
                                    default:
                                        break;
                                }
                            }
                            else
                                ;
                        }
                        else
                        {
                          		waitpacket--;
                        }
                    }
#else
                    else if(ptrChar == &att_HDL_WECHAT_SIMPLEMODE_DATRWI)//WeChat_Simple//手機寫步數
                    {
                        switch(att_HDL_WECHAT_SIMPLEMODE_DATRWI[0])
                        {
                            case 0x01:
                                result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRWI,ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,4);
                                break;
                            
                            case 0x02:
                                result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRWI,ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,4);
                                break;
                            
                            case 0x03:
                                result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRWI,ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,7);
                                break;
                            
                            case 0x04:
                                result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRWI,ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,4);
                                break;
                            
                            case 0x05:
                                result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRWI,ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,7);
                                break;
                            
                            case 0x06:
                                result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRWI,ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,7);
                                break;
                            
                            case 0x07:
                                result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRWI,ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,10);
                                break;
                            
                            default:
                                break;
                        }
                    }
#endif
#endif
#ifdef _PROFILE_USER_DEFINE_01_
                    else if(ptrChar == &att_HDL_USER_DEFINE_01_DATAW01)
                    {
                        if((att_HDL_USER_DEFINE_01_DATAN01_CLIENT_CHARACTERISTIC_CONFIGURATION[0] & GATT_DESCRIPTORS_CLIENT_CHARACTERISTIC_CONFIGURATION_NOTIFICATION) != 0)
                        {
                            for(i=0;i<20;i++)
                            		  att_HDL_USER_DEFINE_01_DATAN01[i] = att_HDL_USER_DEFINE_01_DATAW01[i];
                            
                            result = BLE_SendData(att_HDL_USER_DEFINE_01_DATAN01,ATT_HDL_USER_DEFINE_01_DATAN01_INIT,5);
                            
                            if(result == SUCCESS)
                            {
                                _nop_();
                            }
                            else
                            {
                                _nop_();
                            }
                        }                    
                    }
                    else if(ptrChar == &att_HDL_USER_DEFINE_01_DATAW02)
                    {
                        if((att_HDL_USER_DEFINE_01_DATAN02_CLIENT_CHARACTERISTIC_CONFIGURATION[0] & GATT_DESCRIPTORS_CLIENT_CHARACTERISTIC_CONFIGURATION_NOTIFICATION) != 0)
                        {
                            for(i=0;i<20;i++)
                                att_HDL_USER_DEFINE_01_DATAN02[i] = att_HDL_USER_DEFINE_01_DATAW02[i];
                            
                            result = BLE_SendData(att_HDL_USER_DEFINE_01_DATAN02,ATT_HDL_USER_DEFINE_01_DATAN02_INIT,5);
                            
                            if(result == SUCCESS)
                            {
                                _nop_();
                            }
                            else
                            {
                                _nop_();
                            }
                        }                    
                    }
#endif
                    else
                        ;
                }
#ifdef _PROFILE_HOGP_
#ifdef _PROFILE_HOGP_MOUSE_
                if(~P3_2)
                {
                    do{
                        MouseDemo();
                    }while(~P3_2);
                }
#endif
#ifdef _PROFILE_HOGP_KEYBOARD_
                if(~P0_7)
                {
                    if((att_HDL_HIDS_REPORT_KBI_CLIENT_CHARACTERISTIC_CONFIGURATION[0] & GATT_DESCRIPTORS_CLIENT_CHARACTERISTIC_CONFIGURATION_NOTIFICATION) != 0)
                    {
                        if((HID_report_KB_key_temp < 0x04)||(HID_report_KB_key_temp >= 0x27))  //a~9
                        {
                            HID_report_KB_key_temp = 0x04;
                        }
                        else
                        {
                            HID_report_KB_key_temp++;
                        }
                        att_HDL_HIDS_REPORT_KBI[HDL_HIDS_REPORT_TAB_KEY_DATA0] = HID_report_KB_key_temp;
                        result = BLE_SendData(att_HDL_HIDS_REPORT_KBI,ATT_HDL_HIDS_REPORT_KBI_INIT,ATT_HDL_HIDS_REPORT_KBI_INIT[4]);
                        if(result == SUCCESS)
                        {
                            presskey07 = 1;
                        }
                    }
                }
                else
                {
                    if(presskey07)
                    {
                        if((att_HDL_HIDS_REPORT_KBI_CLIENT_CHARACTERISTIC_CONFIGURATION[0] & GATT_DESCRIPTORS_CLIENT_CHARACTERISTIC_CONFIGURATION_NOTIFICATION) != 0)
                        {
                            att_HDL_HIDS_REPORT_KBI[HDL_HIDS_REPORT_TAB_KEY_DATA0] = 0x00;
                            result = BLE_SendData(att_HDL_HIDS_REPORT_KBI,ATT_HDL_HIDS_REPORT_KBI_INIT,ATT_HDL_HIDS_REPORT_KBI_INIT[4]);
                            if(result == SUCCESS)
                            {
                                presskey07 = 0;
                            }
                        }
                    }
                }
#endif
#ifdef _PROFILE_HOGP_COMSUMER_
                if(~P0_6)
                {
                    if((att_HDL_HIDS_REPORT_CSI_CLIENT_CHARACTERISTIC_CONFIGURATION[0] & GATT_DESCRIPTORS_CLIENT_CHARACTERISTIC_CONFIGURATION_NOTIFICATION) != 0)
                    {
                        att_HDL_HIDS_REPORT_CSI[HDL_HIDS_REPORT_TAB_CSKEY_L] = HID_RPT_CS_KEY_DEMO[0][0];
                        att_HDL_HIDS_REPORT_CSI[HDL_HIDS_REPORT_TAB_CSKEY_H] = HID_RPT_CS_KEY_DEMO[0][1];
                        result = BLE_SendData(att_HDL_HIDS_REPORT_CSI,ATT_HDL_HIDS_REPORT_CSI_INIT,ATT_HDL_HIDS_REPORT_CSI_INIT[4]);
                        if(result == SUCCESS)
                        {
                            presskey06 = 1;
                        }
                    }
                }
                else
                {
                    if(presskey06)
                    {
                        if((att_HDL_HIDS_REPORT_CSI_CLIENT_CHARACTERISTIC_CONFIGURATION[0] & GATT_DESCRIPTORS_CLIENT_CHARACTERISTIC_CONFIGURATION_NOTIFICATION) != 0)
                        {
                            att_HDL_HIDS_REPORT_CSI[HDL_HIDS_REPORT_TAB_CSKEY_L] = 0x00;
                            att_HDL_HIDS_REPORT_CSI[HDL_HIDS_REPORT_TAB_CSKEY_H] = 0x00;
                            result = BLE_SendData(att_HDL_HIDS_REPORT_CSI,ATT_HDL_HIDS_REPORT_CSI_INIT,ATT_HDL_HIDS_REPORT_CSI_INIT[4]);
                            if(result == SUCCESS)
                            {
                                presskey06 = 0;
                            }
                        }
                    }
                }
#endif
#endif

#ifdef _PROFILE_TAOBAO_
                if((att_HDL_TAOBAO_DATI_MEASUREMENT_CLIENT_CHARACTERISTIC_CONFIGURATION[0]&GATT_DESCRIPTORS_CLIENT_CHARACTERISTIC_CONFIGURATION_INDICATION) != 0)
                {
                    if(auth_req == FAIL && waitpacket == 0)
                    {
                        switch(index)
                        {
                            case 0x00:
                                for(i=0;i<20;i++)
                                    att_HDL_TAOBAO_DATI[i] = auth_data_taobao[i];
                                result = BLE_SendData(att_HDL_TAOBAO_DATI,ATT_HDL_TAOBAO_DATI_INIT,20);
                                if(result == SUCCESS)
                                    index++;
                                break;
                                
                            case 0x01:
                                for(i=0;i<20;i++)
                                    att_HDL_TAOBAO_DATI[i] = auth_data_taobao[i+20];
                                result = BLE_SendData(att_HDL_TAOBAO_DATI,ATT_HDL_TAOBAO_DATI_INIT,20);
                                if(result == SUCCESS)
                                    index++;
                                break;
                                
                            case 0x02:
                                for(i=0;i<20;i++)
                                		  att_HDL_TAOBAO_DATI[i] = auth_data_taobao[i+20+20];
                                result = BLE_SendData(att_HDL_TAOBAO_DATI,ATT_HDL_TAOBAO_DATI_INIT,20);
                                if(result == SUCCESS)
                                {
                                    index++;
                                    //auth_req = PASS;
                                }
                                break;
                                
                            default:
                                break;
                        }
                    }
                    else if(auth_req == PASS && init_req == FAIL && waitpacket == 0)
                    {
                        switch(index)
                        {
                            case 0x03:
                                for(i=0;i<20;i++)
                                    att_HDL_TAOBAO_DATI[i] = init_data_taobao[i];
                            
                                result = BLE_SendData(att_HDL_TAOBAO_DATI,ATT_HDL_TAOBAO_DATI_INIT,20);
                            
                                if(result == SUCCESS)
                                    index++;
                                break;
                            
                            default:
                                break;
                        }
                    }
                    else if(auth_init_finish == FAIL && waitpacket == 0)
                    {
                        switch(index)
                        {
                            case 0x04:
                                for(i=0;i<20;i++)
                                    att_HDL_TAOBAO_DATI[i] = send_test_data_taobao[i];
                                result = BLE_SendData(att_HDL_TAOBAO_DATI,ATT_HDL_TAOBAO_DATI_INIT,20);
                                if(result == SUCCESS)
                                    index++;
                                break;
                        
                        				case 0x05:
                                for(i=0;i<20;i++)
                                    att_HDL_TAOBAO_DATI[i] = send_test_data_taobao[i+20];
                                result = BLE_SendData(att_HDL_TAOBAO_DATI,ATT_HDL_TAOBAO_DATI_INIT,20);
                                if(result == SUCCESS)
                                    index++;
                                break;
                                
                            case 0x06:
                                for(i=0;i<20;i++)
                                    att_HDL_TAOBAO_DATI[i] = send_test_data_taobao[i+20+20];
                                result = BLE_SendData(att_HDL_TAOBAO_DATI,ATT_HDL_TAOBAO_DATI_INIT,20);
                                if(result == SUCCESS)
                                {
                                    //auth_init_finish = PASS;
                                	   index++;
                                }
                                break;
                                
                            default:
                                break;
                        }
                    }
                    else
                        ;
                }
#endif
#ifdef _PROFILE_WECHAT_
#ifndef _PROFILE_WECHAT_SIMPLE_MODE_
                if((att_HDL_WECHAT_DATI_MEASUREMENT_CLIENT_CHARACTERISTIC_CONFIGURATION[0]&GATT_DESCRIPTORS_CLIENT_CHARACTERISTIC_CONFIGURATION_INDICATION) != 0)
                {
                    if(auth_req == FAIL && waitpacket == 0)
                    {
                        switch(index)
                        {
                            case 0x00:
                                for(i=0;i<20;i++)
                                    att_HDL_WECHAT_DATI[i] = auth_data_wechat[i];
                                result = BLE_SendData(att_HDL_WECHAT_DATI,ATT_HDL_WECHAT_DATI_INIT,20);
                                if(result == SUCCESS)
                                    index++;
                            break;
                            
                            case 0x01:
                                for(i=0;i<6;i++)
                                    att_HDL_WECHAT_DATI[i] = auth_data_wechat[i+20];
                                result = BLE_SendData(att_HDL_WECHAT_DATI,ATT_HDL_WECHAT_DATI_INIT,6);
                                if(result == SUCCESS)
                                    index++;
                                break;
                            
                            default:
                                break;
                        }
                    }
                    else if(auth_req == PASS && init_req == FAIL && waitpacket == 0)
                    {
                        switch(index)
                        {
                            case 0x02:
                                for(i=0;i<19;i++)
                                    att_HDL_WECHAT_DATI[i] = init_data_wechat[i];
                            
                                result = BLE_SendData(att_HDL_WECHAT_DATI,ATT_HDL_WECHAT_DATI_INIT,19);
                                if(result == SUCCESS)
                                	   index++;
                            break;
                            
                            default:
                                break;
                        }
                    }
                    else if(auth_req == PASS && init_req == PASS && auth_init_finish == FAIL && waitpacket == 0)
                    {
                        switch(index)
                        {
                            case 0x03:
                                for(i=0;i<19;i++)
                                    att_HDL_WECHAT_DATI[i] = send_test_data_wechat[i];
                                result = BLE_SendData(att_HDL_WECHAT_DATI,ATT_HDL_WECHAT_DATI_INIT,19);
                                if(result == SUCCESS)
                                    index++;
                                break;
                                
                            default:
                                break;
                        }
                    }
                    else
                        ;
                }
#else
                if((att_HDL_WECHAT_SIMPLEMODE_DATRI_CLIENT_CHARACTERISTIC_CONFIGURATION[0]&GATT_DESCRIPTORS_CLIENT_CHARACTERISTIC_CONFIGURATION_INDICATION) != 0)
                {
                    switch(index)
                    {
                        case 0x00:
                            for(i=0;i<4;i++)
                                att_HDL_WECHAT_SIMPLEMODE_DATRI[i] = current_step_data[i];
                            result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRI,ATT_HDL_WECHAT_SIMPLEMODE_DATRI_INIT,4);
                            att_HDL_WECHAT_SIMPLEMODE_DATRI[20]=4;
                            if(result == SUCCESS)
                                index++;
                            break;
                        
                        case 0x01:
                            for(i=0;i<10;i++)
                                att_HDL_WECHAT_SIMPLEMODE_DATRI[i] = current_total_data[i];
                            result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRI,ATT_HDL_WECHAT_SIMPLEMODE_DATRI_INIT,10);
                            att_HDL_WECHAT_SIMPLEMODE_DATRI[20]=10;
                            if(result == SUCCESS)
                                index++;
                            break;
                        
                        default:
                            break;
                    }                
                }
                else if((att_HDL_WECHAT_SIMPLEMODE_DATRWI_CLIENT_CHARACTERISTIC_CONFIGURATION[0]&GATT_DESCRIPTORS_CLIENT_CHARACTERISTIC_CONFIGURATION_INDICATION) != 0)
                {
                    switch(att_HDL_WECHAT_SIMPLEMODE_DATRWI[0])
                    {
                        case 0x01:
                            result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRWI,ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,4);
                            if(result == SUCCESS)
                                _nop_();
                            break;
                        
                        case 0x02:
                            result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRWI,ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,4);
                            if(result == SUCCESS)
                                _nop_();
                        				break;
                        
                        case 0x03:
                            result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRWI,ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,7);
                            if(result == SUCCESS)
                                _nop_();
                            break;
                        
                        case 0x04:
                            result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRWI,ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,4);
                            if(result == SUCCESS)
                                _nop_();
                            break;
                        
                        case 0x05:
                            result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRWI,ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,7);
                            if(result == SUCCESS)
                                _nop_();
                            break;
                        
                        case 0x06:
                            result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRWI,ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,7);
                            if(result == SUCCESS)
                                _nop_();
                            break;
                        
                        case 0x07:
                            result = BLE_SendData(att_HDL_WECHAT_SIMPLEMODE_DATRWI,ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,10);
                            if(result == SUCCESS)
                                _nop_();
                            break;
                        
                        default:
                            break;
                    }
                }
#endif
#endif
                if(auth_init_finish == PASS && waitpacket == 0)
                {
#ifdef _PROFILE_TAOBAO_
                    Prcss_Weight();
#endif
                }
            }
    ////////////////TWOR///////////////////////////////////
            if(Timer500ms_flag)
            {
                Timer500ms_flag = 0;
            }

            BLE_AutoPwrDown_Enable();
            
            P1_6 ^=1;
            P1_7 ^=1;
            if ((P3_0==0) && (P3_1==0))
                Uart_OTA_Flag = 1;
        }
        else
        {
            if (Uart_OTA_Start==0)
            {
                EIE = EIE & 0xF7;//Disable RF_ISR interrupt
                while ((P3_0==0) && (P3_1==0))
                    _nop_();
                Uart_OTA_Start = 1;
                Uart_OTA_Init();
                /*if(ble_state == STANDBY_STATE)
                {
                    _nop_();
                }
                else if(ble_state == ADV_STATE)
                {
                    ADV_InitStructure.ADV_Run = DISABLE;
                    BLE_ADV_Cmd(&ADV_InitStructure);
                    _nop_();
                }
                else if(ble_state == CONNECT_ESTABLISH_STATE)
                {
                    _nop_();
                }*/
                P3OE  = P3OE & 0xFE;
                P3PUN = P3PUN & 0xFE;

                InitUART();
            }
            else
            {
                UartOTA_Process();
            }
        }
    }
}

#ifdef _PROFILE_HOGP_
#ifdef _PROFILE_HOGP_MOUSE_
void MouseDemo(void)
{
    uint8_t result;

    if(mousedata == 0)
    {
        if((att_HDL_HIDS_REPORT_MSI_CLIENT_CHARACTERISTIC_CONFIGURATION[0] & GATT_DESCRIPTORS_CLIENT_CHARACTERISTIC_CONFIGURATION_NOTIFICATION) != 0)
        {
            HID_report_MS_key_temp++;
            if(HID_report_MS_key_temp <= 0x3F)
            {
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_L_R_L] = 0xFF;
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_L_R_H] = 0xFF;
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_U_D_L] = 0xFF;
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_U_D_H] = 0xFF;
            }
            else if(HID_report_MS_key_temp <= 0x7F)
            {
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_L_R_L] = 0x01;
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_L_R_H] = 0x00;
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_U_D_L] = 0xFF;
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_U_D_H] = 0xFF;
            }
            else if(HID_report_MS_key_temp <= 0xBF)
            {
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_L_R_L] = 0x01;
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_L_R_H] = 0x00;
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_U_D_L] = 0x01;
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_U_D_H] = 0x00;
            }
            else if(HID_report_MS_key_temp <= 0xFF)
            {
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_L_R_L] = 0xFF;
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_L_R_H] = 0xFF;
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_U_D_L] = 0x01;
                att_HDL_HIDS_REPORT_MSI[HDL_HIDS_REPORT_TAB_DIR_U_D_H] = 0x00;
            }

            result = BLE_SendData(att_HDL_HIDS_REPORT_MSI,ATT_HDL_HIDS_REPORT_MSI_INIT,ATT_HDL_HIDS_REPORT_MSI_INIT[4]);
            if(result == SUCCESS)
            {
                mousedata = 0;
            }
            else
            {
                mousedata = 1;
            }
        }
    }
    else
    {
        result = BLE_SendData(att_HDL_HIDS_REPORT_MSI,ATT_HDL_HIDS_REPORT_MSI_INIT,ATT_HDL_HIDS_REPORT_MSI_INIT[4]);
        if(result == SUCCESS)
        {
            mousedata = 0;
        }
        else
        {
            mousedata = 1;
        }
    }
}
#endif
#endif

#ifdef _PROFILE_TAOBAO_
void Prcss_Weight(void)
{
    uint8_t i,result,tmp;
    
    switch(scale_index)
    {
        case 0x00:
            for(i=0;i<20;i++)
                att_HDL_TAOBAO_DATI[i] = send_scale_data[i];
            
            att_HDL_TAOBAO_DATI[10]=scalebuf[0];
            scalebuf[0]++;
            
            result = BLE_SendData(att_HDL_TAOBAO_DATI,ATT_HDL_TAOBAO_DATI_INIT,20);
            if(result == SUCCESS)
                scale_index++;											
            break;
            
        case 0x01:
            for(i=0;i<20;i++)
                att_HDL_TAOBAO_DATI[i] = send_scale_data[i+20];
            att_HDL_TAOBAO_DATI[1]=scalebuf[1];
            att_HDL_TAOBAO_DATI[2]=scalebuf[2];
            att_HDL_TAOBAO_DATI[3]=scalebuf[3];
            att_HDL_TAOBAO_DATI[4]=scalebuf[4];
            att_HDL_TAOBAO_DATI[8]=scalebuf[5];
            att_HDL_TAOBAO_DATI[9]=scalebuf[6];
            att_HDL_TAOBAO_DATI[10]=scalebuf[7];
            att_HDL_TAOBAO_DATI[11]=scalebuf[8];
            att_HDL_TAOBAO_DATI[12]=scalebuf[9];
            
            result = BLE_SendData(att_HDL_TAOBAO_DATI,ATT_HDL_TAOBAO_DATI_INIT,20);
            if(result == SUCCESS)
            {
                weightvalue = weightvalue+100;
                
                tmp=toascii(weightvalue,3);
                scalebuf[1]=tmp;
                tmp=toascii(weightvalue,2);
                scalebuf[2]=tmp;						
                tmp=toascii(weightvalue,1); 
                scalebuf[3]=tmp;						
                tmp=toascii(weightvalue,0);
                scalebuf[4]=tmp;
                
                datevalue = datevalue+100;
                tmp=toascii(datevalue,4);
                scalebuf[5]=tmp;
                tmp=toascii(datevalue,3);
                scalebuf[6]=tmp;						
                tmp=toascii(datevalue,2);
                scalebuf[7]=tmp;						
                tmp=toascii(datevalue,1);
                scalebuf[8]=tmp;						
                tmp=toascii(datevalue,0);
                scalebuf[9]=tmp;	
                					
                scale_index++;
            }
            break;
            
        case 0x02:
            for(i=0;i<20;i++)
                att_HDL_TAOBAO_DATI[i] = send_scale_data[i+20+20];
            result = BLE_SendData(att_HDL_TAOBAO_DATI,ATT_HDL_TAOBAO_DATI_INIT,20);
            if(result == SUCCESS)
            {
                scale_index++;
                KeyWakeup = 0;
            }
            break;
        
        default:
            break;
    }																	

}

/*********************************************************************
**  toascii
*********************************************************************/
uint8_t toascii(uint32_t in, uint8_t unit)
{
    uint8_t tmp;

    tmp = ascii[(in>>(unit*4))&0x0F];
    return tmp;
}
#endif
