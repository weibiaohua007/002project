/*****************************************************************************
**               AMICCOM Electronics Corporation Document                   **
**          Copyright (c) 2011-2014 AMICCOM Electronics Corporation         **
**                                                                          **
**      A3,1F,No.1, Li-Hsin 1th Road, Science_Based Industrid Park,         **
**                       Hsin_Chu City, 300, Taiwan, ROC.                   **
**                 Tel: 886-3-5785818   Fax: 886-3-5785819                  **
**         E-mail:info@amiccom.com.tw  http: //www.amiccom.com.tw           **
*****************************************************************************/
#define _SERVICEGEN_C_

#include "define.h"
#include "servicegen.h"

#ifdef _PROFILE_WECHAT_
const uint8_t code ADV_DATA_INITIAL[32] = 
{
    0x11,  //User Define ADV Data Length
    
    0x02, 0x01, 0x05, 0x03, 0x02, 0xE7, 0xFE, 0x09,
    0xFF, 0x0D, 0x00, 0xD0, 0x39, 0x72, 0xA5, 0xEF,
    0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t code SCAN_RESPONSE_DATA_INITIAL[32] = 
{
    0x0E,  //User Define Scan response Data Length
    
    0x0D, 0x09, 0x41, 0x4D, 0x49, 0x43, 0x43, 0x4F,
    0x4D, 0x2D, 0x42, 0x4C, 0x45, 0x31, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
#elif defined _PROFILE_TAOBAO_
const uint8_t code ADV_DATA_INITIAL[32] = 
{
    0x18,  //User Define ADV Data Length
    
    0x02, 0x01, 0x06, 0x07, 0x03, 0xE7, 0xFE, 0x18,
    0xD6, 0xB3, 0xFE, 0x0C, 0xFF, 0xA8, 0x01, 0x01,
    0x00, 0x01, 0xE9, 0xEF, 0x24, 0x74, 0x96, 0x07,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t code SCAN_RESPONSE_DATA_INITIAL[32] = 
{
    0x0A,  //User Define Scan response Data Length
    
    0x09, 0x09, 0x4C, 0x53, 0x5F, 0x53, 0x43, 0x41,
    0x31, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
#elif defined _PROFILE_HOGP_
const uint8_t code ADV_DATA_INITIAL[32] = 
{
    0x0B,  //User Define ADV Data Length
    
    0x02, 0x01, 0x05, 0x03, 0x02, 0x12, 0x18, 0x03,
    0x19, 0xC0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t code SCAN_RESPONSE_DATA_INITIAL[32] = 
{
    0x12,  //User Define Scan response Data Length
    
    0x11, 0x08, 0x41, 0x4D, 0x49, 0x43, 0x43, 0x4F,
    0x4D, 0x5F, 0x48, 0x49, 0x44, 0x5F, 0x44, 0x65,
    0x6D, 0x6F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
#else
const uint8_t code ADV_DATA_INITIAL[32] = 
{
    0x0B,  //User Define ADV Data Length
    
    0x02, 0x01, 0x05, 0x03, 0x02, 0x12, 0x18, 0x03,
    0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t code SCAN_RESPONSE_DATA_INITIAL[32] = 
{
    0x15,  //User Define Scan response Data Length
    
    0x14, 0x09, 0x41, 0x4D, 0x49, 0x43, 0x43, 0x4F,
    0x4D, 0x5F, 0x44, 0x65, 0x6D, 0x6F, 0x5F, 0x33,
    0x32, 0x34, 0x5F, 0x4F, 0x4B, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
#endif

/*********************************************************************
** Service Gengerator
*********************************************************************/
const uint8_t code ATT_HDL_INVALID[] =
{
    0x00, 0x00
};

const uint8_t code ATT_HDL_GAP_PRIMARY_SERVICE[] = 
{
    0x00, 0x01,
    0x28, 0x00,
    2,
    0x00, 0x18
};

const uint8_t code ATT_HDL_GAP_CHARACTERISTIC_DEVICE_NAME[] =
{
    0x00, 0x02,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x03, 0x00,
    0x00, 0x2A
};

const uint8_t code ATT_HDL_GAP_DEVICE_NAME_INIT[] =
{
    0x00, 0x03,
    0x2A, 0x00,
    0x13,
    0x41, 0x4D, 0x49, 0x43, 0x43, 0x4F,
    0x4D, 0x5F, 0x44, 0x65, 0x6D, 0x6F, 0x5F, 0x33,
    0x32, 0x34, 0x5F, 0x4F, 0x4B,
};

uint8_t xdata att_HDL_GAP_DEVICE_NAME[] =
{
    0x41, 0x4D, 0x49, 0x43, 0x43, 0x4F,
    0x4D, 0x5F, 0x44, 0x65, 0x6D, 0x6F, 0x5F, 0x33,
    0x32, 0x34, 0x5F, 0x4F, 0x4B,
};

const uint8_t code ATT_HDL_GAP_CHARACTERISTIC_APPEARANCE[] =
{
    0x00, 0x04,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x05, 0x00,
    0x01, 0x2A
};

const uint8_t code ATT_HDL_GAP_APPEARANCE[] =
{
    0x00, 0x05,
    0x2A, 0x01,
    0x02,
    0x00, 0x00,
};

const uint8_t code ATT_HDL_GAP_CHARACTERISTIC_RECONNECTION_ADDRESS[] =
{
    0x00, 0x06,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        //0x02 |
        //0x04 |
        0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x07, 0x00,
    0x03, 0x2A
};

const uint8_t code ATT_HDL_GAP_RECONNECTION_ADDRESS_INIT[] =
{
    0x00, 0x07,
    0x2A, 0x03,
    0x06,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

uint8_t xdata att_HDL_GAP_RECONNECTION_ADDRESS[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t code ATT_HDL_GAP_CHARACTERISTIC_PERIPHERAL_PRIVACY_FLAG[] =
{
    0x00, 0x08,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x09, 0x00,
    0x02, 0x2A
};

const uint8_t code ATT_HDL_GAP_PERIPHERAL_PRIVACY_FLAG[] =
{
    0x00, 0x09,
    0x2A, 0x02,
    0x01,
    0x00
};

const uint8_t code ATT_HDL_GAP_CHARACTERISTIC_PERIPHERAL_PREFERRED_CONNECTION_PARAMETERS[] =
{
    0x00, 0x0A, 
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x0B, 0x00,
    0x04, 0x2A
};

const uint8_t code ATT_HDL_GAP_PERIPHERAL_PREFERRED_CONNECTION_PARAMETERS[] =
{
    0x00, 0x0B,
    0x2A, 0x04,
    8,
    0x90, 0x01,
    0x70, 0x03,
    0x00, 0x00,
    0x98, 0x00,
};

const uint8_t code ATT_HDL_GATT_PRIMARY_SERVICE[] = 
{
    0x00, 0x0C,
    0x28, 0x00,
    2,
    0x01, 0x18
};

const uint8_t code ATT_HDL_GATT_CHARACTERISTIC_SERVICE_CHANGED[] =
{
    0x00, 0x0D,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x0E, 0x00,
    0x05, 0x2A
};

const uint8_t code ATT_HDL_GATT_SERVICE_CHANGED_INIT[] =
{
    0x00, 0x0E,
    0x2A, 0x05,
    0x04,
    0x01, 0x00,
    0xFF, 0xFF,
};

uint8_t xdata att_HDL_GATT_SERVICE_CHANGED[] =
{
    0x00, 0x00,
    0x00, 0x00,
};

const uint8_t code ATT_HDL_GATT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    0x00, 0x0F,
    0x29, 0x02,
    0x02,
    0x00,
    0x00
};

uint8_t xdata att_HDL_GATT_CLIENT_CHARACTERISTIC_CONFIGURATION[] =
{
    0x00, 0x00,
};

const uint8_t code ATT_HDL_DIS_PRIMARY_SERVICE[] =
{
    0x00, 0x10,
    0x28, 0x00,
    2,
    0x0A, 0x18
};

const uint8_t code ATT_HDL_DIS_CHARACTERISTIC_SERIAL_NUMBER_STRING[] =
{
    0x00, 0x11,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x12, 0x00,
    0x25, 0x2A
};

const uint8_t code ATT_HDL_DIS_SERIAL_NUMBER_STRING[] =
{
    0x00, 0x12,
    0x2A, 0x25,
    0x04,
    0x30, 0x30, 0x30, 0x31,
};

const uint8_t code ATT_HDL_DIS_SERIAL_NUMBER_STRING_PRESENTATION_FORMAT[] =
{
    0x00, 0x13,
    0x29, 0x04,
    0x07,
    0x19,
    0x00,
    0x00, 0x00,
    0x01,
    0x00, 0x00
};

const uint8_t code ATT_HDL_DIS_CHARACTERISTIC_MANUFACTURER_NAME_STRING[] =
{
    0x00, 0x14,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x15, 0x00,
    0x29, 0x2A
};

const uint8_t code ATT_HDL_DIS_MANUFACTURER_NAME_STRING[] =
{
    0x00, 0x15,
    0x2A, 0x29,
    13,
    0x41, 0x4D, 0x49, 0x43, 0x43, 0x4F, 0x4D, 0x20, 0x45, 0x6C, 0x65, 0x63, 0x2e,
};

const uint8_t code ATT_HDL_DIS_MANUFACTURER_NAME_STRING_PRESENTATION_FORMAT[] =
{
    0x00, 0x16,
    0x29, 0x04,
    0x07,
    0x19,
    0x00,
    0x00, 0x00,
    0x01,
    0x00, 0x00
};

const uint8_t code ATT_HDL_DIS_CHARACTERISTIC_SYSTEM_ID[] =
{
    0x00, 0x17,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x18, 0x00,
    0x23, 0x2A
};

const uint8_t code ATT_HDL_DIS_SYSTEM_ID[] =
{
    0x00, 0x18,
    0x2A, 0x23,
    0x08,
    0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA,
};

const uint8_t code ATT_HDL_DIS_CHARACTERISTIC_FIRMWARE_REVISION_STRING[] =
{
    0x00, 0x19,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x1A, 0x00,
    0x26 , 0x2A
};

const uint8_t code ATT_HDL_DIS_FIRMWARE_REVISION_STRING[] =
{
    0x00, 0x1A,
    0x2A, 0x26 ,
    0x04,
    0x56, 0x30, 0x2E, 0x38,
};

const uint8_t code ATT_HDL_DIS_FIRMWARE_REVISION_STRING_PRESENTATION_FORMAT[] =
{
    0x00, 0x1B,
    0x29, 0x04,
    0x07,
    0x19,
    0x00,
    0x00, 0x00,
    0x19,
    0x00, 0x00
};

const uint8_t code ATT_HDL_DIS_CHARACTERISTIC_MODEL_NUMBER_STRING[] =
{
    0x00, 0x1C,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x1D, 0x00,
    0x24, 0x2A
};

const uint8_t code ATT_HDL_DIS_MODEL_NUMBER_STRING[] =
{
    0x00, 0x1D,
    0x2A, 0x24,
    0x06,
    0x4D, 0x44, 0x38, 0x31, 0x30, 0x37,
};

const uint8_t code ATT_HDL_DIS_MODEL_NUMBER_STRING_PRESENTATION_FORMAT[] =
{
    0x00, 0x1E,
    0x29, 0x04,
    0x07,
    0x19,
    0x00,
    0x00, 0x00,
    0x01,
    0x00, 0x00
};

const uint8_t code ATT_HDL_DIS_CHARACTERISTIC_HARDWARE_REVISION_STRING[] =
{
    0x00, 0x1F, 
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x20, 0x00,
    0x27, 0x2A,
};

const uint8_t code ATT_HDL_DIS_HARDWARE_REVISION_STRING[] =
{
    0x00, 0x20,
    0x2A, 0x27,
    0x03,
    0x55, 0x30, 0x33,
};

const uint8_t code ATT_HDL_DIS_HARDWARE_REVISION_STRING_PRESENTATION_FORMAT[] =
{
    0x00, 0x21,
    0x29, 0x04,
    0x07,
    0x19,
    0x00,
    0x00, 0x00,
    0x01,
    0x00, 0x00 
};

const uint8_t code ATT_HDL_DIS_CHARACTERISTIC_SOFTWARE_REVISION_STRING[] =
{
    0x00, 0x22,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x23, 0x00,
    0x28, 0x2A
};

const uint8_t code ATT_HDL_DIS_SOFTWARE_REVISION_STRING[] =
{
    0x00, 0x23, 
    0x2A, 0x28,
    0x04,
    0x30, 0x30, 0x30, 0x30,
};

const uint8_t code ATT_HDL_DIS_SOFTWARE_REVISION_STRING_PRESENTATION_FORMAT[] =
{
    0x00, 0x24,
    0x29, 0x04,
    0x07,
    0x19,
    0x00,
    0x00, 0x00,
    0x01,
    0x00, 0x00,
};

const uint8_t code ATT_HDL_DIS_CHARACTERISTIC_PNP_ID[] =
{
    0x00, 0x25,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x26, 0x00,
    0x50, 0x2A
};

const uint8_t code ATT_HDL_DIS_PNP_ID[] =
{
    0x00, 0x26,
    0x2A, 0x50,
    0x07,
    0x01,
    0xC0, 0x00,
    0x00, 0x00,
    0x00, 0x00
};

const uint8_t code ATT_HDL_OTA_PRIMARY_SERVICE[] =
{
    0x00, 0x27,
    0x28, 0x00,
    0x02,
    0xBA, 0xFE
};

const uint8_t code ATT_HDL_OTA_CHARACTERISTIC_OTA_DATA[] =
{
    0x00, 0x28,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        //0x02 |
        0x04 |
        //0x08 |
        0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x29, 0x00,
    0x10, 0xFA
};

const uint8_t code ATT_HDL_OTA_OTA_DATA_INIT[] =
{
    0x00, 0x29,
    0xFA, 0x10,
    20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

uint8_t xdata att_HDL_OTA_OTA_DATA[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

const uint8_t code ATT_HDL_OTA_OTA_DATA_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    0x00, 0x2A,
    0x29, 0x02,
    0x02,
    0x00,
    0x00
};

uint8_t xdata att_HDL_OTA_OTA_DATA_CLIENT_CHARACTERISTIC_CONFIGURATION[] =
{
    0x00, 0x00,
};

const uint8_t code ATT_HDL_OTA_OTA_DATA_DESCRIPTION[] =
{
    0x00, 0x2B,
    0x29, 0x01,
    0x08,
    0x4F, 0x54, 0x41, 0x5F, 0x44, 0x41, 0x54, 0x41
};

const uint8_t code ATT_HDL_OTA_CHARACTERISTIC_OTA_CMD_CONTROL_POINT[] =
{
    0x00, 0x2C,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        //0x02 |
        //0x04 |
        0x08 |
        //0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x2D, 0x00,
    0x11, 0xFA
};

const uint8_t code ATT_HDL_OTA_OTA_CMD_CONTROL_POINT_INIT[] =
{
    0x00, 0x2D,
    0xFA, 0x11,
    0x08,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

uint8_t xdata att_HDL_OTA_OTA_CMD_CONTROL_POINT[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t code ATT_HDL_OTA_OTA_CMD_CONTROL_POINT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    0x00, 0x2E,
    0x29, 0x02,
    0x02,
    0x00,
    0x00
};

uint8_t xdata att_HDL_OTA_OTA_CMD_CONTROL_POINT_CLIENT_CHARACTERISTIC_CONFIGURATION[] =
{
    0x00, 0x00
};

const uint8_t code ATT_HDL_OTA_OTA_CMD_USER_DESCRIPTION[] =
{
    0x00, 0x2F,
    0x29, 0x01,
    0x07,
    0x4F, 0x54, 0x41, 0x5F, 0x43, 0x4D, 0x44
};

const uint8_t code ATT_HDL_BAS_PRIMARY_SERVICE[] =
{
    0x00, 0x30,                                                                             
    0x28, 0x00,                                           
    0x02,
    0x0F, 0x18                                          
};

const uint8_t code ATT_HDL_BAS_CHARACTERISTIC_BATTERY_LEVEL[] =
{
    0x00, 0x31,                                                                             
    0x28, 0x03,                                            
    0x05,
    {                                                                                               
        //0x01 |                                                  
        0x02 |                                                         
        //0x04 |
        //0x08 |
        0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    0x32, 0x00,
    0x19, 0x2A                                
};

const uint8_t code ATT_HDL_BAS_BATTERY_LEVEL_INIT[] =
{
    0x00, 0x32,                                                                             
    0x2A, 0x19,                               
    0x01,
    100,                                                                                    
};

uint8_t xdata att_HDL_BAS_BATTERY_LEVEL[] =
{
    100,                                                                                    
};

const uint8_t code ATT_HDL_BAS_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =                 
{
    0x00, 0x33,                                                                             
    0x29, 0x02,
    0x02,
    0x00,                                                                                   
    0x00                                                                                    
};

uint8_t xdata att_HDL_BAS_CLIENT_CHARACTERISTIC_CONFIGURATION[] =
{
    0x00, 0x00                                                                                    
};

#ifdef _PROFILE_HOGP_
const uint8_t code ATT_HDL_HIDS_PRIMARY_SERVICE[] =
{
    0x00, (_HOGP_HDL_OFFSET_BASE_+0x00),                                                                                   
    0x28, 0x00,
    0x02,
    0x12, 0x18,
};

const uint8_t code ATT_HDL_HIDS_CHARACTERISTIC_HID_INFORMATION[] =
{
    0x00, (_HOGP_HDL_OFFSET_BASE_+0x01),
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_HOGP_HDL_OFFSET_BASE_+0x02), 0x00,
    0x4A, 0x2A
};

const uint8_t code ATT_HDL_HIDS_HID_INFORMATION[] =
{
    0x00, (_HOGP_HDL_OFFSET_BASE_+0x02),
    0x2A, 0x4A,
    0x04,
    0x13, 0x02,
    0x40,
    0x01,
};

const uint8_t code ATT_HDL_HIDS_CHARACTERISTIC_HID_CONTROL_POINT[] =
{
    0x00, (_HOGP_HDL_OFFSET_BASE_+0x03),
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        //0x02 |
        0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_HOGP_HDL_OFFSET_BASE_+0x04), 0x00,
    0x4C, 0x2A
};

const uint8_t code ATT_HDL_HIDS_HID_CONTROL_POINT_INIT[] =
{
    0x00, (_HOGP_HDL_OFFSET_BASE_+0x04),
    0x2A, 0x4C,
    0x01,
    0x01,
};

uint8_t xdata att_HDL_HIDS_HID_CONTROL_POINT[] =
{
    0x01,
};

const uint8_t code ATT_HDL_HIDS_CHARACTERISTIC_REPORT_MAP[] =
{
    0x00, (_HOGP_HDL_OFFSET_BASE_+0x05),      
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_HOGP_HDL_OFFSET_BASE_+0x06), 0x00,
    0x4B, 0x2A
};

const uint8_t code ATT_HDL_HIDS_REPORT_MAP[] = 
{
    0x00, (_HOGP_HDL_OFFSET_BASE_+0x06),
    0x2A, 0x4B,
    (SIZE_OF_ATTRIBUTE_VALUE_MS+SIZE_OF_ATTRIBUTE_VALUE_KB+SIZE_OF_ATTRIBUTE_VALUE_CS),
#ifdef _PROFILE_HOGP_COMSUMER_                                             
    0x05, 0x0C, 0x09, 0x01, 0xA1, 0x01,
#ifdef _PROFILE_HOGP_MULTI_
    0x85, 0x03,                            
#endif
    0x19, 0x00, 0x2A, 0x9C, 0x02, 0x15, 0x00, 0x26,
    0x9C, 0x02, 0x75, 0x10, 0x95, 0x01, 0x81, 0x00,
    0xC0,                                                          
#endif                                                                     
#ifdef _PROFILE_HOGP_KEYBOARD_
    0x05, 0x01, 0x09, 0x06, 0xa1, 0x01,
#ifdef _PROFILE_HOGP_MULTI_
    0x85, (0x00+__PROFILE_HOGP_KEYBOARD_RPIDOFST_),
#endif
    0x05, 0x08,	0x19, 0x01, 0x29, 0x03, 0x75, 0x01,
    0x95, 0x03, 0x15, 0x00, 0x25, 0x01, 0x91, 0x02,
    0x95, 0x05, 0x91, 0x01, 0x05, 0x07, 0x19, 0xe0,
    0x29, 0xe7, 0x95, 0x08, 0x81, 0x02, 0x75, 0x08,
    0x95, 0x01, 0x81, 0x01, 0x19, 0x00, 0x29, 0x91,
    0x26, 0xff, 0x00, 0x95, 0x06, 0x81, 0x00,
    0xC0,
#endif
#ifdef _PROFILE_HOGP_MOUSE_                                                
    0x05, 0x01, 0x09, 0x02, 0xA1, 0x01, 0x09, 0x01,                            
    0xA1, 0x00, 0x05, 0x09,
#ifdef _PROFILE_HOGP_MULTI_
    0x85, 0x02,
#endif
    0x19, 0x01, 0x29, 0x05, 0x15, 0x00, 0x25, 0x01,
    0x95, 0x05, 0x75, 0x01, 0x81, 0x02, 0x95, 0x01,
    0x75, 0x03, 0x81, 0x03, 0x05, 0x01, 0x09, 0x30,
    0x09, 0x31, 0x16, 0x00, 0xF8, 0x26, 0xFF, 0x07,
    0x75, 0x10, 0x95, 0x02, 0x81, 0x06, 0x09, 0x38,
    0x15, 0x80, 0x25, 0x7F, 0x75, 0x08, 0x95, 0x01,
    0x81, 0x06, 0x09, 0x01, 0x15, 0x00, 0x25, 0x03,
    0x95, 0x01, 0x75, 0x02, 0xB1, 0x02, 0x95, 0x01,
    0x75, 0x06, 0xB1, 0x03, 0xC0, 0xC0,
#endif      //#ifdef _PROFILE_HOGP_MOUSE_
};

#ifdef _PROFILE_HOGP_KEYBOARD_
const uint8_t code ATT_HDL_HIDS_CHARACTERISTIC_REPORT_KBI[] =
{
    0x00, _HOGP_HDL_OFFSET_KB_,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        0x08 |
        0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_HOGP_HDL_OFFSET_KB_+0x01), 0x00,
    0x4D, 0x2A
};

const uint8_t code ATT_HDL_HIDS_REPORT_KBI_INIT[] =
{
    0x00, (_HOGP_HDL_OFFSET_KB_+0x01),
    0x2A, 0x4D,
    0x08,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

uint8_t xdata att_HDL_HIDS_REPORT_KBI[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t code ATT_HDL_HIDS_REPORT_KBI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] = 
{
    0x00, (_HOGP_HDL_OFFSET_KB_+0x02),
    0x29, 0x02,
    0x02,
    0x00,
    0x00,
};

uint8_t xdata att_HDL_HIDS_REPORT_KBI_CLIENT_CHARACTERISTIC_CONFIGURATION[] =                                
{
    0x00, 0x00,
};

const uint8_t code ATT_HDL_HIDS_REPORT_KBI_REPORT_REFERENCE[] =
{
    0x00, (_HOGP_HDL_OFFSET_KB_+0x03),
    0x29, 0x08,
    0x02,
    (0x00+__PROFILE_HOGP_KEYBOARD_RPIDOFST_),
    0x01
};

const uint8_t code ATT_HDL_HIDS_CHARACTERISTIC_REPORT_KBO[] =
{
    0x00, (_HOGP_HDL_OFFSET_KB_+0x04),
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        0x04 |
        0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_HOGP_HDL_OFFSET_KB_+0x05), 0x00,
    0x4D, 0x2A
};

const uint8_t code ATT_HDL_HIDS_REPORT_KBO_INIT[] =
{
    0x00, (_HOGP_HDL_OFFSET_KB_+0x05),
    0x2A, 0x4D,
    0x01,
    0x03
};

uint8_t xdata att_HDL_HIDS_REPORT_KBO[] =
{
    0x03,
};

const uint8_t code ATT_HDL_HIDS_REPORT_KBO_REPORT_REFERENCE[] =
{
    0x00, (_HOGP_HDL_OFFSET_KB_+0x06),
    0x29, 0x08,
    0x02,
    (0x00+__PROFILE_HOGP_KEYBOARD_RPIDOFST_),
    0x02,
};
#endif

#ifdef _PROFILE_HOGP_MOUSE_
const uint8_t code ATT_HDL_HIDS_CHARACTERISTIC_REPORT_MSI[] =
{
    0x00, _HOGP_HDL_OFFSET_MOUSE_,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        0x08 |
        0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_HOGP_HDL_OFFSET_MOUSE_+0x01), 0x00,
    0x4D, 0x2A
};

const uint8_t code ATT_HDL_HIDS_REPORT_MSI_INIT[] =
{
    0x00, (_HOGP_HDL_OFFSET_MOUSE_+0x01),
    0x2A, 0x4D,
    0x06,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

uint8_t xdata att_HDL_HIDS_REPORT_MSI[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t code ATT_HDL_HIDS_REPORT_MSI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] = 
{
    0x00, (_HOGP_HDL_OFFSET_MOUSE_+0x02),
    0x29, 0x02,
    0x02,
    0x00,
    0x00
};

uint8_t xdata att_HDL_HIDS_REPORT_MSI_CLIENT_CHARACTERISTIC_CONFIGURATION[] =                                
{
    0x00, 0x00,
};


const uint8_t code ATT_HDL_HIDS_REPORT_MSI_REPORT_REFERENCE[] =
{
    0x00, (_HOGP_HDL_OFFSET_MOUSE_+0x03),
    0x29, 0x08,
    0x02,
    (0x00+__PROFILE_HOGP_MS_RPIDOFST_),
    0x01
};

const uint8_t code ATT_HDL_HIDS_CHARACTERISTIC_REPORT_MSF[] =
{
    0x00, (_HOGP_HDL_OFFSET_MOUSE_+0x04),
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 | 
        //0x04 |
        0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_HOGP_HDL_OFFSET_MOUSE_+0x05), 0x00,
    0x4D, 0x2A
};

const uint8_t code ATT_HDL_HIDS_REPORT_MSF_INIT[] =
{
    0x00, (_HOGP_HDL_OFFSET_MOUSE_+0x05),
    0x2A, 0x4D,
    0x01,
    0x03
};

uint8_t xdata att_HDL_HIDS_REPORT_MSF[] =
{
    0x03,
};

const uint8_t code ATT_HDL_HIDS_REPORT_MSF_REPORT_REFERENCE[] =
{
    0x00, (_HOGP_HDL_OFFSET_MOUSE_+0x06),
    0x29, 0x08,
    0x02,
    (0x00+__PROFILE_HOGP_MS_RPIDOFST_),
    0x03
};

const uint8_t code ATT_HDL_HIDS_REPORT_MSF_USER_DESCRIPTION[] =
{
    0x00, (_HOGP_HDL_OFFSET_MOUSE_+0x07),
    0x29, 0x01,
    (0x00+65),
    0x42, 0x4C, 0x45, 0x20, 0x4D, 0x4F, 0x55, 0x53,
    0x45, 0x20, 0x52, 0x45, 0x53, 0x4F, 0x4C, 0x55,
    0x54, 0x49, 0x4F, 0x4E, 0x20, 0x49, 0x4E, 0x20,
    0x43, 0x50, 0x49, 0x0A, 0x20, 0x30, 0x20, 0x3D,
    0x20, 0x34, 0x30, 0x30, 0x0A, 0x20, 0x31, 0x20,
    0x3D, 0x20, 0x38, 0x30, 0x30, 0x0A, 0x20, 0x32,
    0x20, 0x3D, 0x20, 0x31, 0x32, 0x30, 0x30, 0x0A,
    0x20, 0x33, 0x20, 0x3D, 0x20, 0x31, 0x36, 0x30,
    0x30,
};
#endif

#ifdef _PROFILE_HOGP_COMSUMER_
const uint8_t code ATT_HDL_HIDS_CHARACTERISTIC_REPORT_CSI[] =
{
    0x00, _HOGP_HDL_OFFSET_CONSUMER_,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        //0x04 |
        0x08 |
        0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_HOGP_HDL_OFFSET_CONSUMER_+0x01), 0x00,
    0x4D, 0x2A
};

const uint8_t code ATT_HDL_HIDS_REPORT_CSI_INIT[] =
{
    0x00, (_HOGP_HDL_OFFSET_CONSUMER_+0x01),
    0x2A, 0x4D,
    0x02,
    0x00, 0x00,
};

uint8_t xdata att_HDL_HIDS_REPORT_CSI[] =
{
    0x00, 0x00,
};

const uint8_t code ATT_HDL_HIDS_REPORT_CSI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] = 
{
    0x00, (_HOGP_HDL_OFFSET_CONSUMER_+0x02),
    0x29, 0x02,
    0x02,
    0x00,
    0x00,
};

uint8_t xdata att_HDL_HIDS_REPORT_CSI_CLIENT_CHARACTERISTIC_CONFIGURATION[] =                                
{
    0x00, 0x00
};

const uint8_t code ATT_HDL_HIDS_REPORT_CSI_REPORT_REFERENCE[] =
{
    0x00, (_HOGP_HDL_OFFSET_CONSUMER_+0x03),
    0x29, 0x08,
    0x02,
    (0x00+__PROFILE_HOGP_CS_RPIDOFST_),
    0x01
};
#endif

const uint8_t code ATT_HDL_HIDS_CHARACTERISTIC_PROTOCOL_MODE[] =
{
    0x00, _HOGP_HDL_OFFSET_RPT_REF_,
    0x28, 0x03,
    0x05,
    {
        //0x01 |
        0x02 |
        0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_HOGP_HDL_OFFSET_RPT_REF_+0x01), 0x00,
    0x4E, 0x2A
};

const uint8_t code ATT_HDL_HIDS_PROTOCOL_MODE_INIT[] =
{
    0x00, (_HOGP_HDL_OFFSET_RPT_REF_+0x01),
    0x2A, 0x4E,
    0x01,
    1,
};

uint8_t xdata att_HDL_HIDS_PROTOCOL_MODE[] =
{
    1,
};
#endif    //ifdef _PROFILE_HOGP_

#ifdef _PROFILE_TAOBAO_
const uint8_t code ATT_HDL_TAOBAO_PRIMARY_SERVICE[] =
{
    0x00, _TAOBAO_HDL_OFFSET_BASE_,                                                                                      
    0x28, 0x00,                                           
    0x02,
    0xB3, 0xFE,                                          
};

const uint8_t code ATT_HDL_TAOBAO_CHARACTERISTIC_DATW[] =
{
    0x00, (_TAOBAO_HDL_OFFSET_BASE_+0x01),                                                              
    0x28, 0x03,                                                
    0x05,
    //0x11,
    {                                                                                                   
        //0x01 |                                                      
        //0x02 |                                                           
        //0x04 |
        0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_TAOBAO_HDL_OFFSET_BASE_+0x02), 0x00,
    0xD5, 0xFE                                
};

const uint8_t code ATT_HDL_TAOBAO_DATW_INIT[] =
{
    0x00, (_TAOBAO_HDL_OFFSET_BASE_+0x02),                                                              
    0xFE, 0xD5,                               
    0x14,
    0x20, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13
};

uint8_t xdata att_HDL_TAOBAO_DATW[] =
{
    0x20, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13
};

const uint8_t code ATT_HDL_TAOBAO_CHARACTERISTIC_DATI[] =
{
    0x00, (_TAOBAO_HDL_OFFSET_BASE_+0x03),
    0x28, 0x03,
    0x05,
    {                                                             
        //0x01 |                                               
        //0x02 |                                               
        //0x04 |
        //0x08 |
        //0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_TAOBAO_HDL_OFFSET_BASE_+0x04), 0x00,
    0xD6, 0xFE                                
};

const uint8_t code ATT_HDL_TAOBAO_DATI_INIT[] =
{
    0x00, (_TAOBAO_HDL_OFFSET_BASE_+0x04),                                                             
    0xFE, 0xD6,                               
    0x14,
    0x10, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13
};

uint8_t xdata att_HDL_TAOBAO_DATI[] =
{
    0x10, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13
};

const uint8_t code ATT_HDL_TAOBAO_DATI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =                           
{
    0x00, (_TAOBAO_HDL_OFFSET_BASE_+0x05),                                                                       
    0x29, 0x02,                         
    0x02,
    0x00,                                                                                           
    0x00                                                                                            
};

uint8_t xdata att_HDL_TAOBAO_DATI_MEASUREMENT_CLIENT_CHARACTERISTIC_CONFIGURATION[] =                                
{
    0x00, 0x00,                                                                                         
};
#endif    //ifdef _PROFILE_TAOBAO_

#ifdef _PROFILE_WECHAT_
const uint8_t code ATT_HDL_WECHAT_PRIMARY_SERVICE[] =
{
    0x00, _WECHAT_HDL_OFFSET_BASE_,                                                                                     
    0x28, 0x00,                                           
    0x02,
    0xE7, 0xFE,                                          
};

const uint8_t code ATT_HDL_WECHAT_CHARACTERISTIC_DATW[] =
{
    0x00, (_WECHAT_HDL_OFFSET_BASE_+0x01),                                                              
    0x28, 0x03,                                                
    0x05,
    {                                                                                                   
        //0x01 |                                                      
        //0x02 |                                                           
        //0x04 |
        0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_WECHAT_HDL_OFFSET_BASE_+0x02), 0x00,
    0xC7, 0xFE                                
};

const uint8_t code ATT_HDL_WECHAT_DATW_INIT[] =
{
    0x00, (_WECHAT_HDL_OFFSET_BASE_+0x02),                                                             
    0xFE, 0xC7,                               
    0x14,
    0x20, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13
};

uint8_t xdata att_HDL_WECHAT_DATW[] =
{
    0x20, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13
};

const uint8_t code ATT_HDL_WECHAT_CHARACTERISTIC_DATI[] =
{
    0x00, (_WECHAT_HDL_OFFSET_BASE_+0x03),                                                             
    0x28, 0x03,                                                
    0x05,
    {                                                          
        //0x01 |                                               
        //0x02 |                                               
        //0x04 |
        //0x08 |
        //0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_WECHAT_HDL_OFFSET_BASE_+0x04), 0x00,
    0xC8, 0xFE                               
};

const uint8_t code ATT_HDL_WECHAT_DATI_INIT[] =
{
    0x00, (_WECHAT_HDL_OFFSET_BASE_+0x04),                                                             
    0xFE, 0xC8,                               
    0x14,
    0x10, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13
};

uint8_t xdata att_HDL_WECHAT_DATI[] =
{
    0x10, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13
};

const uint8_t code ATT_HDL_WECHAT_DATI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =                           
{
    0x00, (_WECHAT_HDL_OFFSET_BASE_+0x05),                                                                                      
    0x29, 0x02,                         
    0x02,
    0x00,                                                                                           
    0x00                                                                                            
};

uint8_t xdata att_HDL_WECHAT_DATI_MEASUREMENT_CLIENT_CHARACTERISTIC_CONFIGURATION[] =                                
{
    0x00, 0x00,                                                                                     
};

const uint8_t code ATT_HDL_WECHAT_CHARACTERISTIC_DATR[] =
{
    0x00, (_WECHAT_HDL_OFFSET_BASE_+0x06),
    0x28, 0x03,                                            
    0x05,
    {                                                                                               
        //0x01 |                                                  
        0x02 |                                                    
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_WECHAT_HDL_OFFSET_BASE_+0x07), 0x00,
    0xC9, 0xFE                                
};

const uint8_t code ATT_HDL_WECHAT_DATR[] =
{
    0x00, (_WECHAT_HDL_OFFSET_BASE_+0x07),
    0xFE, 0xC9,                              
    0x14,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13
};

#ifdef _PROFILE_WECHAT_SIMPLE_MODE_
const uint8_t code ATT_HDL_WECHAT_SIMPLEMODE_CHARACTERISTIC_DATRI[] =
{
    0x00, _WECHAT_SIMPLE_MODE_HDL_OFFSET_BASE_,
    0x28, 0x03,                                                
    0x05,
    {                                                          
        //0x01 |                                               
        0x02 |                                               
        //0x04 |
        //0x08 |
        //0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_WECHAT_SIMPLE_MODE_HDL_OFFSET_BASE_+0x01), 0x00,
    0xA1, 0xFE                               
};

const uint8_t code ATT_HDL_WECHAT_SIMPLEMODE_DATRI_INIT[] =
{
    0x00, (_WECHAT_SIMPLE_MODE_HDL_OFFSET_BASE_+0x01),
    0xFE, 0xA1,                               
    0x14,
    0x10, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13
};

uint8_t xdata att_HDL_WECHAT_SIMPLEMODE_DATRI[] =
{
    0x10, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0xFF
};

const uint8_t code ATT_HDL_WECHAT_SIMPLEMODE_DATRI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =                           
{
    0x00, (_WECHAT_SIMPLE_MODE_HDL_OFFSET_BASE_+0x02),
    0x29, 0x02,                         
    0x02,
    0x00,                                                                                           
    0x00                                                                                            
};

uint8_t xdata att_HDL_WECHAT_SIMPLEMODE_DATRI_CLIENT_CHARACTERISTIC_CONFIGURATION[] =                                
{
    0x00,                                                                                            
    0x00,                                                                                            
};

const uint8_t code ATT_HDL_WECHAT_SIMPLEMODE_CHARACTERISTIC_DATRWI[] =
{
    0x00, (_WECHAT_SIMPLE_MODE_HDL_OFFSET_BASE_+0x03),                                                            
    0x28, 0x03,                                                
    0x05,
    {                                                          
        //0x01 |                                               
        0x02 |                                               
        //0x04 |
        0x08 |
        //0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_WECHAT_SIMPLE_MODE_HDL_OFFSET_BASE_+0x04), 0x00,
    0xA2, 0xFE                               
};

const uint8_t code ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT[] =
{
    0x00, (_WECHAT_SIMPLE_MODE_HDL_OFFSET_BASE_+0x04),                                                        
    0xFE, 0xA2,                               
    0x14,
    0x10, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13
};

uint8_t xdata att_HDL_WECHAT_SIMPLEMODE_DATRWI[] =
{
    0x10, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0xFF
};

const uint8_t code ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =                           
{
    0x00, (_WECHAT_SIMPLE_MODE_HDL_OFFSET_BASE_+0x05),
    0x29, 0x02,                         
    0x02,
    0x00,                                                                                           
    0x00                                                                                            
};

uint8_t xdata att_HDL_WECHAT_SIMPLEMODE_DATRWI_CLIENT_CHARACTERISTIC_CONFIGURATION[] =                                
{
    0x00,                                                                                             
    0x00,                                                                                           
};
#endif    //ifdef _PROFILE_WECHAT_SIMPLE_MODE_
#endif    //ifdef _PROFILE_WECHAT_

#ifdef _PROFILE_USER_DEFINE_01_
const uint8_t code ATT_HDL_USER_DEFINE_01_PRIMARY_SERVICE[] =
{
    0x00, _UDF01S_HDL_OFFSET_BASE_,
    0x28, 0x00,                                           
    0x02,
    GATT_SPEC_CSTM_SERVICES_UDF01S, GATT_SPEC_CSTM_SERVICES
};

const uint8_t code ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAN01[] =
{
    0x00, (_UDF01S_HDL_OFFSET_BASE_+0x01),
    0x28, 0x03,                                            
    0x05,
    {                                                                                               
        //0x01 |                                                  
        //0x02 |                      
        //0x04 |
        //0x08 |
        0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_UDF01S_HDL_OFFSET_BASE_+0x02), 0x00,
    GATT_SPEC_CSTM_CHARACTERISTIC_UDATAN01, GATT_SPEC_CSTM_CHARACTERISTIC
};

const uint8_t code ATT_HDL_USER_DEFINE_01_DATAN01_INIT[] =
{
    0x00, (_UDF01S_HDL_OFFSET_BASE_+0x02),
    GATT_SPEC_CSTM_CHARACTERISTIC, GATT_SPEC_CSTM_CHARACTERISTIC_UDATAN01,
    0x14,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

uint8_t xdata att_HDL_USER_DEFINE_01_DATAN01[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

const uint8_t code ATT_HDL_USER_DEFINE_01_DATAN01_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] = 
{
    0x00, (_UDF01S_HDL_OFFSET_BASE_+0x03),                                                      
    0x29, 0x02,                     
    0x02,
    0x00,                                                                                       
    0x00                                                                                        
};

uint8_t xdata att_HDL_USER_DEFINE_01_DATAN01_CLIENT_CHARACTERISTIC_CONFIGURATION[] =                                
{
    0x00, 0x00,
};

const uint8_t code ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAW01[] =
{
    0x00, (_UDF01S_HDL_OFFSET_BASE_+0x04),
    0x28, 0x03,                                            
    0x05,
    {                                                                                               
        //0x01 |                                                  
        //0x02 |                      
        //0x04 |
        0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_UDF01S_HDL_OFFSET_BASE_+0x05), 0x00,
    GATT_SPEC_CSTM_CHARACTERISTIC_UDATAW01, GATT_SPEC_CSTM_CHARACTERISTIC
};

const uint8_t code ATT_HDL_USER_DEFINE_01_DATAW01_INIT[] =
{
    0x00, (_UDF01S_HDL_OFFSET_BASE_+0x05),
    GATT_SPEC_CSTM_CHARACTERISTIC, GATT_SPEC_CSTM_CHARACTERISTIC_UDATAW01,
    0x14,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

uint8_t xdata att_HDL_USER_DEFINE_01_DATAW01[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

const uint8_t code ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAN02[] =
{
    0x00, (_UDF01S_HDL_OFFSET_BASE_+0x06),
    0x28, 0x03,                                            
    0x05,
    {                                                                                               
        //0x01 |                                                  
        //0x02 |                      
        //0x04 |
        //0x08 |
        0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_UDF01S_HDL_OFFSET_BASE_+0x07), 0x00,
    GATT_SPEC_CSTM_CHARACTERISTIC_UDATAN02, GATT_SPEC_CSTM_CHARACTERISTIC
};

const uint8_t code ATT_HDL_USER_DEFINE_01_DATAN02_INIT[] =
{
    0x00, (_UDF01S_HDL_OFFSET_BASE_+0x07),
    GATT_SPEC_CSTM_CHARACTERISTIC, GATT_SPEC_CSTM_CHARACTERISTIC_UDATAN02,
    0x14,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

uint8_t xdata att_HDL_USER_DEFINE_01_DATAN02[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

const uint8_t code ATT_HDL_USER_DEFINE_01_DATAN02_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] = 
{
    0x00, (_UDF01S_HDL_OFFSET_BASE_+0x08),                                                      
    0x29, 0x02,                     
    0x02,
    0x00,                                                                                       
    0x00                                                                                        
};

uint8_t xdata att_HDL_USER_DEFINE_01_DATAN02_CLIENT_CHARACTERISTIC_CONFIGURATION[] =                                
{
    0x00, 0x00,
};

const uint8_t code ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAW02[] =
{
    0x00, (_UDF01S_HDL_OFFSET_BASE_+0x09),
    0x28, 0x03,                                            
    0x05,
    {                                                                                               
        //0x01 |                                                  
        //0x02 |                      
        //0x04 |
        0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_UDF01S_HDL_OFFSET_BASE_+0x0A), 0x00,
    GATT_SPEC_CSTM_CHARACTERISTIC_UDATAW02, GATT_SPEC_CSTM_CHARACTERISTIC
};

const uint8_t code ATT_HDL_USER_DEFINE_01_DATAW02_INIT[] =
{
    0x00, (_UDF01S_HDL_OFFSET_BASE_+0x0A),
    GATT_SPEC_CSTM_CHARACTERISTIC, GATT_SPEC_CSTM_CHARACTERISTIC_UDATAW02,
    0x14,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

uint8_t xdata att_HDL_USER_DEFINE_01_DATAW02[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};

const uint8_t code ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAR01[] =
{
    0x00, (_UDF01S_HDL_OFFSET_BASE_+0x0B),
    0x28, 0x03,                                            
    0x05,
    {                                                                                               
        //0x01 |                                                  
        0x02 |                                                    
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_UDF01S_HDL_OFFSET_BASE_+0x0C), 0x00,
    GATT_SPEC_CSTM_CHARACTERISTIC_UDATAR01, GATT_SPEC_CSTM_CHARACTERISTIC                                
};

const uint8_t code ATT_HDL_USER_DEFINE_01_DATAR01[] =
{
    0x00, (_UDF01S_HDL_OFFSET_BASE_+0x0C),
    GATT_SPEC_CSTM_CHARACTERISTIC, GATT_SPEC_CSTM_CHARACTERISTIC_UDATAR01,                              
    0x14,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13
};
#endif    //ifdef _PROFILE_USER_DEFINE_01_

#ifdef _PROFILE_GLS_
const uint8_t code ATT_HDL_GLS_PRIMARY_SERVICE[] =
{
    0x00, _GLS_HDL_OFFSET_BASE_,
    0x28, 0x00,
    0x02,
    0x08, 0x18
};

const uint8_t code ATT_HDL_GLS_CHARACTERISTIC_GLUCOSE_MEASUREMENT[] =
{
    0x00, (_GLS_HDL_OFFSET_BASE_+1), 
    0x28, 0x03,
    0x05,
    {                                                                                               
        //0x01 |                                                  
        //0x02 |                                                    
        //0x04 |
        //0x08 |
        0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_GLS_HDL_OFFSET_BASE_+2), 0x00,
    0x18, 0x2A,
};

const uint8_t code ATT_HDL_GLS_GLUCOSE_MEASUREMENT_INIT[] =
{
    0x00, (_GLS_HDL_OFFSET_BASE_+2),
    0x2A, 0x18,
    0x11,
    0x00,          //Flags
    0x00, 0x00,    //Sequence Number
    0x00, 0x00,    //UTC Time: Year
    0x00,          //UTC Time: Month
    0x00,          //UTC Time: Day
    0x00,          //UTC Time: Hours
    0x00,          //UTC Time: Minutes
    0x00,          //UTC Time: Seconds
    0x00, 0x00,    //Time Offset
    0x00, 0x00,    //Glucose Concentration - units of kg/L (0) or mol/L (1)
    0x00,          //Type, Sample Location
    0x00, 0x00,    //Sensor Status Annunciation
};

uint8_t xdata att_HDL_GLS_GLUCOSE_MEASUREMENT[] =
{
    0x11,
    0x00,          //Flags
    0x00, 0x00,    //Sequence Number
    0x00, 0x00,    //UTC Time: Year
    0x00,          //UTC Time: Month
    0x00,          //UTC Time: Day
    0x00,          //UTC Time: Hours
    0x00,          //UTC Time: Minutes
    0x00,          //UTC Time: Seconds
    0x00, 0x00,    //Time Offset
    0x00, 0x00,    //Glucose Concentration - units of kg/L (0) or mol/L (1)
    0x00,          //Type, Sample Location
    0x00, 0x00,    //Sensor Status Annunciation
};

const uint8_t code ATT_HDL_GLS_GLUCOSE_MEASUREMENT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    0x00, (_GLS_HDL_OFFSET_BASE_+3),
    0x29, 0x02,
    0x02,
    0x00,
    0x00,
};

uint8_t xdata att_HDL_GLS_GLUCOSE_MEASUREMENT_CLIENT_CHARACTERISTIC_CONFIGURATION[] =
{
    0x00,
    0x00,
};

const uint8_t code ATT_HDL_GLS_CHARACTERISTIC_GLUCOSE_MEASUREMENT_CONTEXT[] =
{
    0x00, (_GLS_HDL_OFFSET_BASE_+4), 
    0x28, 0x03,
    0x05,
    {                                                                                               
        //0x01 |                                                  
        //0x02 |                                                    
        //0x04 |
        //0x08 |
        0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_GLS_HDL_OFFSET_BASE_+5), 0x00,
    0x34, 0x2A
};

const uint8_t code ATT_HDL_GLS_GLUCOSE_MEASUREMENT_CONTEXT_INIT[] =
{
    0x00, (_GLS_HDL_OFFSET_BASE_+5),
    0x2A, 0x34,
    0x11,
    0x00,          //Flags
    0x00, 0x00,    //Sequence Number
    0x00,          //Extended Flags, Reserved for future use
    0x00,          //Carbohydrate ID
    0x00, 0x00,    //Carbohydrate - units of kilograms
    0x00,          //Meal
    0x00,          //Tester, Health
    0x00, 0x00,    //Exercise Duration
    0x00,          //Exercise Intensity
    0x00,          //Medication ID
    0x00, 0x00,    //Medication - units of kilograms (0) or liters (1)
    0x00, 0x00,    //HbA1c
};

uint8_t xdata att_HDL_GLS_GLUCOSE_MEASUREMENT_CONTEXT[] =
{
    0x00,          //Flags
    0x00, 0x00,    //Sequence Number
    0x00,          //Extended Flags, Reserved for future use
    0x00,          //Carbohydrate ID
    0x00, 0x00,    //Carbohydrate - units of kilograms
    0x00,          //Meal
    0x00,          //Tester, Health
    0x00, 0x00,    //Exercise Duration
    0x00,          //Exercise Intensity
    0x00,          //Medication ID
    0x00, 0x00,    //Medication - units of kilograms (0) or liters (1)
    0x00, 0x00,    //HbA1c
};

const uint8_t code ATT_HDL_GLS_GLUCOSE_MEASUREMENT_CONTEXT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    0x00, (_GLS_HDL_OFFSET_BASE_+6),
    0x29, 0x02,
    0x02,
    0x00,
    0x00
};

uint8_t xdata att_HDL_GLS_GLUCOSE_MEASUREMENT_CONTEXT_CLIENT_CHARACTERISTIC_CONFIGURATION[] =
{
    0x00,
    0x00,
};

const uint8_t code ATT_HDL_GLS_CHARACTERISTIC_GLUCOSE_FEATURE[] =
{
    0x00, (_GLS_HDL_OFFSET_BASE_+7),
    0x28, 0x03,
    0x05,
    {                                                                                               
        //0x01 |                                                  
        0x02 |                                                    
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_GLS_HDL_OFFSET_BASE_+8), 0x00,
    0x51, 0x2A
};

const uint8_t code ATT_HDL_GLS_GLUCOSE_FEATURE_INIT[] =
{
    0x00, (_GLS_HDL_OFFSET_BASE_+8),
    0x2A, 0x51,
    0x02,
    {                                                                                               
        0x01 |                                                  
        0x02 |                                                    
        0x04 |
        0x08 |
        0x10 |
        0x20 |
        0x40 |
        0x80 |
        0x00
    },
    {
        0x01 |
        0x02 |
        0x04 |
        0x00,
    },
};

const uint8_t code ATT_HDL_GLS_CHARACTERISTIC_RECORD_ACCESS_CONTROL_POINT[] =
{
    0x00, (_GLS_HDL_OFFSET_BASE_+9),
    0x28, 0x03,
    0x05,
    {                                                                                               
        //0x01 |                                                  
        //0x02 |                                                    
        //0x04 |
        0x08 |
        //0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    (_GLS_HDL_OFFSET_BASE_+10), 0x00,
    0x52, 0x2A,
};

const uint8_t code ATT_HDL_GLS_RECORD_ACCESS_CONTROL_POINT_INIT[] =
{
    0x00, (_GLS_HDL_OFFSET_BASE_+10),
    0x2A, 0x52,
    0x07,
    0x00,                     //Op Code                     
    0x00,                     //Operator                    
    0x00,                     //Operand, Filter Type        
    0x00, 0x00, 0x00, 0x00    //Operand, Filter Parameters  
};

uint8_t xdata att_HDL_GLS_RECORD_ACCESS_CONTROL_POINT[] =
{
    0x00,                     //Op Code
    0x00,                     //Operator
    0x00,                     //Operand, Filter Type
    0x00, 0x00, 0x00, 0x00    //Operand, Filter Parameters
};

const uint8_t code ATT_HDL_GLS_RECORD_ACCESS_CONTROL_POINT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    0x00, (_GLS_HDL_OFFSET_BASE_+11),
    0x29, 0x02,
    0x02,
    0x00,
    0x00,
};

uint8_t xdata att_HDL_GLS_RECORD_ACCESS_CONTROL_POINT_CLIENT_CHARACTERISTIC_CONFIGURATION[] =                                
{
    0x00,
    0x00,
};
#endif  //_PROFILE_GLS_

const uint8_t code ATT_PERMISSION_NULL[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_PRIMARY_SERVICE[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_CHARACTERISTIC[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_GAP_DEVICE_NAME_INIT[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_GAP_APPEARANCE[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x010 |
        //0x020 |
        //0x040 |
        //0x080 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_GAP_RECONNECTION_ADDRESS_INIT[] =
{
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_GAP_PERIPHERAL_PRIVACY_FLAG[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_GAP_PERIPHERAL_PREFERRED_CONNECTION_PARAMETERS[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};


const uint8_t code ATT_PERMISSION_HDL_GATT_SERVICE_CHANGED_INIT[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_GATT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    {
        0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};


const uint8_t code ATT_PERMISSION_HDL_DIS_SERIAL_NUMBER_STRING[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_CHARACTERISTIC_PRESENTATION_FORMAT[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_DIS_MANUFACTURER_NAME_STRING[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_DIS_SYSTEM_ID[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_DIS_FIRMWARE_REVISION_STRING[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_DIS_MODEL_NUMBER_STRING[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_DIS_HARDWARE_REVISION_STRING[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_DIS_SOFTWARE_REVISION_STRING[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_DIS_PNP_ID[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};


const uint8_t code ATT_PERMISSION_HDL_OTA_OTA_DATA_INIT[] =
{
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_OTA_OTA_DATA_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    {
        0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_OTA_OTA_DATA_DESCRIPTION[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_OTA_OTA_CMD_CONTROL_POINT_INIT[] =
{
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_OTA_OTA_CMD_CP_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    {
        0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_OTA_OTA_CMD_USER_DESCRIPTION[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_BAS_BATTERY_LEVEL_INIT[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_BAS_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    {
        0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

#ifdef _PROFILE_HOGP_
const uint8_t code ATT_PERMISSION_HDL_HIDS_HID_INFORMATION[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_HIDS_HID_CONTROL_POINT_INIT[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_HIDS_REPORT_MAP[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_HIDS_REPORT_INIT[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_HIDS_REPORT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_HIDS_REPORT_REPORT_REFERENCE[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

#ifdef _PROFILE_HOGP_MOUSE_
const uint8_t code ATT_PERMISSION_HDL_HIDS_REPORT1_USER_DESCRIPTION[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};
#endif    //_PROFILE_HOGP_MOUSE_

const uint8_t code ATT_PERMISSION_HDL_HIDS_PROTOCOL_MODE_INIT[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_HIDS_REPORT1_INIT[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_HIDS_REPORT1_REPORT_REFERENCE[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

#endif    //ifdef _PROFILE_HOGP_

#ifdef _PROFILE_TAOBAO_
const uint8_t code ATT_PERMISSION_HDL_TAOBAO_DATW[] =
{
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_TAOBAO_DATI_INIT[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_TAOBAO_DATI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    {
        0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};
#endif    //_PROFILE_TAOBAO_

#ifdef _PROFILE_WECHAT_
const uint8_t code ATT_PERMISSION_HDL_WECHAT_DATW[] =
{
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_WECHAT_DATI_INIT[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_WECHAT_DATI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    {
        0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_WECHAT_DATR[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

#ifdef _PROFILE_WECHAT_SIMPLE_MODE_
const uint8_t code ATT_PERMISSION_HDL_WECHAT_SIMPLEMODE_DATRI_INIT[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x04	|
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_WECHAT_SIMPLEMODE_DATRI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    {
        0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT[] =
{
    {
        0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x04	|
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_WECHAT_SIMPLEMODE_DATRWI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    {
        0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

#endif    //_PROFILE_WECHAT_SIMPLE_MODE_
#endif    //_PROFILE_WECHAT_

#ifdef _PROFILE_USER_DEFINE_01_
const uint8_t code ATT_PERMISSION_HDL_USER_DEFINE_01_DATAN01_INIT[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_USER_DEFINE_01_DATAN01_CLIENT_CHARACT_CONFIG_INIT[] =
{
    {
        0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_USER_DEFINE_01_DATAW01_INIT[] =
{
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_USER_DEFINE_01_DATAN02_INIT[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_USER_DEFINE_01_DATAN02_CLIENT_CHARACT_CONFIG_INIT[] =
{
    {
        0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_USER_DEFINE_01_DATAW02_INIT[] =
{
    {
        //0x01 |
        0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_USER_DEFINE_01_DATAR01[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};
#endif    //_PROFILE_USER_DEFINE_01_

#ifdef _PROFILE_GLS_
const uint8_t code ATT_PERMISSION_HDL_GLS_GLUCOSE_MEASUREMENT_INIT[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_GLS_GLUCOSE_MEASUREMENT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_GLS_GLUCOSE_MEASUREMENT_CONTEXT_INIT[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_GLS_GLUCOSE_MEASUREMENT_CONTEXT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_GLS_GLUCOSE_FEATURE_INIT[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        //0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_GLS_RECORD_ACCESS_CONTROL_POINT_INIT[] =
{
    {
        //0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};

const uint8_t code ATT_PERMISSION_HDL_GLS_RECORD_ACCESS_CONTROL_POINT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT[] =
{
    {
        0x01 |
        //0x02 |
        //0x04 |
        //0x08 |
        //0x10 |
        0x20 |
        //0x40 |
        //0x80 |
        0x00
    },
    {
        0x01 |
        //0x02 |
        0x00
    },
};
#endif  //_PROFILE_GLS_

code uint8_t code *ATTRIBUTE_SERVER[SIZE_ATTRIBUTE_SERVER] =
{
    ATT_HDL_INVALID,
    ATT_HDL_GAP_PRIMARY_SERVICE,
    ATT_HDL_GAP_CHARACTERISTIC_DEVICE_NAME,
    ATT_HDL_GAP_DEVICE_NAME_INIT,
    ATT_HDL_GAP_CHARACTERISTIC_APPEARANCE,
    ATT_HDL_GAP_APPEARANCE,
    ATT_HDL_GAP_CHARACTERISTIC_RECONNECTION_ADDRESS,
    ATT_HDL_GAP_RECONNECTION_ADDRESS_INIT,
    ATT_HDL_GAP_CHARACTERISTIC_PERIPHERAL_PRIVACY_FLAG,
    ATT_HDL_GAP_PERIPHERAL_PRIVACY_FLAG,
    ATT_HDL_GAP_CHARACTERISTIC_PERIPHERAL_PREFERRED_CONNECTION_PARAMETERS,
    ATT_HDL_GAP_PERIPHERAL_PREFERRED_CONNECTION_PARAMETERS,
    ATT_HDL_GATT_PRIMARY_SERVICE,
    ATT_HDL_GATT_CHARACTERISTIC_SERVICE_CHANGED,
    ATT_HDL_GATT_SERVICE_CHANGED_INIT,
    ATT_HDL_GATT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_HDL_DIS_PRIMARY_SERVICE,
    ATT_HDL_DIS_CHARACTERISTIC_SERIAL_NUMBER_STRING,
    ATT_HDL_DIS_SERIAL_NUMBER_STRING,
    ATT_HDL_DIS_SERIAL_NUMBER_STRING_PRESENTATION_FORMAT,
    ATT_HDL_DIS_CHARACTERISTIC_MANUFACTURER_NAME_STRING,
    ATT_HDL_DIS_MANUFACTURER_NAME_STRING,
    ATT_HDL_DIS_MANUFACTURER_NAME_STRING_PRESENTATION_FORMAT,
    ATT_HDL_DIS_CHARACTERISTIC_SYSTEM_ID,
    ATT_HDL_DIS_SYSTEM_ID,
    ATT_HDL_DIS_CHARACTERISTIC_FIRMWARE_REVISION_STRING,
    ATT_HDL_DIS_FIRMWARE_REVISION_STRING,
    ATT_HDL_DIS_FIRMWARE_REVISION_STRING_PRESENTATION_FORMAT,
    ATT_HDL_DIS_CHARACTERISTIC_MODEL_NUMBER_STRING,
    ATT_HDL_DIS_MODEL_NUMBER_STRING,
    ATT_HDL_DIS_MODEL_NUMBER_STRING_PRESENTATION_FORMAT,
    ATT_HDL_DIS_CHARACTERISTIC_HARDWARE_REVISION_STRING,
    ATT_HDL_DIS_HARDWARE_REVISION_STRING,
    ATT_HDL_DIS_HARDWARE_REVISION_STRING_PRESENTATION_FORMAT,
    ATT_HDL_DIS_CHARACTERISTIC_SOFTWARE_REVISION_STRING,
    ATT_HDL_DIS_SOFTWARE_REVISION_STRING,
    ATT_HDL_DIS_SOFTWARE_REVISION_STRING_PRESENTATION_FORMAT,
    ATT_HDL_DIS_CHARACTERISTIC_PNP_ID,
    ATT_HDL_DIS_PNP_ID,
    ATT_HDL_OTA_PRIMARY_SERVICE,
    ATT_HDL_OTA_CHARACTERISTIC_OTA_DATA,
    ATT_HDL_OTA_OTA_DATA_INIT,
    ATT_HDL_OTA_OTA_DATA_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_HDL_OTA_OTA_DATA_DESCRIPTION,
    ATT_HDL_OTA_CHARACTERISTIC_OTA_CMD_CONTROL_POINT,
    ATT_HDL_OTA_OTA_CMD_CONTROL_POINT_INIT,
    ATT_HDL_OTA_OTA_CMD_CONTROL_POINT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_HDL_OTA_OTA_CMD_USER_DESCRIPTION,
    ATT_HDL_BAS_PRIMARY_SERVICE,
    ATT_HDL_BAS_CHARACTERISTIC_BATTERY_LEVEL,
    ATT_HDL_BAS_BATTERY_LEVEL_INIT,
    ATT_HDL_BAS_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,

#ifdef _PROFILE_HOGP_
    ATT_HDL_HIDS_PRIMARY_SERVICE,
    ATT_HDL_HIDS_CHARACTERISTIC_HID_INFORMATION,
    ATT_HDL_HIDS_HID_INFORMATION,
    ATT_HDL_HIDS_CHARACTERISTIC_HID_CONTROL_POINT,
    ATT_HDL_HIDS_HID_CONTROL_POINT_INIT,
    ATT_HDL_HIDS_CHARACTERISTIC_REPORT_MAP,
    ATT_HDL_HIDS_REPORT_MAP,
#ifdef _PROFILE_HOGP_KEYBOARD_
    ATT_HDL_HIDS_CHARACTERISTIC_REPORT_KBI,
    ATT_HDL_HIDS_REPORT_KBI_INIT,
    ATT_HDL_HIDS_REPORT_KBI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_HDL_HIDS_REPORT_KBI_REPORT_REFERENCE,
    ATT_HDL_HIDS_CHARACTERISTIC_REPORT_KBO,
    ATT_HDL_HIDS_REPORT_KBO_INIT,
    ATT_HDL_HIDS_REPORT_KBO_REPORT_REFERENCE,
#endif
#ifdef _PROFILE_HOGP_MOUSE_
    ATT_HDL_HIDS_CHARACTERISTIC_REPORT_MSI,
    ATT_HDL_HIDS_REPORT_MSI_INIT,
    ATT_HDL_HIDS_REPORT_MSI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_HDL_HIDS_REPORT_MSI_REPORT_REFERENCE,
    ATT_HDL_HIDS_CHARACTERISTIC_REPORT_MSF,
    ATT_HDL_HIDS_REPORT_MSF_INIT,
    ATT_HDL_HIDS_REPORT_MSF_REPORT_REFERENCE,
    ATT_HDL_HIDS_REPORT_MSF_USER_DESCRIPTION,
#endif
#ifdef _PROFILE_HOGP_COMSUMER_
    ATT_HDL_HIDS_CHARACTERISTIC_REPORT_CSI,
    ATT_HDL_HIDS_REPORT_CSI_INIT,
    ATT_HDL_HIDS_REPORT_CSI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_HDL_HIDS_REPORT_CSI_REPORT_REFERENCE,
#endif
    ATT_HDL_HIDS_CHARACTERISTIC_PROTOCOL_MODE,
    ATT_HDL_HIDS_PROTOCOL_MODE_INIT,
#endif

////////////////////////TaoBao//////////////////////////////////
#ifdef _PROFILE_TAOBAO_
    ATT_HDL_TAOBAO_PRIMARY_SERVICE,
    ATT_HDL_TAOBAO_CHARACTERISTIC_DATW,
    ATT_HDL_TAOBAO_DATW_INIT,
    ATT_HDL_TAOBAO_CHARACTERISTIC_DATI,
    ATT_HDL_TAOBAO_DATI_INIT,
    ATT_HDL_TAOBAO_DATI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
#endif
////////////////////////TaoBao//////////////////////////////////

////////////////////////WeChat//////////////////////////////////
#ifdef _PROFILE_WECHAT_
    ATT_HDL_WECHAT_PRIMARY_SERVICE,
    ATT_HDL_WECHAT_CHARACTERISTIC_DATW,
    ATT_HDL_WECHAT_DATW_INIT,
    ATT_HDL_WECHAT_CHARACTERISTIC_DATI,
    ATT_HDL_WECHAT_DATI_INIT,
    ATT_HDL_WECHAT_DATI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_HDL_WECHAT_CHARACTERISTIC_DATR,
    ATT_HDL_WECHAT_DATR,
/////////////////////Simple mode current pedometer measurement///
#ifdef _PROFILE_WECHAT_SIMPLE_MODE_
    ATT_HDL_WECHAT_SIMPLEMODE_CHARACTERISTIC_DATRI,
    ATT_HDL_WECHAT_SIMPLEMODE_DATRI_INIT,
    ATT_HDL_WECHAT_SIMPLEMODE_DATRI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
/////////////////////Simple mode current pedometer measurement///
/////////////////////Simple mode target//////////////////////////
    ATT_HDL_WECHAT_SIMPLEMODE_CHARACTERISTIC_DATRWI,
    ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,
    ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
#endif
/////////////////////Simple mode target/////////////////////////
#endif
////////////////////////WeChat//////////////////////////////////

////////////////////////6UUID//////////////////////////////////
#ifdef _PROFILE_USER_DEFINE_01_
    ATT_HDL_USER_DEFINE_01_PRIMARY_SERVICE,
    ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAN01,
    ATT_HDL_USER_DEFINE_01_DATAN01_INIT,
    ATT_HDL_USER_DEFINE_01_DATAN01_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAW01,
    ATT_HDL_USER_DEFINE_01_DATAW01_INIT,
    ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAN02,
    ATT_HDL_USER_DEFINE_01_DATAN02_INIT,
    ATT_HDL_USER_DEFINE_01_DATAN02_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAW02,
    ATT_HDL_USER_DEFINE_01_DATAW02_INIT,
    ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAR01,
    ATT_HDL_USER_DEFINE_01_DATAR01,
#endif
////////////////////////6UUID//////////////////////////////////

////////////////////////GLS////////////////////////////////////
 #ifdef _PROFILE_GLS_
    ATT_HDL_GLS_PRIMARY_SERVICE,
    ATT_HDL_GLS_CHARACTERISTIC_GLUCOSE_MEASUREMENT,
    ATT_HDL_GLS_GLUCOSE_MEASUREMENT_INIT,
    ATT_HDL_GLS_GLUCOSE_MEASUREMENT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_HDL_GLS_CHARACTERISTIC_GLUCOSE_MEASUREMENT_CONTEXT,
    ATT_HDL_GLS_GLUCOSE_MEASUREMENT_CONTEXT_INIT,
    ATT_HDL_GLS_GLUCOSE_MEASUREMENT_CONTEXT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_HDL_GLS_CHARACTERISTIC_GLUCOSE_FEATURE,
    ATT_HDL_GLS_GLUCOSE_FEATURE_INIT,
    ATT_HDL_GLS_CHARACTERISTIC_RECORD_ACCESS_CONTROL_POINT,
    ATT_HDL_GLS_RECORD_ACCESS_CONTROL_POINT_INIT,
    ATT_HDL_GLS_RECORD_ACCESS_CONTROL_POINT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
#endif
////////////////////////GLS////////////////////////////////////
};



code uint8_t *ATTRIBUTE_SERVER_param[SIZE_ATTRIBUTE_SERVER] =
{
        &ATT_HDL_INVALID[5],
        &ATT_HDL_GAP_PRIMARY_SERVICE[5],
        &ATT_HDL_GAP_CHARACTERISTIC_DEVICE_NAME[5],
    att_HDL_GAP_DEVICE_NAME,
        &ATT_HDL_GAP_CHARACTERISTIC_APPEARANCE[5],
        &ATT_HDL_GAP_APPEARANCE[5],
        &ATT_HDL_GAP_CHARACTERISTIC_RECONNECTION_ADDRESS[5],
    att_HDL_GAP_RECONNECTION_ADDRESS,
        &ATT_HDL_GAP_CHARACTERISTIC_PERIPHERAL_PRIVACY_FLAG[5],
        &ATT_HDL_GAP_PERIPHERAL_PRIVACY_FLAG[5],
        &ATT_HDL_GAP_CHARACTERISTIC_PERIPHERAL_PREFERRED_CONNECTION_PARAMETERS[5],
        &ATT_HDL_GAP_PERIPHERAL_PREFERRED_CONNECTION_PARAMETERS[5],
        &ATT_HDL_GATT_PRIMARY_SERVICE[5],
        &ATT_HDL_GATT_CHARACTERISTIC_SERVICE_CHANGED[5],
    att_HDL_GATT_SERVICE_CHANGED,
    att_HDL_GATT_CLIENT_CHARACTERISTIC_CONFIGURATION,
        &ATT_HDL_DIS_PRIMARY_SERVICE[5],
        &ATT_HDL_DIS_CHARACTERISTIC_SERIAL_NUMBER_STRING[5],
        &ATT_HDL_DIS_SERIAL_NUMBER_STRING[5],
        &ATT_HDL_DIS_SERIAL_NUMBER_STRING_PRESENTATION_FORMAT[5],
        &ATT_HDL_DIS_CHARACTERISTIC_MANUFACTURER_NAME_STRING[5],
        &ATT_HDL_DIS_MANUFACTURER_NAME_STRING[5],
        &ATT_HDL_DIS_MANUFACTURER_NAME_STRING_PRESENTATION_FORMAT[5],
        &ATT_HDL_DIS_CHARACTERISTIC_SYSTEM_ID[5],
        &ATT_HDL_DIS_SYSTEM_ID[5],
        &ATT_HDL_DIS_CHARACTERISTIC_FIRMWARE_REVISION_STRING[5],
        &ATT_HDL_DIS_FIRMWARE_REVISION_STRING[5],
        &ATT_HDL_DIS_FIRMWARE_REVISION_STRING_PRESENTATION_FORMAT[5],
        &ATT_HDL_DIS_CHARACTERISTIC_MODEL_NUMBER_STRING[5],
        &ATT_HDL_DIS_MODEL_NUMBER_STRING[5],
        &ATT_HDL_DIS_MODEL_NUMBER_STRING_PRESENTATION_FORMAT[5],
        &ATT_HDL_DIS_CHARACTERISTIC_HARDWARE_REVISION_STRING[5],
        &ATT_HDL_DIS_HARDWARE_REVISION_STRING[5],
        &ATT_HDL_DIS_HARDWARE_REVISION_STRING_PRESENTATION_FORMAT[5],
        &ATT_HDL_DIS_CHARACTERISTIC_SOFTWARE_REVISION_STRING[5],
        &ATT_HDL_DIS_SOFTWARE_REVISION_STRING[5],
        &ATT_HDL_DIS_SOFTWARE_REVISION_STRING_PRESENTATION_FORMAT[5],
        &ATT_HDL_DIS_CHARACTERISTIC_PNP_ID[5],
        &ATT_HDL_DIS_PNP_ID[5],
        &ATT_HDL_OTA_PRIMARY_SERVICE[5],
        &ATT_HDL_OTA_CHARACTERISTIC_OTA_DATA[5],
    att_HDL_OTA_OTA_DATA,
    att_HDL_OTA_OTA_DATA_CLIENT_CHARACTERISTIC_CONFIGURATION,
        &ATT_HDL_OTA_OTA_DATA_DESCRIPTION[5],
        &ATT_HDL_OTA_CHARACTERISTIC_OTA_CMD_CONTROL_POINT[5],
    att_HDL_OTA_OTA_CMD_CONTROL_POINT,
    att_HDL_OTA_OTA_CMD_CONTROL_POINT_CLIENT_CHARACTERISTIC_CONFIGURATION,
        &ATT_HDL_OTA_OTA_CMD_USER_DESCRIPTION[5],        
        &ATT_HDL_BAS_PRIMARY_SERVICE[5],
        &ATT_HDL_BAS_CHARACTERISTIC_BATTERY_LEVEL[5],
    att_HDL_BAS_BATTERY_LEVEL,
    att_HDL_BAS_CLIENT_CHARACTERISTIC_CONFIGURATION,

#ifdef _PROFILE_HOGP_
        &ATT_HDL_HIDS_PRIMARY_SERVICE[5],
        &ATT_HDL_HIDS_CHARACTERISTIC_HID_INFORMATION[5],
        &ATT_HDL_HIDS_HID_INFORMATION[5],
        &ATT_HDL_HIDS_CHARACTERISTIC_HID_CONTROL_POINT[5],
    att_HDL_HIDS_HID_CONTROL_POINT,
        &ATT_HDL_HIDS_CHARACTERISTIC_REPORT_MAP[5],
        &ATT_HDL_HIDS_REPORT_MAP[5],
#ifdef _PROFILE_HOGP_KEYBOARD_
        &ATT_HDL_HIDS_CHARACTERISTIC_REPORT_KBI[5],
    att_HDL_HIDS_REPORT_KBI,
    att_HDL_HIDS_REPORT_KBI_CLIENT_CHARACTERISTIC_CONFIGURATION,
        &ATT_HDL_HIDS_REPORT_KBI_REPORT_REFERENCE[5],
        &ATT_HDL_HIDS_CHARACTERISTIC_REPORT_KBO[5],
    att_HDL_HIDS_REPORT_KBO,
        &ATT_HDL_HIDS_REPORT_KBO_REPORT_REFERENCE[5],
#endif
#ifdef _PROFILE_HOGP_MOUSE_
        &ATT_HDL_HIDS_CHARACTERISTIC_REPORT_MSI[5],
    att_HDL_HIDS_REPORT_MSI,
    att_HDL_HIDS_REPORT_MSI_CLIENT_CHARACTERISTIC_CONFIGURATION,
        &ATT_HDL_HIDS_REPORT_MSI_REPORT_REFERENCE[5],
        &ATT_HDL_HIDS_CHARACTERISTIC_REPORT_MSF[5],
    att_HDL_HIDS_REPORT_MSF,
        &ATT_HDL_HIDS_REPORT_MSF_REPORT_REFERENCE[5],
        &ATT_HDL_HIDS_REPORT_MSF_USER_DESCRIPTION[5],
#endif
#ifdef _PROFILE_HOGP_COMSUMER_
        &ATT_HDL_HIDS_CHARACTERISTIC_REPORT_CSI[5],
    att_HDL_HIDS_REPORT_CSI,
    att_HDL_HIDS_REPORT_CSI_CLIENT_CHARACTERISTIC_CONFIGURATION,
        &ATT_HDL_HIDS_REPORT_CSI_REPORT_REFERENCE[5],
#endif
        &ATT_HDL_HIDS_CHARACTERISTIC_PROTOCOL_MODE[5],
    att_HDL_HIDS_PROTOCOL_MODE,
#endif

////////////////////////TaoBao//////////////////////////////////
#ifdef _PROFILE_TAOBAO_
        &ATT_HDL_TAOBAO_PRIMARY_SERVICE[5],
        &ATT_HDL_TAOBAO_CHARACTERISTIC_DATW[5],
        att_HDL_TAOBAO_DATW,
        &ATT_HDL_TAOBAO_CHARACTERISTIC_DATI[5],
    att_HDL_TAOBAO_DATI,
    att_HDL_TAOBAO_DATI_MEASUREMENT_CLIENT_CHARACTERISTIC_CONFIGURATION,
#endif
////////////////////////TaoBao//////////////////////////////////

////////////////////////WeChat//////////////////////////////////
#ifdef _PROFILE_WECHAT_
        &ATT_HDL_WECHAT_PRIMARY_SERVICE[5],
        &ATT_HDL_WECHAT_CHARACTERISTIC_DATW[5],
        att_HDL_WECHAT_DATW,
        &ATT_HDL_WECHAT_CHARACTERISTIC_DATI[5],
    att_HDL_WECHAT_DATI,
    att_HDL_WECHAT_DATI_MEASUREMENT_CLIENT_CHARACTERISTIC_CONFIGURATION,
        &ATT_HDL_WECHAT_CHARACTERISTIC_DATR[5],
        &ATT_HDL_WECHAT_DATR[5],
/////////////////////Simple mode current pedometer measurement///
#ifdef _PROFILE_WECHAT_SIMPLE_MODE_
        &ATT_HDL_WECHAT_SIMPLEMODE_CHARACTERISTIC_DATRI[5],
    att_HDL_WECHAT_SIMPLEMODE_DATRI,
    att_HDL_WECHAT_SIMPLEMODE_DATRI_CLIENT_CHARACTERISTIC_CONFIGURATION,
/////////////////////Simple mode current pedometer measurement///
/////////////////////Simple mode target//////////////////////////
        &ATT_HDL_WECHAT_SIMPLEMODE_CHARACTERISTIC_DATRWI[5],
    att_HDL_WECHAT_SIMPLEMODE_DATRWI,
    att_HDL_WECHAT_SIMPLEMODE_DATRWI_CLIENT_CHARACTERISTIC_CONFIGURATION,
#endif
/////////////////////Simple mode target/////////////////////////
#endif
////////////////////////WeChat//////////////////////////////////

////////////////////////6UUID//////////////////////////////////
#ifdef _PROFILE_USER_DEFINE_01_
        &ATT_HDL_USER_DEFINE_01_PRIMARY_SERVICE[5],
        &ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAN01[5],
    att_HDL_USER_DEFINE_01_DATAN01,
    att_HDL_USER_DEFINE_01_DATAN01_CLIENT_CHARACTERISTIC_CONFIGURATION,
        &ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAW01[5],
    att_HDL_USER_DEFINE_01_DATAW01,
        &ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAN02[5],
    att_HDL_USER_DEFINE_01_DATAN02,
    att_HDL_USER_DEFINE_01_DATAN02_CLIENT_CHARACTERISTIC_CONFIGURATION,
        &ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAW02[5],
    att_HDL_USER_DEFINE_01_DATAW02,
        &ATT_HDL_USER_DEFINE_01_CHARACTERISTIC_DATAR01[5],
        &ATT_HDL_USER_DEFINE_01_DATAR01[5],
#endif
////////////////////////6UUID//////////////////////////////////

////////////////////////GLS////////////////////////////////////
 #ifdef _PROFILE_GLS_
         &ATT_HDL_GLS_PRIMARY_SERVICE[5],
         &ATT_HDL_GLS_CHARACTERISTIC_GLUCOSE_MEASUREMENT[5],
     att_HDL_GLS_GLUCOSE_MEASUREMENT,
     att_HDL_GLS_GLUCOSE_MEASUREMENT_CLIENT_CHARACTERISTIC_CONFIGURATION,
         &ATT_HDL_GLS_CHARACTERISTIC_GLUCOSE_MEASUREMENT_CONTEXT[5],
     att_HDL_GLS_GLUCOSE_MEASUREMENT_CONTEXT,
     att_HDL_GLS_GLUCOSE_MEASUREMENT_CONTEXT_CLIENT_CHARACTERISTIC_CONFIGURATION,
         &ATT_HDL_GLS_CHARACTERISTIC_GLUCOSE_FEATURE[5],
         &ATT_HDL_GLS_GLUCOSE_FEATURE_INIT[5],
         &ATT_HDL_GLS_CHARACTERISTIC_RECORD_ACCESS_CONTROL_POINT[5],
     att_HDL_GLS_RECORD_ACCESS_CONTROL_POINT,
     att_HDL_GLS_RECORD_ACCESS_CONTROL_POINT_CLIENT_CHARACTERISTIC_CONFIGURATION,
 #endif
////////////////////////GLS////////////////////////////////////

};


code uint8_t code *ATTRIBUTE_SERVER_PERMISSION[SIZE_ATTRIBUTE_SERVER] =
{
    ATT_PERMISSION_NULL,                                                
    ATT_PERMISSION_PRIMARY_SERVICE,                                     
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_GAP_DEVICE_NAME_INIT,                            
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_GAP_APPEARANCE,                                  
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_GAP_RECONNECTION_ADDRESS_INIT,                   
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_GAP_PERIPHERAL_PRIVACY_FLAG,                     
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_GAP_PERIPHERAL_PREFERRED_CONNECTION_PARAMETERS,  
    ATT_PERMISSION_PRIMARY_SERVICE,                                     
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_GATT_SERVICE_CHANGED_INIT,                       
    ATT_PERMISSION_HDL_GATT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,   
    ATT_PERMISSION_PRIMARY_SERVICE,                                     
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_DIS_SERIAL_NUMBER_STRING,                        
    ATT_PERMISSION_CHARACTERISTIC_PRESENTATION_FORMAT,                  
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_DIS_MANUFACTURER_NAME_STRING,                    
    ATT_PERMISSION_CHARACTERISTIC_PRESENTATION_FORMAT,                  
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_DIS_SYSTEM_ID,                                   
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_DIS_FIRMWARE_REVISION_STRING,                    
    ATT_PERMISSION_CHARACTERISTIC_PRESENTATION_FORMAT,                  
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_DIS_MODEL_NUMBER_STRING,                         
    ATT_PERMISSION_CHARACTERISTIC_PRESENTATION_FORMAT,                  
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_DIS_HARDWARE_REVISION_STRING,                    
    ATT_PERMISSION_CHARACTERISTIC_PRESENTATION_FORMAT,                  
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_DIS_SOFTWARE_REVISION_STRING,                    
    ATT_PERMISSION_CHARACTERISTIC_PRESENTATION_FORMAT,                  
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_DIS_PNP_ID,                                      
    ATT_PERMISSION_PRIMARY_SERVICE,                                             
    ATT_PERMISSION_CHARACTERISTIC,                                              
    ATT_PERMISSION_HDL_OTA_OTA_DATA_INIT,                                       
    ATT_PERMISSION_HDL_OTA_OTA_DATA_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,   
    ATT_PERMISSION_HDL_OTA_OTA_DATA_DESCRIPTION,                                
    ATT_PERMISSION_CHARACTERISTIC,                                              
    ATT_PERMISSION_HDL_OTA_OTA_CMD_CONTROL_POINT_INIT,                          
    ATT_PERMISSION_HDL_OTA_OTA_CMD_CP_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,                        
    ATT_PERMISSION_HDL_OTA_OTA_CMD_USER_DESCRIPTION,                            
    ATT_PERMISSION_PRIMARY_SERVICE,                                     
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_BAS_BATTERY_LEVEL_INIT,
    ATT_PERMISSION_HDL_BAS_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,

#ifdef _PROFILE_HOGP_
    ATT_PERMISSION_PRIMARY_SERVICE,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_HIDS_HID_INFORMATION,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_HIDS_HID_CONTROL_POINT_INIT,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_HIDS_REPORT_MAP,
#ifdef _PROFILE_HOGP_KEYBOARD_
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_HIDS_REPORT_INIT,
    ATT_PERMISSION_HDL_HIDS_REPORT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_PERMISSION_HDL_HIDS_REPORT_REPORT_REFERENCE,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_HIDS_REPORT1_INIT,
    ATT_PERMISSION_HDL_HIDS_REPORT1_REPORT_REFERENCE,
#endif
#ifdef _PROFILE_HOGP_MOUSE_
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_HIDS_REPORT_INIT,
    ATT_PERMISSION_HDL_HIDS_REPORT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_PERMISSION_HDL_HIDS_REPORT_REPORT_REFERENCE,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_HIDS_REPORT1_INIT,
    ATT_PERMISSION_HDL_HIDS_REPORT1_REPORT_REFERENCE,
    ATT_PERMISSION_HDL_HIDS_REPORT1_USER_DESCRIPTION,
#endif
#ifdef _PROFILE_HOGP_COMSUMER_
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_HIDS_REPORT_INIT,
    ATT_PERMISSION_HDL_HIDS_REPORT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_PERMISSION_HDL_HIDS_REPORT_REPORT_REFERENCE,
#endif
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_HIDS_PROTOCOL_MODE_INIT,
#endif

////////////////////////TaoBao//////////////////////////////////
#ifdef _PROFILE_TAOBAO_
    ATT_PERMISSION_PRIMARY_SERVICE,                                     
    ATT_PERMISSION_CHARACTERISTIC,                                      
    ATT_PERMISSION_HDL_TAOBAO_DATW,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_TAOBAO_DATI_INIT,
    ATT_PERMISSION_HDL_TAOBAO_DATI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
#endif
////////////////////////TaoBao//////////////////////////////////

////////////////////////WeChat//////////////////////////////////
#ifdef _PROFILE_WECHAT_
    ATT_PERMISSION_PRIMARY_SERVICE,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_WECHAT_DATW,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_WECHAT_DATI_INIT,
    ATT_PERMISSION_HDL_WECHAT_DATI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_WECHAT_DATR,
/////////////////////Simple mode current pedometer measurement///
#ifdef _PROFILE_WECHAT_SIMPLE_MODE_
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_WECHAT_SIMPLEMODE_DATRI_INIT,
    ATT_PERMISSION_HDL_WECHAT_SIMPLEMODE_DATRI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
/////////////////////Simple mode current pedometer measurement///
/////////////////////Simple mode target//////////////////////////
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT,
    ATT_PERMISSION_HDL_WECHAT_SIMPLEMODE_DATRWI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
#endif
/////////////////////Simple mode target/////////////////////////
#endif
////////////////////////WeChat//////////////////////////////////

////////////////////////6UUID//////////////////////////////////
#ifdef _PROFILE_USER_DEFINE_01_
    ATT_PERMISSION_PRIMARY_SERVICE,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_USER_DEFINE_01_DATAN01_INIT,
    ATT_PERMISSION_HDL_USER_DEFINE_01_DATAN01_CLIENT_CHARACT_CONFIG_INIT,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_USER_DEFINE_01_DATAW01_INIT,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_USER_DEFINE_01_DATAN02_INIT,
    ATT_PERMISSION_HDL_USER_DEFINE_01_DATAN02_CLIENT_CHARACT_CONFIG_INIT,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_USER_DEFINE_01_DATAW02_INIT,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_USER_DEFINE_01_DATAR01,  
#endif
////////////////////////6UUID//////////////////////////////////
////////////////////////GLS////////////////////////////////////
#ifdef _PROFILE_GLS_
    ATT_PERMISSION_PRIMARY_SERVICE,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_GLS_GLUCOSE_MEASUREMENT_INIT,
    ATT_PERMISSION_HDL_GLS_GLUCOSE_MEASUREMENT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_GLS_GLUCOSE_MEASUREMENT_CONTEXT_INIT,
    ATT_PERMISSION_HDL_GLS_GLUCOSE_MEASUREMENT_CONTEXT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_GLS_GLUCOSE_FEATURE_INIT,
    ATT_PERMISSION_CHARACTERISTIC,
    ATT_PERMISSION_HDL_GLS_RECORD_ACCESS_CONTROL_POINT_INIT,
    ATT_PERMISSION_HDL_GLS_RECORD_ACCESS_CONTROL_POINT_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
#endif
////////////////////////GLS////////////////////////////////////
};

code uint8_t code *ATTRIBUTE_SERVER_BOND[SIZE_ATTRIBUTE_SERVER_BOND] =
{
    ATT_HDL_BAS_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
#ifdef _PROFILE_HOGP_
#ifdef _PROFILE_HOGP_COMSUMER_
    ATT_HDL_HIDS_REPORT_CSI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
#endif
#ifdef _PROFILE_HOGP_MOUSE_
    ATT_HDL_HIDS_REPORT_MSI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_HDL_HIDS_REPORT_MSF_INIT,
#endif
#ifdef _PROFILE_HOGP_KEYBOARD_
    ATT_HDL_HIDS_REPORT_KBI_CLIENT_CHARACTERISTIC_CONFIGURATION_INIT,
    ATT_HDL_HIDS_REPORT_KBO_INIT,
#endif
#endif
};

code uint8_t *ATTRIBUTE_SERVER_BOND_PARAM[SIZE_ATTRIBUTE_SERVER_BOND] =
{
    att_HDL_BAS_CLIENT_CHARACTERISTIC_CONFIGURATION,
#ifdef _PROFILE_HOGP_
#ifdef _PROFILE_HOGP_COMSUMER_
    att_HDL_HIDS_REPORT_CSI_CLIENT_CHARACTERISTIC_CONFIGURATION,
#endif
#ifdef _PROFILE_HOGP_MOUSE_
    att_HDL_HIDS_REPORT_MSI_CLIENT_CHARACTERISTIC_CONFIGURATION,
    att_HDL_HIDS_REPORT_MSF,
#endif
#ifdef _PROFILE_HOGP_KEYBOARD_
    att_HDL_HIDS_REPORT_KBI_CLIENT_CHARACTERISTIC_CONFIGURATION,
    att_HDL_HIDS_REPORT_KBO,
#endif
#endif
};
