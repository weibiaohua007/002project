/*****************************************************************************
**               AMICCOM Electronics Corporation Document                   **
**          Copyright (c) 2011-2014 AMICCOM Electronics Corporation         **
**                                                                          **
**      A3,1F,No.1, Li-Hsin 1th Road, Science_Based Industrid Park,         **
**                       Hsin_Chu City, 300, Taiwan, ROC.                   **
**                 Tel: 886-3-5785818   Fax: 886-3-5785819                  **
**         E-mail:info@amiccom.com.tw  http: //www.amiccom.com.tw           **
*****************************************************************************/
#ifndef _SERVICEGEN_H_
#define _SERVICEGEN_H_


/*------- Multi-Function select ----------*/
/*----------------------------------------*/
//#define _PROFILE_HOGP_
//#define _PROFILE_HOGP_MOUSE_
//#define _PROFILE_HOGP_KEYBOARD_
//#define _PROFILE_HOGP_COMSUMER_



#define BLE_NAME_STRING	"Fmg-Tech"
#define BLE_NAME_LENGTH	sizeof(BLE_NAME_STRING)

#define _PROFILE_USER_DEFINE_01_

#define _PROFILE_USER_TEMPERTURE_

//#define _PROFILE_TAOBAO_
//#define _PROFILE_WECHAT_
//#define _PROFILE_WECHAT_SIMPLE_MODE_

//#define _PROFILE_GLS_
/*----------------------------------------*/
/*----------------------------------------*/

//////////////////////////////6UUID///////////////////////////////////
#ifdef _PROFILE_USER_DEFINE_01_
#define GATT_SPEC_CSTM_SERVICES                   0xFF
#define GATT_SPEC_CSTM_SERVICES_UDF01S            0xF0

#define GATT_SPEC_CSTM_CHARACTERISTIC             0xFF
#define GATT_SPEC_CSTM_CHARACTERISTIC_UDATAN01    0xF1
#define GATT_SPEC_CSTM_CHARACTERISTIC_UDATAW01    0xF2
#define GATT_SPEC_CSTM_CHARACTERISTIC_UDATAN02    0xF3
#define GATT_SPEC_CSTM_CHARACTERISTIC_UDATAW02    0xF4
#define GATT_SPEC_CSTM_CHARACTERISTIC_UDATAR01    0xF5
#endif
//////////////////////////////6UUID///////////////////////////////////






#ifdef _PROFILE_HOGP_
#ifdef _PROFILE_HOGP_MOUSE_
#if defined _PROFILE_HOGP_KEYBOARD_
#define _PROFILE_HOGP_MULTI_
#elif defined _PROFILE_HOGP_COMSUMER_
#define _PROFILE_HOGP_MULTI_
#endif
#endif

#ifndef _PROFILE_HOGP_MULTI_
#ifdef _PROFILE_HOGP_KEYBOARD_
#ifdef _PROFILE_HOGP_COMSUMER_
#define _PROFILE_HOGP_MULTI_
#endif
#endif
#else
#endif

#ifndef _PROFILE_HOGP_MULTI_
#define __PROFILE_HOGP_KEYBOARD_RPIDOFST_   0
#define __PROFILE_HOGP_MS_RPIDOFST_         0
#define __PROFILE_HOGP_CS_RPIDOFST_         0
#else
#define __PROFILE_HOGP_KEYBOARD_RPIDOFST_   1
#define __PROFILE_HOGP_MS_RPIDOFST_         2
#define __PROFILE_HOGP_CS_RPIDOFST_         3
#endif
#endif      //#ifdef _PROFILE_HOGP_



#define _SERVICE_OFFSET_BASE_                           56

#ifdef _PROFILE_HOGP_
#define SIZE_ATTRIBUTE_HIDS_BASE_                       7
#ifdef _PROFILE_HOGP_COMSUMER_
#define SIZE_ATTRIBUTE_HIDS_COMSUMER_                   4
#else
#define SIZE_ATTRIBUTE_HIDS_COMSUMER_                   0
#endif
#ifdef _PROFILE_HOGP_MOUSE_
#define SIZE_ATTRIBUTE_HIDS_MOUSE_                      8
#else
#define SIZE_ATTRIBUTE_HIDS_MOUSE_                      0
#endif
#ifdef _PROFILE_HOGP_KEYBOARD_
#define SIZE_ATTRIBUTE_HIDS_KEYBOARD_                   7
#else
#define SIZE_ATTRIBUTE_HIDS_KEYBOARD_                   0
#endif
#define SIZE_ATTRIBUTE_HIDS_RPT_REF                     2

