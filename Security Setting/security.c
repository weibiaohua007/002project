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
#include "security.h"

const uint8_t code RSP_PAIRING_REQUEST[] = {
    0x07, 0x00,                                          //PDU Length
    0x06, 0x00,                                          //Attribute Protocol
    0x02,                                                //Code
    IO_CAPABILITY_NOINPUT_NOOUTPUT,                      //IO Capabilities, User define
    //IO_CAPABILITY_DISPLAY_ONLY,                          //IO Capabilities, User define
    //IO_CAPABILITY_KEYBOARD_ONLY,                         //IO Capabilities, User define
    0x00,                                                //OOB data flag: OOB Authentication data not present
    (                                                    //AuthReq
        AUTHREQ_BONDING_FLAGS_BONDING |
        MITM_PROTECTION_NO|
        0x00
    ),
    0x10,                                                //Maximum Encryption Key Size: 16 Octets
    (                                                    //Initiator Key Distribution
        KEY_DISTRIBUTION_ENCKEY_1 |
        //KEY_DISTRIBUTION_IDKEY_1 |
        //KEY_DISTRIBUTION_SIGN_1 |
        0x00
    ),
    (                                                    //Responder Key Distribution
        KEY_DISTRIBUTION_ENCKEY_1 |
        //KEY_DISTRIBUTION_IDKEY_1 |
        //KEY_DISTRIBUTION_SIGN_1 |
        0x00
    )
};