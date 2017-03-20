#include "TIMs.h"
#include "defines.c"
void TIM6_Init(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	TIM6->CR1 |= TIM_CR1_ARPE;
	TIM6->DIER |= TIM_DIER_UIE;
	TIM6 -> ARR = 10000;//100;
	TIM6 -> PSC = 2097-1;//65530;//16000 - 1;
	NVIC_EnableIRQ(TIM6_IRQn);
	TIM6-> CR1 |= TIM_CR1_CEN;
}


//void TIM7_Init(){
//		RCC->APB1ENR |=  RCC_APB1ENR_TIM7EN ;
//		TIM7->CR1 |= TIM_CR1_OPM;
//		TIM7->PSC =  2096;
//}
//void while_timeout(){
//	while(!time_out);
//}

//void set_timeout(int t){
//	TIM7->ARR = t;
//	TIM7->EGR |= TIM_EGR_UG;
//	TIM7->SR &= !TIM_SR_UIF;
//	TIM7->CR1 |= TIM_CR1_CEN;
//}
//
//
//void reset_timer(){
//	TIM7->EGR |= TIM_EGR_UG;
//	TIM7->SR &= !TIM_SR_UIF;
//}

void TIM6_IRQHandler(void)
{
	LED_RED_PORT->ODR ^= LED_RED_PIN;
	TIM6 -> SR &= ~TIM_SR_UIF;
}