#define _HOGP_HDL_OFFSET_BASE_                          _SERVICE_OFFSET_BASE_
#define _HOGP_HDL_OFFSET_KB_                            (_HOGP_HDL_OFFSET_BASE_+SIZE_ATTRIBUTE_HIDS_BASE_)
#define _HOGP_HDL_OFFSET_MOUSE_                         (_HOGP_HDL_OFFSET_KB_+SIZE_ATTRIBUTE_HIDS_KEYBOARD_)
#define _HOGP_HDL_OFFSET_CONSUMER_                      (_HOGP_HDL_OFFSET_MOUSE_+SIZE_ATTRIBUTE_HIDS_MOUSE_)
#define _HOGP_HDL_OFFSET_RPT_REF_                       (_HOGP_HDL_OFFSET_CONSUMER_+SIZE_ATTRIBUTE_HIDS_COMSUMER_)

#define SIZE_ATTRIBUTE_HIDS                             (\
                                                        SIZE_ATTRIBUTE_HIDS_BASE_+\
                                                        SIZE_ATTRIBUTE_HIDS_COMSUMER_+\
                                                        SIZE_ATTRIBUTE_HIDS_MOUSE_+\
                                                        SIZE_ATTRIBUTE_HIDS_KEYBOARD_+\
                                                        SIZE_ATTRIBUTE_HIDS_RPT_REF\
                                                        )

#ifdef _PROFILE_HOGP_MULTI_
#define SIZE_OF_ATT_VALUE_HID_OFFSET                    0
#else
#define SIZE_OF_ATT_VALUE_HID_OFFSET                    2
#endif

#ifdef _PROFILE_HOGP_MOUSE_
#define SIZE_OF_ATTRIBUTE_VALUE_MS                      (84-SIZE_OF_ATT_VALUE_HID_OFFSET)
#else
#define SIZE_OF_ATTRIBUTE_VALUE_MS                      0
#endif
#ifdef _PROFILE_HOGP_KEYBOARD_
#define SIZE_OF_ATTRIBUTE_VALUE_KB                      (56-SIZE_OF_ATT_VALUE_HID_OFFSET)
#else
#define SIZE_OF_ATTRIBUTE_VALUE_KB                      0
#endif
#ifdef _PROFILE_HOGP_COMSUMER_
#define SIZE_OF_ATTRIBUTE_VALUE_CS                      (25-SIZE_OF_ATT_VALUE_HID_OFFSET)
#else
#define SIZE_OF_ATTRIBUTE_VALUE_CS                      0
#endif
#else
#define _HOGP_HDL_OFFSET_BASE_                          _SERVICE_OFFSET_BASE_
#define SIZE_ATTRIBUTE_HIDS                             0
#endif      //#ifdef _PROFILE_HOGP_

#ifdef _PROFILE_HOGP_
#ifdef _PROFILE_HOGP_COMSUMER_
#define SIZE_ATTRIBUTE_BOND_HIDS_COMSUMER_              1
#else
#define SIZE_ATTRIBUTE_BOND_HIDS_COMSUMER_              0
#endif
#ifdef _PROFILE_HOGP_MOUSE_
#define SIZE_ATTRIBUTE_BOND_HIDS_MOUSE_                 2
#else
#define SIZE_ATTRIBUTE_BOND_HIDS_MOUSE_                 0
#endif
#ifdef _PROFILE_HOGP_KEYBOARD_
#define SIZE_ATTRIBUTE_BOND_HIDS_KEYBOARD_              2
#else
#define SIZE_ATTRIBUTE_BOND_HIDS_KEYBOARD_              0
#endif
#endif

#ifdef _PROFILE_HOGP_
#define SIZE_ATTRIBUTE_BOND_HIDS                        (\
                                                        SIZE_ATTRIBUTE_BOND_HIDS_COMSUMER_+\
                                                        SIZE_ATTRIBUTE_BOND_HIDS_MOUSE_+\
                                                        SIZE_ATTRIBUTE_BOND_HIDS_KEYBOARD_\
                                                        )
#else
#define SIZE_ATTRIBUTE_BOND_HIDS                        0
#endif  //#ifdef _PROFILE_HOGP_


