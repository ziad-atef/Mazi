#include "Includes/stm32/stm32f10x.h"

#include "EXTINT.h"
void delay(uint16_t milli);
void Handler();
void Handler2();
int signal = 0;
int signal2 = 0;
int main(void)
{
	init_GP(PA, 0, IN, I_PP);
	init_GP(PA, 8, IN, I_PP);
	init_GP(PC, 13, OUT50, O_GP_PP);
	init_GP(PA, 12, OUT50, O_GP_PP);
	init_GP(PB, 5, OUT50, O_GP_PP);

	/*__disable_irq();
	AFIO->EXTICR[0] = 0x00; /// Activating the interrupts for the Port A PIN 0
	EXTI->IMR |= 1; /// Enable the interrupt for EXTI0
	EXTI->RTSR |= 1; /// Generate a system interrupt at the rising edge
	NVIC_EnableIRQ(EXTI1_IRQn); // Enable the global interrupt function
	__enable_irq();*/

	_EXTINT_init(PA, 0, RISING, PULL_UP, Handler);
	_EXTINT_init(PA, 8, RISING, PULL_UP, Handler2);
	while (1)
	{
		W_GP(PA, 12, signal);
		if (signal) /// Checking status of PIN ! portA
		{
			// delay(500);
			toggle_GP(PC, 13); /// Toggle the PIN state
			delay(500);
		}
		else
		{
			W_GP(PC, 13, 1); /// Set the PIN 13 port C high
		}

		if (signal2) /// Checking status of PIN ! portA
		{
			// delay(500);
			toggle_GP(PB, 5); /// Toggle the PIN state
			delay(500);
		}
		else
		{
			W_GP(PB, 5, 1); /// Set the PIN 13 port C high
		}
	}
}

void Handler() // Interrupt Handler function
{
	if (signal)
	{
		signal = 0;
	}
	else
	{
		signal = 1;
	}
}

void Handler2() // Interrupt Handler function
{
	if (signal2)
	{
		signal2 = 0;
	}
	else
	{
		signal2 = 1;
	}
}

void delay(uint16_t milli)
{
	RCC->APB1ENR |= (1 << 1);

	TIM3->CNT = 0;

	TIM3->PSC = 60000 - 1;

	TIM3->ARR = milli;

	TIM3->CR1 |= 0x8;

	TIM3->CR1 |= 1;
	while (TIM3->CR1 & 1)
	{
	}
}
