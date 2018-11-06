#ifndef _LCDFUN_H_
#define	_LCDFUN_H_
#include "define.h"
/*---------------------------------------------//*/
void InitLCD(void);
void LCDON(uint8_t sel);
void Display_4mux(uint8_t position, uint8_t Num);
/*---------------------------------------------//*/
#endif