#include "PWM.h"

int main()
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	GPIOA->CRH = 0xBBBBBBBB;
	GPIOA->CRL = 0xBBBBBBBB;
	
	PWM_Init(PA8, 2, 60000);
	PWM_Start(PA8, 30000);
	
	PWM_Init(PA9, 2, 60000);
	PWM_Start(PA9, 10000);
	
	PWM_Init(PA10, 2, 60000);
	PWM_Start(PA10, 15000);
	
	PWM_Init(PA11, 2, 60000);
	PWM_Start(PA11, 1000);
	
	PWM_Init(PA0, 2, 60000);
	PWM_Start(PA0, 30000);
	
	PWM_Init(PA1, 2, 60000);
	PWM_Start(PA1, 10000);
	
	PWM_Init(PA2, 2, 60000);
	PWM_Start(PA2, 15000);
	
	PWM_Init(PA3, 2, 60000);
	PWM_Start(PA3, 1000);
	
	PWM_Init(PA6, 2, 60000);
	PWM_Start(PA6, 30000);
	
	PWM_Init(PA7, 2, 60000);
	PWM_Start(PA7, 10000);
	
	PWM_Init(PB0, 2, 60000);
	PWM_Start(PB0, 15000);
	
	PWM_Init(PB1, 2, 60000);
	PWM_Start(PB1, 1000);
	
	while(1)
	{
		
	}
	return 0;
}

/*
#include "stm32f10x.h"                 

int main()
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	
	
	GPIOA->CRH = 0xBBBBBBBB;
	GPIOA->CRL = 0xBBBBBBBB;
	
		
	TIM1->PSC = 2-1;									
	
	TIM1->ARR = 60000;									
	
	TIM1->CNT = 0;													
	
	TIM1->CCMR1 |= 0x60; 
	
	TIM1->CCER |= 1;
	TIM1->BDTR |= 0x8000;
	
	TIM1->CCR1 = 1000;
	
	TIM1->CR1 |= 1;
}
*/