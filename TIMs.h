#ifndef TIms_h
#define TIms_h
#include "stm32l053xx.h"
#include "stm32l0xx_hal.h"
void while_timeout();
void TIM6_Init(void);
void set_timeout(int t);
void while_timeout();
void while_time(int usec);







#else
#endif
