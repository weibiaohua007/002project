/*****************************************************************************
**               AMICCOM Electronics Corporation Document                   **
**          Copyright (c) 2011-2015 AMICCOM Electronics Corporation         **
**                                                                          **
**      A3,1F,No.1, Li-Hsin 1th Road, Science_Based Industrid Park,         **
**                       Hsin_Chu City, 300, Taiwan, ROC.                   **
**                 Tel: 886-3-5785818   Fax: 886-3-5785819                  **
**         E-mail:info@amiccom.com.tw  http: //www.amiccom.com.tw           **
*****************************************************************************/
#ifndef _SECURITY_H_
#define _SECURITY_H_

/*********************************************************************
** Security Function Setting
*********************************************************************/
#define IO_CAPABILITY_DISPLAY_ONLY                      0x00
#define IO_CAPABILITY_KEYBOARD_ONLY                     0x02
#define IO_CAPABILITY_NOINPUT_NOOUTPUT                  0x03

#define AUTHREQ_BONDING_FLAGS_NO_BONDING                0x00
#define AUTHREQ_BONDING_FLAGS_BONDING                   0x01

#define MITM_PROTECTION_YES                             0x04
#define MITM_PROTECTION_NO                              0x00

#define KEY_DISTRIBUTION_ENCKEY_0                       0x00
#define KEY_DISTRIBUTION_ENCKEY_1                       0x01
#define KEY_DISTRIBUTION_IDKEY_0                        0x00
#define KEY_DISTRIBUTION_IDKEY_1                        0x02
#define KEY_DISTRIBUTION_SIGN_0                         0x00
#define KEY_DISTRIBUTION_SIGN_1                         0x04

#endif