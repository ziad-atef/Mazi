#include "../../Includes/stm32/stm32f10x.h"

void delay(uint16_t milli);

void delay(uint16_t milli)
{
	RCC->APB1ENR |= (1<<1);
	
	TIM3->CNT = 0;
	
	TIM3->PSC = 60000-1;	
	
	TIM3->ARR = milli;
	
	TIM3->CR1 |= 0x8;
	
	TIM3->CR1 |= 1;
	while(TIM3->CR1 & 1)
	{
	}
}