//////////////////////////////TaoBao///////////////////////////////////
#ifdef _PROFILE_TAOBAO_
#define SIZE_ATTRIBUTE_TAOBAO    6
#else
#define SIZE_ATTRIBUTE_TAOBAO    0
#endif
//////////////////////////////TaoBao///////////////////////////////////
//////////////////////////////WeChat///////////////////////////////////
#ifdef _PROFILE_WECHAT_
#define SIZE_ATTRIBUTE_WECHAT    8
#else
#define SIZE_ATTRIBUTE_WECHAT    0
#endif
//////////////////////////////WeChat///////////////////////////////////
//////////////////////////////WeChat_SimpleMode////////////////////////
#ifdef _PROFILE_WECHAT_SIMPLE_MODE_
#define SIZE_ATTRIBUTE_WECHAT_SIMPLE_MODE    6
#else
#define SIZE_ATTRIBUTE_WECHAT_SIMPLE_MODE    0
#endif
//////////////////////////////WeChat_SimpleMode////////////////////////
//////////////////////////////6UUID///////////////////////////////////
#ifdef _PROFILE_USER_DEFINE_01_
#define SIZE_ATTRIBUTE_USER_DEFINE_01    13
#else
#define SIZE_ATTRIBUTE_USER_DEFINE_01    0
#endif

////////////////////////////TEMPERATYRE///////////////////////////////
#ifdef _PROFILE_USER_TEMPERTURE_
#define SIZE_ATTRIBUTE_TEMPERTURE_MODE    15 
#else
#define SIZE_ATTRIBUTE_TEMPERTURE_MODE    0
#endif

//////////////////////////////6UUID///////////////////////////////////
//////////////////////////////GLS//////////////////////////////////////
#ifdef _PROFILE_GLS_
#define SIZE_ATTRIBUTE_GLS               12
#else
#define SIZE_ATTRIBUTE_GLS               0
#endif
//////////////////////////////GLS//////////////////////////////////////

//////////////////////////////TaoBao+WeChat+6UUID///////////////////////////////////
#define _TAOBAO_HDL_OFFSET_BASE_                 _HOGP_HDL_OFFSET_BASE_ + SIZE_ATTRIBUTE_HIDS
#define _WECHAT_HDL_OFFSET_BASE_                 _HOGP_HDL_OFFSET_BASE_ + SIZE_ATTRIBUTE_HIDS +	SIZE_ATTRIBUTE_TAOBAO
#define _WECHAT_SIMPLE_MODE_HDL_OFFSET_BASE_     _HOGP_HDL_OFFSET_BASE_ + SIZE_ATTRIBUTE_HIDS +	SIZE_ATTRIBUTE_TAOBAO + SIZE_ATTRIBUTE_WECHAT
#define _UDF01S_HDL_OFFSET_BASE_                 _HOGP_HDL_OFFSET_BASE_ + SIZE_ATTRIBUTE_HIDS +	SIZE_ATTRIBUTE_TAOBAO + SIZE_ATTRIBUTE_WECHAT + SIZE_ATTRIBUTE_WECHAT_SIMPLE_MODE
#define _TEMPERTURE_HDL_OFFSET_BASE_             _HOGP_HDL_OFFSET_BASE_ + SIZE_ATTRIBUTE_HIDS +	SIZE_ATTRIBUTE_TAOBAO + SIZE_ATTRIBUTE_WECHAT + SIZE_ATTRIBUTE_WECHAT_SIMPLE_MODE + SIZE_ATTRIBUTE_USER_DEFINE_01 
#define _GLS_HDL_OFFSET_BASE_                    _HOGP_HDL_OFFSET_BASE_ + SIZE_ATTRIBUTE_HIDS +	SIZE_ATTRIBUTE_TAOBAO + SIZE_ATTRIBUTE_WECHAT + SIZE_ATTRIBUTE_WECHAT_SIMPLE_MODE + SIZE_ATTRIBUTE_USER_DEFINE_01 + SIZE_ATTRIBUTE_TEMPERTURE_MODE
 

//////////////////////////////TaoBao+WeChat+6UUID///////////////////////////////////

