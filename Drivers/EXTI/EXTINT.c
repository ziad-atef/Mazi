#ifndef EXTI_SRC_PWM_C_
#define EXTI_SRC_PWM_C_

/*
********************************************************************
* // Authors: Donya Esawi  , Ahmed Ihab
* // Copy rights @2022
********************************************************************
*/

#include "EXTINT.h"

void _EXTINT_init(GPIO_TypeDef *PORT, uint32_t PIN, triggeringEdge interrupt_edge, state default_state, void (*intHandler)(void))
{

	__disable_irq();

	/**** Enable GPIO and AFIO clocks through RCC controller ****/
	// enable AFIO RCC: Alternate function IO clock enable
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

	// Enable GPIO_RCC
	if (PORT == PORTA)
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	if (PORT == PORTB)
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	if (PORT == PORTC)
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

	/***********************************************************/
	// AFIO_EXTICR1 register
	if (PIN < 4)
	{
		if (PORT == PORTA)
		{
			AFIO->EXTICR[0] &= ~(1 << (PIN * 4));
			AFIO->EXTICR[0] &= ~(1 << ((PIN * 4) + 1));
			AFIO->EXTICR[0] &= ~(1 << ((PIN * 4) + 2));
			AFIO->EXTICR[0] &= ~(1 << ((PIN * 4) + 3));
		}
		if (PORT == PORTB)
		{
			AFIO->EXTICR[0] |= (1 << (PIN * 4));
			AFIO->EXTICR[0] &= ~(1 << ((PIN * 4) + 1));
			AFIO->EXTICR[0] &= ~(1 << ((PIN * 4) + 2));
			AFIO->EXTICR[0] &= ~(1 << ((PIN * 4) + 3));
		}
		if (PORT == PORTC)
		{
			AFIO->EXTICR[0] &= ~(1 << (PIN * 4));
			AFIO->EXTICR[0] |= (1 << ((PIN * 4) + 1));
			AFIO->EXTICR[0] &= ~(1 << ((PIN * 4) + 2));
			AFIO->EXTICR[0] &= ~(1 << ((PIN * 4) + 3));
		}
	}
	// AFIO_EXTICR2 register
	if (PIN > 3 & PIN < 8)
	{
		if (PORT == PORTA)
		{
			AFIO->EXTICR[1] &= ~(1 << ((PIN - 4) * 4));
			AFIO->EXTICR[1] &= ~(1 << (((PIN - 4) * 4) + 1));
			AFIO->EXTICR[1] &= ~(1 << (((PIN - 4) * 4) + 2));
			AFIO->EXTICR[1] &= ~(1 << (((PIN - 4) * 4) + 3));
		}
		if (PORT == PORTB)
		{
			AFIO->EXTICR[1] |= (1 << ((PIN - 4) * 4));
			AFIO->EXTICR[1] &= ~(1 << (((PIN - 4) * 4) + 1));
			AFIO->EXTICR[1] &= ~(1 << (((PIN - 4) * 4) + 2));
			AFIO->EXTICR[1] &= ~(1 << (((PIN - 4) * 4) + 3));
		}
		if (PORT == PORTC)
		{
			AFIO->EXTICR[1] &= ~(1 << ((PIN - 4) * 4));
			AFIO->EXTICR[1] |= (1 << (((PIN - 4) * 4) + 1));
			AFIO->EXTICR[1] &= ~(1 << (((PIN - 4) * 4) + 2));
			AFIO->EXTICR[1] &= ~(1 << (((PIN - 4) * 4) + 3));
		}
	}
	// AFIO_EXTICR3 register
	if (PIN > 8 & PIN < 12)
	{
		if (PORT == PORTA)
		{
			AFIO->EXTICR[2] &= ~(1 << ((PIN - 8) * 4));
			AFIO->EXTICR[2] &= ~(1 << (((PIN - 8) * 4) + 1));
			AFIO->EXTICR[2] &= ~(1 << (((PIN - 8) * 4) + 2));
			AFIO->EXTICR[2] &= ~(1 << (((PIN - 8) * 4) + 3));
		}
		if (PORT == PORTB)
		{
			AFIO->EXTICR[2] |= (1 << ((PIN - 8) * 4));
			AFIO->EXTICR[2] &= ~(1 << (((PIN - 8) * 4) + 1));
			AFIO->EXTICR[2] &= ~(1 << (((PIN - 8) * 4) + 2));
			AFIO->EXTICR[2] &= ~(1 << (((PIN - 8) * 4) + 3));
		}
		if (PORT == PORTC)
		{
			AFIO->EXTICR[2] &= ~(1 << ((PIN - 8) * 4));
			AFIO->EXTICR[2] |= (1 << (((PIN - 8) * 4) + 1));
			AFIO->EXTICR[2] &= ~(1 << (((PIN - 8) * 4) + 2));
			AFIO->EXTICR[2] &= ~(1 << (((PIN - 8) * 4) + 3));
		}
	}
	// AFIO_EXTICR4 register
	if (PIN > 11 & PIN < 16)
	{
		if (PORT == PORTA)
		{
			AFIO->EXTICR[3] &= ~(1 << ((PIN - 12) * 4));
			AFIO->EXTICR[3] &= ~(1 << (((PIN - 12) * 4) + 1));
			AFIO->EXTICR[3] &= ~(1 << (((PIN - 12) * 4) + 2));
			AFIO->EXTICR[3] &= ~(1 << (((PIN - 12) * 4) + 3));
		}
		if (PORT == PORTB)
		{
			AFIO->EXTICR[3] |= (1 << ((PIN - 12) * 4));
			AFIO->EXTICR[3] &= ~(1 << (((PIN - 12) * 4) + 1));
			AFIO->EXTICR[3] &= ~(1 << (((PIN - 12) * 4) + 2));
			AFIO->EXTICR[3] &= ~(1 << (((PIN - 12) * 4) + 3));
		}
		if (PORT == PORTC)
		{
			AFIO->EXTICR[3] &= ~(1 << ((PIN - 12) * 4));
			AFIO->EXTICR[3] |= (1 << (((PIN - 12) * 4) + 1));
			AFIO->EXTICR[3] &= ~(1 << (((PIN - 12) * 4) + 2));
			AFIO->EXTICR[3] &= ~(1 << (((PIN - 12) * 4) + 3));
		}
	}

	// Unmask the interrupt
	EXTI->IMR |= (1 << PIN);
	// set whether falling edge or rising edge
	if (interrupt_edge == FALLING)
	{
		EXTI->FTSR |= (1 << PIN);
		EXTI->RTSR &= ~(1 << PIN);
	}
	else if (interrupt_edge == RISING)
	{
		EXTI->RTSR |= (1 << PIN);
		EXTI->FTSR &= ~(1 << PIN);
	}
	else if (interrupt_edge == ON_CHANGE)
	{
		EXTI->RTSR |= (1 << PIN);
		EXTI->FTSR |= (1 << PIN);
	}
	// set interrupt line to input pull_up
	if (default_state == PULL_UP)
	{
		GPIO_TYPE gp = {
			.port = PORT,
			.pin = PIN,
			.mode = INPUT_MODE,
			.mode_type = INPUT_PU_PD,
			.speed = SPEED_50MHZ};
		gpio_init(gp);
	}
	else if (default_state == PULL_DOWN)
	{ // needs to change
		GPIO_TYPE gp = {
			.port = PORT,
			.pin = PIN,
			.mode = INPUT_MODE,
			.mode_type = INPUT_PU_PD,
			.speed = SPEED_50MHZ};
		gpio_init(gp);
	}
	// Enable the global interrupt function
	switch (PIN)
	{ // choose IRQ  based on the EXTI_LINE that this PIN belongs to
	case 0:
		NVIC_EnableIRQ(EXTI0_IRQn);
		EXTI_Handler[0] = intHandler;
		break;
	case 1:
		NVIC_EnableIRQ(EXTI1_IRQn);
		EXTI_Handler[1] = intHandler;
		break;
	case 2:
		NVIC_EnableIRQ(EXTI2_IRQn);
		EXTI_Handler[2] = intHandler;
		break;
	case 3:
		NVIC_EnableIRQ(EXTI3_IRQn);
		EXTI_Handler[3] = intHandler;
		break;
	case 4:
		NVIC_EnableIRQ(EXTI4_IRQn);
		EXTI_Handler[4] = intHandler;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_EnableIRQ(EXTI9_5_IRQn);
		EXTI_Handler[5] = intHandler;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_EnableIRQ(EXTI15_10_IRQn);
		EXTI_Handler[6] = intHandler;
		break;
	}

	__enable_irq();
}

