/*****************************************************************************
**               AMICCOM Electronics Corporation Document                   **
**          Copyright (c) 2011-2014 AMICCOM Electronics Corporation         **
**                                                                          **
**      A3,1F,No.1, Li-Hsin 1th Road, Science_Based Industrid Park,         **
**                       Hsin_Chu City, 300, Taiwan, ROC.                   **
**                 Tel: 886-3-5785818   Fax: 886-3-5785819                  **
**         E-mail:info@amiccom.com.tw  http: //www.amiccom.com.tw           **
*****************************************************************************/
#ifndef _IAP_H_
#define _IAP_H_

/*--------------------------------------------------------------------------*/
/* INCLUDE FILE                                                             */
/*--------------------------------------------------------------------------*/
#include "..\include\define.h"

/*--------------------------------------------------------------------------*/
/* CONSTANT DECLARATION                                                     */
/*--------------------------------------------------------------------------*/
#define IAP_SECTOR_SIZE                 0x100
#define IAP_BANK123_START               0x8000
#define IAP_BANK123_END                 0xFFFF

/*--------------------------------------------------------------------------*/
/* MACRO DEFINITION                                                         */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* TYPE DEFINITION                                                          */
/*--------------------------------------------------------------------------*/

typedef enum
{
    IAP_NORMAL,
    IAP_OTA
}TE_IAP_TYPE;

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
 * @fn       void IAP_Initialize(void)
 * @brief    Initialize IAP module when system power on
 * @param    N/A
 * @return   N/A
**/
extern void IAP_Initialize(void);

/**
 * @fn       void IAP_BankSwitch(uint8_t u8Bank)
 * @brief    Bank switch (Common Bank, Bank1, Bank2, Bank3)
 * @param    u8Bank [in] bank number (Common Bank = 0, Bank1 = 1, Bank2 = 2, Bank3 = 3).
 * @return   N/A
**/
extern void IAP_BankSwitch(uint8_t);

/**
 * @fn       IAP_Init(const TE_IAP_TYPE teType)
 * @brief    Change IAP type (0: normal mode, 1: for OTA) 
 * @param    teType [in] IAP tyep (0: normal mode, 1: for OTA).
 * @return   N/A
**/
extern void IAP_Init(const TE_IAP_TYPE teType);

/**
 * @fn       void IAP_Erase(const uint16_t u16Address)
 * @brief    Erase Flash.If you use this function, EA will briefly closed.
 * @param    u16Address [in] erase address.
 * @note     Each sector = 256 bytes.
 * @return   N/A
**/
extern void IAP_Erase(const uint16_t);

/**
 * @fn       void IAP_ReadData(const uint16_t u16Address, uint8_t* pu8Buf, uint16_t u16Length)
 * @brief    Read Flash Data.
 * @param    u16Address [in] Read address.
 * @param    pu8Buf [in] Get data buffer pointer.
 * @param    u16Length [in] Read data length.
 * @return   N/A
**/
extern void IAP_ReadData(const uint16_t, uint8_t*, uint16_t);

/**
 * @fn       void IAP_WriteData(const uint16_t u16Address, uint8_t* pu8Buf, uint16_t u16Length)
 * @brief    Write Flash Data.If you use this function, EA will briefly closed.
 * @param    u16Address [in] write address.
 * @param    pu8Buf [in] pointer of data buffer.
 * @param    u16Length [in] write data length.
 * @note     Please erase sector firstly if change the content in the flash memory.
 * @return   N/A
**/
extern void IAP_WriteData(const uint16_t u16Address, uint8_t* pu8Buf, uint16_t u16Length);
#endif




