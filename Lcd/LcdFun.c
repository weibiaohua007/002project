#include "LcdFun.h"
#include "define.h"
#include "LCD.h"
#include "A8107.h"
//---------------------------------------------
void InitLCD(void)
{
	uint16_t  i;
	uint8_t LCD_IO_tmp; 

	//Port0's I/O  configured as input. According the [#define LCD_ELCDAE1] [#define LCD_ELCDAE2] @ A8105_LCD.h
    LCD_IO_tmp = 0;
    for(i=0;i<=3;i++)
    {
		LCD_IO_tmp<<=1;
		if((LCD_ELCDAE1<<i) & 0x80)
			LCD_IO_tmp  |= 0x01;
    }

    P0OE  &= ~( LCD_IO_tmp  | ((LCD_ELCDAE2 & 0x01) << 7 )| ((LCD_ELCDAE2 & 0x02) << 3 ) );
    P0PUN &= ~( LCD_IO_tmp  | ((LCD_ELCDAE2 & 0x01) << 7 ) | ((LCD_ELCDAE2 & 0x02) << 3 ) );
    P0WUN = 0xFF;

    //Port1's I/O  configured as input. According the [#define LCD_ELCDAE1] [#define LCD_ELCDAE3] @ A8105_LCD.h
    LCD_IO_tmp = 0;
    for(i=4;i<=7;i++)
    {
		LCD_IO_tmp<<=1;

		if((LCD_ELCDAE1<<i) & 0x80)
			LCD_IO_tmp  |= 0x01;
    }

    LCD_IO_tmp  |= ((LCD_ELCDAE3<<4)    & 0x80);
    LCD_IO_tmp  |= ((LCD_ELCDAE3<<3)    & 0x40);

    P1OE  &= ~LCD_IO_tmp;
    P1PUN &= ~LCD_IO_tmp;
    P1WUN = 0xFF;

    //Port2's I/O  configured as input. According the [#define LCD_ELCDAE0] @ A8105_LCD.h
    P2OE  &= ~LCD_ELCDAE0;
    P2PUN &= ~LCD_ELCDAE0;
    P2WUN = 0xFF;

    //Port3's I/O  configured as input. According the [#define LCD_ELCDAE3] @ A8105_LCD.h
    P3OE  &= ~(LCD_ELCDAE3 & 0x03);
    P3PUN &= ~(LCD_ELCDAE3 & 0x03);
    P3WUN = 0xFF;
    
    //   Setting I/O as COM or Segment analog input.
    XBYTE[ELCDAE0_REG] = LCD_ELCDAE0;
    XBYTE[ELCDAE1_REG] = LCD_ELCDAE1;   
    XBYTE[ELCDAE2_REG] = LCD_ELCDAE2;   
    XBYTE[ELCDAE3_REG] = LCD_ELCDAE3;

    //LCD config
    for(i=LB_LCDBCTL0_REG;i<=HB_LCDBVCTL_REG;i++)
        XBYTE[i] = LCD_ConfigTab[i-LB_LCDBCTL0_REG];

    for(i=LCDM_S0_REG;i<=LCDM_S46_REG;i++)
		XBYTE[i] = 0x00;

    for(i=LCD_Misc_REG;i<=LCDBMEMCTL_REG;i++)
        XBYTE[i] = LCD_ConfigTab[(i-LB_LCDBCTL0_REG)-0x0018];

    for(i=LCDBM_S0_REG;i<=LCDBM_S46_REG;i++)
        XBYTE[i] = 0x00;

    XBYTE[LB_LCDBCTL1_REG] = LCD_ConfigTab[8];
    XBYTE[HB_LCDBCTL1_REG] = LCD_ConfigTab[9];
    XBYTE[LCD_Misc2_REG] = LCD_ConfigTab[11];
    XBYTE[LCD_Misc3_REG] = LCD_ConfigTab[12];
}
//---------------------------------------------
void LCDON(uint8_t sel)
{
/*             ======
                    |____ENABLE:  LCD turn on.
                    |____DISABLE: LCD trun off.

    ex: LCD_ON(ENABLE);
        LCD_ON(DISABLE);
*/
     if(ENABLE == sel)
     {
        XBYTE[LCD_Misc_REG]    = (LCD_ConfigTab[4] & 0xFE);  //LCDOFF off =0
        XBYTE[LB_LCDBVCTL_REG] = (LCD_ConfigTab[2] | 0x08);  //Charge pump  on
        XBYTE[LB_LCDBCTL0_REG] = (LCD_ConfigTab[0] & 0x7F) | 0x07;  //LCD on
        XBYTE[HB_LCDBVCTL_REG] = (LCD_ConfigTab[3] | 0x01);  //VLCDx  on
     }
     else
     {
        XBYTE[LB_LCDBCTL0_REG] = LCD_ConfigTab[0];  //LCD off
        XBYTE[LB_LCDBVCTL_REG] = LCD_ConfigTab[2];  //Charge pump  off
        XBYTE[HB_LCDBVCTL_REG] = (LCD_ConfigTab[3]|0x01);  //VLCDx  off
        XBYTE[LCD_Misc_REG]    = LCD_ConfigTab[4];  //LCDOFF off
     }
}
//---------------------------------------------
void Display_4mux(uint8_t position, uint8_t Num)
{
	uint8_t NumValue , NumValue1;
	
	NumValue	= NumTable_4mux[Num];
	NumValue1 	= NumTable_4mux1[Num];

	switch (position)
	{
		case 1:
			XBYTE[LCDM_S14_REG] = NumValue;
			XBYTE[LCDBM_S14_REG] = NumValue;

			XBYTE[LCDM_S16_REG] = NumValue1;
			XBYTE[LCDBM_S16_REG] = NumValue1;
			break;

		case 2:
			XBYTE[LCDM_S12_REG] = NumValue;
			XBYTE[LCDBM_S12_REG] = NumValue;

			XBYTE[LCDM_S18_REG] = NumValue1;
			XBYTE[LCDBM_S18_REG] = NumValue1;
			break;

		case 3:
			XBYTE[LCDM_S10_REG] = NumValue;
			XBYTE[LCDBM_S10_REG] = NumValue;

			XBYTE[LCDM_S20_REG] = NumValue1;
			XBYTE[LCDBM_S20_REG] = NumValue1;
			break;

		case 4:
			XBYTE[LCDM_S8_REG] = NumValue;
			XBYTE[LCDBM_S8_REG] = NumValue;

			XBYTE[LCDM_S22_REG] = NumValue1;
			XBYTE[LCDBM_S22_REG] = NumValue1;
			break;
		case 5:
			XBYTE[LCDM_S6_REG] = NumValue;
			XBYTE[LCDBM_S6_REG] = NumValue;

			XBYTE[LCDM_S24_REG] = NumValue1;
			XBYTE[LCDBM_S24_REG] = NumValue1;
			break;

		case 6:
			XBYTE[LCDM_S4_REG] = NumValue;
			XBYTE[LCDBM_S4_REG] = NumValue;

			XBYTE[LCDM_S26_REG] = NumValue1;
			XBYTE[LCDBM_S26_REG] = NumValue1;
			break;
	}
}