void EXTI0_IRQHandler()
{
	EXTI->PR |= EXTI_PR_PR0;
	(EXTI_Handler[0])();
}
void EXTI1_IRQHandler()
{
	EXTI->PR |= EXTI_PR_PR1;
	(EXTI_Handler[1])();
}
void EXTI2_IRQHandler()
{
	EXTI->PR |= EXTI_PR_PR2;
	(EXTI_Handler[2])();
}
void EXTI3_IRQHandler()
{
	EXTI->PR |= EXTI_PR_PR3;
	(EXTI_Handler[3])();
}
void EXTI4_IRQHandler()
{
	EXTI->PR |= EXTI_PR_PR4;
	(EXTI_Handler[4])();
}
void EXTI9_5_IRQHandler()
{
	EXTI->PR |= EXTI_PR_PR5;
	EXTI->PR |= EXTI_PR_PR6;
	EXTI->PR |= EXTI_PR_PR7;
	EXTI->PR |= EXTI_PR_PR8;
	EXTI->PR |= EXTI_PR_PR9;
	(EXTI_Handler[5])();
}

void EXTI15_10_IRQHandler()
{
	EXTI->PR |= EXTI_PR_PR10;
	EXTI->PR |= EXTI_PR_PR11;
	EXTI->PR |= EXTI_PR_PR12;
	EXTI->PR |= EXTI_PR_PR14;
	EXTI->PR |= EXTI_PR_PR15;
	(EXTI_Handler[6])();
}
#endif
