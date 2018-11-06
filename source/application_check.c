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
#include "LibFunction.h"

/*************************************************************************
 *
 * ChkBLE_ATT_Chr_AcssRd_ByUser
 * Description:
 * 
 ************************************************************************/
uint8_t ChkBLE_ATT_Chr_AcssRd_ByUser(uint8_t *AddrAttHandle)
{
    uint8_t Rsp_Error;
    uint8_t *p;

    Rsp_Error = 0;

    //add for remove compiler warning 
    p = AddrAttHandle;

//    /******     Demo 01    ******/
//    //Check ATT_PERMISSION_HDL_UDF01S_UDATRW01_INIT & ATT_PERMISSION_HDL_DIS_SERIAL_NUMBER_STRING
//    p = &ATT_HDL_DIS_SERIAL_NUMBER_STRING[5];
//    if(AddrAttHandle == p)
//    {
//        Rsp_Error = ERR_CODE_ATT_APPLICATION_ERROR;
//    }

//    p = att_HDL_UDF01S_UDATRW01;
//    if(AddrAttHandle == p)
//    {
//        //Rsp_Error = 0;
//    }
//    /************End 01**********/
    
    return Rsp_Error;
}

/*************************************************************************
 *
 * ChkBLE_ATT_Chr_AcssWr_ByUser
 * Description:
 * 
 ************************************************************************/
uint8_t ChkBLE_ATT_Chr_AcssWr_ByUser(uint8_t *AddrAttHandle, uint8_t *wrDataBuf)
{
    uint8_t Rsp_Error;
    uint8_t *p;

    Rsp_Error = 0;

    //add for remove compiler warning 
    p = AddrAttHandle;
    p = wrDataBuf;
//
//    /******     Demo 02    ******/
//    //Check ATT_PERMISSION_HDL_UDF01S_UDATRW01_INIT & ATT_PERMISSION_HDL_DIS_SERIAL_NUMBER_STRING
//    //p = &ATT_HDL_DIS_SERIAL_NUMBER_STRING[5];     //Read only, not need to handle
//
//    p = att_HDL_UDF01S_UDATRW01;
//    if(AddrAttHandle == p)
//    {
//        if(*(wrDataBuf+1) != 0x05)
//        {
//            Rsp_Error = ERR_CODE_ATT_APPLICATION_ERROR;
//        }
//    }
//    /************End 02**********/

    return Rsp_Error;
}