#define SIZE_ATTRIBUTE_SERVER_BOND    (1  + SIZE_ATTRIBUTE_BOND_HIDS)
#define SIZE_ATTRIBUTE_SERVER         (56 + SIZE_ATTRIBUTE_HIDS + SIZE_ATTRIBUTE_TAOBAO + SIZE_ATTRIBUTE_WECHAT + SIZE_ATTRIBUTE_WECHAT_SIMPLE_MODE + SIZE_ATTRIBUTE_USER_DEFINE_01 + SIZE_ATTRIBUTE_GLS + SIZE_ATTRIBUTE_TEMPERTURE_MODE)
/*********************************************************************
** Extern Code
*********************************************************************/
extern const uint8_t code ADV_DATA_INITIAL[32];
extern const uint8_t code SCAN_RESPONSE_DATA_INITIAL[32];
extern code uint8_t code *ATTRIBUTE_SERVER[SIZE_ATTRIBUTE_SERVER];
extern code uint8_t *ATTRIBUTE_SERVER_param[SIZE_ATTRIBUTE_SERVER];
extern code uint8_t code *ATTRIBUTE_SERVER_PERMISSION[SIZE_ATTRIBUTE_SERVER];
extern code uint8_t code *ATTRIBUTE_SERVER_BOND[SIZE_ATTRIBUTE_SERVER_BOND];
extern code uint8_t *ATTRIBUTE_SERVER_BOND_PARAM[SIZE_ATTRIBUTE_SERVER_BOND];

extern const uint8_t code ATT_HDL_OTA_OTA_DATA_INIT[];
extern uint8_t xdata att_HDL_OTA_OTA_DATA[];
extern uint8_t xdata att_HDL_OTA_OTA_DATA_CLIENT_CHARACTERISTIC_CONFIGURATION[];
extern const uint8_t code ATT_HDL_OTA_OTA_CMD_CONTROL_POINT_INIT[];
extern uint8_t xdata att_HDL_OTA_OTA_CMD_CONTROL_POINT[];
extern uint8_t xdata att_HDL_OTA_OTA_CMD_CONTROL_POINT_CLIENT_CHARACTERISTIC_CONFIGURATION[];
extern const uint8_t code ATT_HDL_OTA_DATA_ERROR_STATUS_INIT[];
extern uint8_t xdata att_HDL_OTA_DATA_ERROR_STATUS[];
extern uint8_t xdata att_HDL_OTA_DATA_ERROR_STATUS_CLIENT_CHARACTERISTIC_CONFIGURATION[];

///************************** 0xFEBA is for OTA UUIDs *********************************/
#define GATT_SPEC_OTA_SERVICES                              0xFE
#define GATT_SPEC_OTA_SERVICES_OTA                          0xBA
///************************************************************************************/

///*********** 0xFA00 through 0xFAFF are for OTA Types ************/
#define GATT_SPEC_OTA_CHARACTERISTIC                        0xFA
#define GATT_SPEC_OTA_CHARACTERISTIC_OTA_DATA               0x10
#define GATT_SPEC_OTA_CHARACTERISTIC_OTA_CMD                0x11
///************************************************************************************/
#ifdef _PROFILE_HOGP_
#ifdef _PROFILE_HOGP_MOUSE_
extern uint8_t xdata att_HDL_HIDS_REPORT_MSI[];
extern const uint8_t code ATT_HDL_HIDS_REPORT_MSI_INIT[];
extern uint8_t xdata att_HDL_HIDS_REPORT_MSI_CLIENT_CHARACTERISTIC_CONFIGURATION[];
#endif

#ifdef _PROFILE_HOGP_KEYBOARD_
extern uint8_t xdata att_HDL_HIDS_REPORT_KBI[];
extern const uint8_t code ATT_HDL_HIDS_REPORT_KBI_INIT[];
extern uint8_t xdata att_HDL_HIDS_REPORT_KBI_CLIENT_CHARACTERISTIC_CONFIGURATION[];
#endif

#ifdef _PROFILE_HOGP_COMSUMER_
extern uint8_t xdata att_HDL_HIDS_REPORT_CSI[];
extern const uint8_t code ATT_HDL_HIDS_REPORT_CSI_INIT[];
extern uint8_t xdata att_HDL_HIDS_REPORT_CSI_CLIENT_CHARACTERISTIC_CONFIGURATION[];
#endif
#endif

