#include "Clock.h"


void Clock_init(){
//	  FLASH->ACR = FLASH_ACR_ACC64;
//	  FLASH->ACR|=FLASH_ACR_LATENCY;
//	  FLASH->ACR|=FLASH_ACR_PRFTEN;

	RCC -> CR |= RCC_CR_HSION;
	while(!(RCC->CR&RCC_CR_HSIRDY));
	RCC -> CFGR |= RCC_CFGR_SW_HSI;
}
