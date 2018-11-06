/*****************************************************************************
**               AMICCOM Electronics Corporation Document                   **
**          Copyright (c) 2011-2014 AMICCOM Electronics Corporation         **
**                                                                          **
**      A3,1F,No.1, Li-Hsin 1th Road, Science_Based Industrid Park,         **
**                       Hsin_Chu City, 300, Taiwan, ROC.                   **
**                 Tel: 886-3-5785818   Fax: 886-3-5785819                  **
**         E-mail:info@amiccom.com.tw  http: //www.amiccom.com.tw           **
*****************************************************************************/
#ifndef _OTA_H_
#define _OTA_H_

/*--------------------------------------------------------------------------*/
/* INCLUDE FILE                                                             */
/*--------------------------------------------------------------------------*/
#include "..\include\define.h"

/*--------------------------------------------------------------------------*/
/* CONSTANT DECLARATION                                                     */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* MACRO DEFINITION                                                         */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* TYPE DEFINITION                                                          */
/*--------------------------------------------------------------------------*/

typedef enum
{
    OTA_UPDATING,
    OTA_SUCCESSFUL,
    OTA_COUNT_MAX,
    OTA_NOT_ENABLE
}TE_OTA_SPEEDSTATUS;

/*--------------------------------------------------------------------------*/
/* LOCAL VARIABLES DEFINITION                                               */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* LOCAL FUNCTION PROTOTYPE                                                 */ 
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* LOCAL FUNCTIONS DEFINITION                                               */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* GLOBAL VARIABLES DEFINITION                                              */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* GLOBAL FUNCTIONS DEFINITION                                              */ 
/*--------------------------------------------------------------------------*/
/**
 * @fn       void OTA_Initialize(void)
 * @brief    Initialize OTA module when system power on
 * @param    N/A
 * @return   N/A
**/
extern void OTA_Initialize(void);

/**
 * @fn       TE_OTA_SPEEDSTATUS OTA_UpdataSpeed(void)
 * @brief    Changing OTA download speeds (Range: 10ms ~ 318.75ms).
 * @param    N/A.
 * @return   0: Updating
 *           1: Pass
 *           2: Fail
 *           3: Notification or Indication isn't enable.
**/
extern TE_OTA_SPEEDSTATUS OTA_UpdataSpeed(void);

/**
 * @fn       void OTA_SetReceiveData(const uint16_t u8BufAddr, uint8_t u8Len)
 * @brief    Setting the received data for OTA_Process use.
 * @param    u16BufAddr [in] receive data address.
 * @param    u8Len [in] receive data length.
 * @return   N/A
**/
extern void OTA_SetReceiveData(const uint16_t, uint8_t);

/**
 * @fn       void OTA_Process(void)
 * @brief    OTA main loop.
 * @param    N/A.
 * @return   N/A
**/
extern void OTA_Process(void);

#endif