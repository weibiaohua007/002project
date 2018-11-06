/*****************************************************************************
**               AMICCOM Electronics Corporation Document                   **
**          Copyright (c) 2011-2014 AMICCOM Electronics Corporation         **
**                                                                          **
**      A3,1F,No.1, Li-Hsin 1th Road, Science_Based Industrid Park,         **
**                       Hsin_Chu City, 300, Taiwan, ROC.                   **
**                 Tel: 886-3-5785818   Fax: 886-3-5785819                  **
**         E-mail:info@amiccom.com.tw  http: //www.amiccom.com.tw           **
*****************************************************************************/
#ifndef _PROPRIETARY_H_
#define _PROPRIETARY_H_

/*--------------------------------------------------------------------------*/
/* INCLUDE FILE                                                             */
/*--------------------------------------------------------------------------*/
#include "..\include\define.h"

/*--------------------------------------------------------------------------*/
/* CONSTANT DECLARATION                                                     */
/*--------------------------------------------------------------------------*/

#define FUN_PROPRIETARY

/*--------------------------------------------------------------------------*/
/* MACRO DEFINITION                                                         */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* TYPE DEFINITION                                                          */
/*--------------------------------------------------------------------------*/
typedef enum
{
    PR_SUCCESS,
    PR_ERR_HANDLE,
    PR_ERR_RECALL,
    PR_ERR_NOINIT,
    PR_ERR_LACKOFTIME,
    PR_ERR_USING,
    PR_ERR_CHANNEL,
    PR_ERR_ID,
    PR_ERR_DATARATE,
    PR_ERR_TXLEN,
    PR_ERR_RXLEN,
    PR_ERR_TIMEOUT,
    PR_ERR_CRC,
}TE_PR_Code;

typedef enum
{
    DR500K_DV186K,  /*<< For A7105, Data rate <=500K, Deviation = 250K */
    DR1MB_DV250K,   /*<< Data rate < 1M, Deviation = 250K */
    DR1M_DV250K,    /*<< Data rate = 1M, Deviation = 250K */
    //DR2M_DV500K     /*<< Data rate = 2M, Deviation = 500K */
}TE_PR_DR_Item;

typedef struct
{
    TE_PR_DR_Item   Prop_DRI;       /*<< Data rate item */
    uint8_t         Prop_SDR;       /*<< Setting "Data Rate = 1M/(Prop_SDR+1)", used in DR500K_DV186K and DR1MB_DV250K item */
    uint8_t         Prop_Ext;       /*<< RUF */
}TS_PR_DataRate;

typedef struct
{
    uint8_t*        Prop_ID;        /*<< The ID length must is four byte */
    TS_PR_DataRate  Prop_DR;        /*<< Data Rate = 1M/(Prop_DR + 1)) */
	uint8_t         Prop_TxWait;    /*<< Tx waitting (Unit: Prop_TxWait * 1us) */
    uint8_t         Prop_RxWS;      /*<< Rx window size (Unit: Prop_RxWS * 1ms) */
}TS_PR_Param;

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

#ifdef FUN_PROPRIETARY
extern uint8_t xdata g_RxCnt;
#endif

/*--------------------------------------------------------------------------*/
/* GLOBAL FUNCTIONS DEFINITION                                              */ 
/*--------------------------------------------------------------------------*/

#ifdef FUN_PROPRIETARY
void Prop_Initialize(void);
TE_PR_Code Prop_Create(TS_PR_Param*, void**);
TE_PR_Code Prop_Delete(void**);
TE_PR_Code Prop_Start(void*, uint8_t);
TE_PR_Code Prop_Stop(void*);
uint8_t Prop_RunTx(void* pvHandle, uint8_t* u8TxBuf, uint8_t u8TxLen);
uint8_t Prop_RunRx(void* pvHandle, uint8_t* pu8RxBuf, uint8_t u8RxLen);
void DisableRxWinS(void);
extern uint16_t Get_Interval_Time(void);
extern uint16_t Get_Interval_Time_Left(void);

uint8_t Prop_GetRFMode(void);
#endif

#endif