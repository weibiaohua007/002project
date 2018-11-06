#ifndef _LCD_h_
#define _LCD_h_
/*---------------------------------------------//*/
#include "define.h"
/*---------------------------------------------//*/

	const uint8_t	code LCD_ConfigTab[]=
	{	0x1F , 
		0x83 ,
		0x0A , 
		0xCD , 
		0x1E ,
		0x00 ,
		0x00 ,
		0x00 , 
		0x00 ,
		0x00 ,
		0x00 , 
		0x00 ,
		0x84 ,//0x94 , 
		0xFF ,
		0xFF ,
		0x73 
	};

	const uint16_t code NumTable_4mux[] =
	{
		0x0E, //0
		0x00, //1
		0x4C, //2
		0x48, //3
		0x42, //4
		0x4A, //5
		0x4E, //6
		0x00, //7
		0x4E, //8
		0x42, //9
		0x40, //10 '-'
		0x0E, //11 'C'
		0x00, //12 ' '
		0x42, //13 o
		0xFF, //14 all
	};

	const uint16_t code NumTable_4mux1[] =
	{
		0x07, //0
		0x06, //1
		0x23, //2
		0x27, //3
		0x26, //4
		0x25, //5
		0x24, //6
		0x07, //7
		0x27, //8
		0x27, //9
		0x20, //10 '-'
		0x01, //11 'C'
		0x00, //12 ' '
		0x23, //13 o
		0xFF, //14 all
	};

	#define	LCD_ELCDAE0	0xFF
	#define	LCD_ELCDAE1	0x0F//0xFF
	#define	LCD_ELCDAE2	0x73
	#define	LCD_ELCDAE3	0x0C//0x0f

/************************************
* LCD control register
************************************/
	#define LB_LCDBCTL0_REG 0x20B9
	#define HB_LCDBCTL0_REG 0x20BA
	#define LB_LCDBVCTL_REG 0x20BB
	#define HB_LCDBVCTL_REG 0x20BC
	#define LCDM_S0_REG     0x20BD
	#define LCDM_S2_REG     0x20BE
	#define LCDM_S4_REG     0x20BF
	#define LCDM_S6_REG     0x20C0
	#define LCDM_S8_REG     0x20C1
	#define LCDM_S10_REG    0x20C2
	#define LCDM_S12_REG    0x20C3
	#define LCDM_S14_REG    0x20C4
	#define LCDM_S16_REG    0x20C5
	#define LCDM_S18_REG    0x20C6
	#define LCDM_S20_REG    0x20C7
	#define LCDM_S22_REG    0x20C8
	#define LCDM_S24_REG    0x20C9
	#define LCDM_S26_REG    0x20CA
	#define LCDM_S28_REG    0x20CB
	#define LCDM_S30_REG    0x20CC
	#define LCDM_S32_REG    0x20CD
	#define LCDM_S34_REG    0x20CE
	#define LCDM_S36_REG    0x20CF
	#define LCDM_S38_REG    0x20D0
	#define LCDM_S40_REG    0x20D1
	#define LCDM_S42_REG    0x20D2
	#define LCDM_S44_REG    0x20D3
	#define LCDM_S46_REG    0x20D4
	#define LCD_Misc_REG    0x20D5
	#define Test_Mux_REG    0x20D6
	#define LCDBBLKCTL_REG  0x20D7
	#define LCDBMEMCTL_REG  0x20D8
	#define LCDBM_S0_REG    0x20D9
	#define LCDBM_S2_REG    0x20DA
	#define LCDBM_S4_REG    0x20DB
	#define LCDBM_S6_REG    0x20DC
	#define LCDBM_S8_REG    0x20DD
	#define LCDBM_S10_REG   0x20DE
	#define LCDBM_S12_REG   0x20DF
	#define LCDBM_S14_REG   0x20E0
	#define LCDBM_S16_REG   0x20E1
	#define LCDBM_S18_REG   0x20E2
	#define LCDBM_S20_REG   0x20E3
	#define LCDBM_S22_REG   0x20E4
	#define LCDBM_S24_REG   0x20E5
	#define LCDBM_S26_REG   0x20E6
	#define LCDBM_S28_REG   0x20E7
	#define LCDBM_S30_REG   0x20E8
	#define LCDBM_S32_REG   0x20E9
	#define LCDBM_S34_REG   0x20EA
	#define LCDBM_S36_REG   0x20EB
	#define LCDBM_S38_REG   0x20EC
	#define LCDBM_S40_REG   0x20ED
	#define LCDBM_S42_REG   0x20EE
	#define LCDBM_S44_REG   0x20EF
	#define LCDBM_S46_REG   0x20F0
	#define LB_LCDBCTL1_REG 0x20F1
	#define HB_LCDBCTL1_REG 0x20F2
	#define LCDBIV_REG      0x20F3
	
	#define ELCDAE0_REG     0x20F4  
	#define ELCDAE1_REG     0x20F5
	#define ELCDAE2_REG     0x20F6
	#define ELCDAE3_REG     0x20F7
	#define LCD_Misc2_REG   0x20F8
	#define LCD_Misc3_REG   0x20F9
	#define	WUNIE   		0x20FA
	#define INTF		   	0x20FB
	
	#define LCD_CP_REG      0x20FC
	#define TCKG0_REG 	    0x20FE
	#define TCKG1_REG   	0x20FF

#endif