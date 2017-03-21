#ifndef LCD_func_h
#define LCD_func_h
#include "stm32l053xx.h"
#include "stm32l0xx_hal.h"
void MTLCD_CLR();
void MTLCD_set_y(unsigned char pos_y);
void MTLCD_set_x(unsigned char pos_x);
void MTLCD_Init();
void MTLCD_DATA(unsigned char data);
void MTLCD_CMD(unsigned char cmd);
void MTLCD_OnOff(char status);






#else
#endif
