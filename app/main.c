#include "stm32l053xx.h"
#include "stm32l0xx_hal.h"
#include "defines.h"
#include "TIMs.h"
#include "Clock.h"
#include "LCD_func.h"

int main(void){

	Clock_init();
	TIM6_Init();

	RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
	RCC->IOPENR |= RCC_IOPENR_GPIOBEN;
	GPIO_InitTypeDef initSrtuct;

			initSrtuct.Mode = GPIO_MODE_OUTPUT_PP;
			initSrtuct.Pin = LED_RED_PIN;
			initSrtuct.Pull = GPIO_NOPULL;
			initSrtuct.Speed = GPIO_SPEED_HIGH;
			HAL_GPIO_Init(LED_RED_PORT, &initSrtuct);

			while_time(100);
			MTLCD_Init();
			while_time(1000);
			MTLCD_OnOff(1);
    while(1)
    {
    	int i;
    	for (i = 0;i<10;i++){
    		set_timeout(100);
    		while_timeout();
    	}
    	LED_RED_PORT->ODR ^= LED_RED_PIN;
    	MTLCD_CLR();
    }
}