#ifdef _PROFILE_WECHAT_
extern const uint8_t code ATT_HDL_WECHAT_DATI_INIT[];
extern uint8_t xdata att_HDL_WECHAT_DATI[];
extern uint8_t xdata att_HDL_WECHAT_DATW[];
extern uint8_t xdata att_HDL_WECHAT_DATI_MEASUREMENT_CLIENT_CHARACTERISTIC_CONFIGURATION[];
#ifdef _PROFILE_WECHAT_SIMPLE_MODE_
extern const uint8_t code ATT_HDL_WECHAT_SIMPLEMODE_DATRI_INIT[];
extern uint8_t xdata att_HDL_WECHAT_SIMPLEMODE_DATRI[];
extern uint8_t xdata att_HDL_WECHAT_SIMPLEMODE_DATRI_CLIENT_CHARACTERISTIC_CONFIGURATION[];
extern const uint8_t code ATT_HDL_WECHAT_SIMPLEMODE_DATRWI_INIT[];
extern uint8_t xdata att_HDL_WECHAT_SIMPLEMODE_DATRWI[];
extern uint8_t xdata att_HDL_WECHAT_SIMPLEMODE_DATRWI_CLIENT_CHARACTERISTIC_CONFIGURATION[];
#endif
#endif

#ifdef _PROFILE_USER_DEFINE_01_
extern const uint8_t code ATT_HDL_USER_DEFINE_01_DATAN01_INIT[];
extern uint8_t xdata att_HDL_USER_DEFINE_01_DATAN01[];
extern uint8_t xdata att_HDL_USER_DEFINE_01_DATAW01[];
extern uint8_t xdata att_HDL_USER_DEFINE_01_DATAN01_CLIENT_CHARACTERISTIC_CONFIGURATION[];

extern const uint8_t code ATT_HDL_USER_DEFINE_01_DATAN02_INIT[];
extern uint8_t xdata att_HDL_USER_DEFINE_01_DATAN02[];
extern uint8_t xdata att_HDL_USER_DEFINE_01_DATAW02[];
extern uint8_t xdata att_HDL_USER_DEFINE_01_DATAN02_CLIENT_CHARACTERISTIC_CONFIGURATION[];
#endif

//??????????
#ifdef _PROFILE_USER_TEMPERTURE_
//UUID : 0xFB01 Read & Write 
extern const uint8_t code ATT_HDL_USER_DEVICENAME_RW01_INIT[];
extern uint8_t xdata att_HDL_USER_DEVICENAME_RW01[];
extern const uint8_t code ATT_HDL_USER_DEVICENAME_CONFIGURATION_INIT[];
extern uint8_t xdata att_HDL_USER_DEVICENAME_CONFIGURATION[];

//UUID ??0xFB02 Notify
extern const uint8_t code ATT_HDL_USER_TEMPERTURE_N01_INIT[];
extern uint8_t xdata att_HDL_USER_TEMPERTURE_N01[];
extern const uint8_t code ATT_HDL_USER_TEMPERTURE_CONFIGURATION_INIT[];
extern uint8_t xdata att_HDL_USER_TEMPERTURE_CONFIGURATION[];

//UUID : 0xFB03 Write
extern const uint8_t code ATT_HDL_USER_COMMAND_W01_INIT[];
extern uint8_t xdata att_HDL_USER__COMMAND_W01[];
//UUID : 0xFB04 Notify
extern const uint8_t code ATT_HDL_USER_UPLOAD_N01_INIT[];
extern uint8_t xdata att_HDL_USER_UPLOAD_N01[];
extern const uint8_t code ATT_HDL_USER_UPLOAD_CONFIGURATION_INIT[];
extern uint8_t xdata att_HDL_USER_UPLOAD_CONFIGURATION[];
//UUID : 0xFB05 Read & Notify
extern const uint8_t code ATT_HDL_USER_STATUS_RN01_INIT[];
extern uint8_t xdata att_HDL_USER_STATUS_RN01[];
extern const uint8_t code ATT_HDL_USER_STATUS_CONFIGURATION_INIT[];
extern uint8_t xdata att_HDL_USER_STATUS_CONFIGURATION[];

#endif


#ifdef _PROFILE_TAOBAO_
extern const uint8_t code ATT_HDL_TAOBAO_DATI_INIT[];
extern uint8_t xdata att_HDL_TAOBAO_DATI[];
extern uint8_t xdata att_HDL_TAOBAO_DATW[];
extern uint8_t xdata att_HDL_TAOBAO_DATI_MEASUREMENT_CLIENT_CHARACTERISTIC_CONFIGURATION[];
#endif





#endif