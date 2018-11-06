#ifndef _RCADC_H_
#define _RCADC_H_

#define RCADC0   0x20
#define RCADC1	 0x40
#define ABmode   0x00
#define BAmode	 0x10

#define RCADC24B_HIGH	0xFF
#define RCADC24B_MID	0xE0
#define RCADC24B_LOW	0x00
#define RCADC24B_MVT	0x00

#define RCADC24B_RACK	0x00
#define RCADC24B_CKS	0x01

#define RADCA00_REG	0x206A
#define RADCB00_REG	0x206D
#define RADCON0_REG	0x2072

extern sint16_t Get_temperature(void);

extern const sint32_t code TempTable1[111][2];

#endif