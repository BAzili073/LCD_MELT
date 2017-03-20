#include "stm32l053xx.h"
#include "stm32l0xx_hal.h"
#define LED_RED_PORT GPIOA
#define LED_RED_PIN GPIO_PIN_5
#define LED_GREEN_PORT GPIOB
#define LED_GREEN_PIN GPIO_PIN_4

int main(void)
{
	RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
	RCC->IOPENR |= RCC_IOPENR_GPIOBEN;
	GPIO_InitTypeDef initSrtuct;

			initSrtuct.Mode = GPIO_MODE_OUTPUT_PP;
			initSrtuct.Pin = LED_RED_PIN;
			initSrtuct.Pull = GPIO_NOPULL;
			initSrtuct.Speed = GPIO_SPEED_HIGH;
			HAL_GPIO_Init(LED_RED_PORT, &initSrtuct);

			initSrtuct.Mode = GPIO_MODE_OUTPUT_PP;
			initSrtuct.Pin = LED_GREEN_PIN;
			initSrtuct.Pull = GPIO_NOPULL;
			initSrtuct.Speed = GPIO_SPEED_HIGH;
			HAL_GPIO_Init(LED_GREEN_PORT, &initSrtuct);
    while(1)
    {
    	LED_RED_PORT->ODR |= LED_RED_PIN;
    	LED_GREEN_PORT-> ODR |= LED_GREEN_PIN;
    }
}