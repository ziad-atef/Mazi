
 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.c
 *
 * Description: Source file for STM32 Microcontroller - PWM Driver.
 *
 * Author: Ziad Atef
 ******************************************************************************/

#ifndef PWM_SRC_PWM_C_
#define PWM_SRC_PWM_C_


#include "../Inc/PWM.h"

/*******************************************************************************
* Service Name: PWM_Init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): PinNum    - Number of pin to be configured as PWM pin.
*									 Prescalar - Value used to determine the frequency of the timer
*															 Ftimer = Fclk/(prescalar+1).
*									 ReloadVal - Value at which counter resets.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initialize the pin specified to be a pwm pin.
*							 Beware when initializing pins that multiple pins initialize the
*							 same timer module:-
*							 -Timer1: PA8, PA9, PA10, PA11
*							 -Timer2:	PA0, PA1, PA2, PA3
*							 -Timer3:	PA6, PA7, PB0, PB1
********************************************************************************/
void PWM_Init(GPIO_TypeDef *port, uint32_t pinNumber, uint16 Prescalar, uint16 ReloadVal)
{
	if(port == GPIOA && (pinNumber == 8 || pinNumber == 9 || pinNumber == 10 || pinNumber == 11))
	{
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;			/* Enabling CLK for Timer1 Module*/

				TIM1->PSC = Prescalar-1;									/*
																									 Setting prescalar value for timer 1
																									 where Ftimer = Fclk/(Prescalar+1)
																								*/

				TIM1->ARR = ReloadVal;									/*
																									Setting Reload value at which Timer1
																									counter resets
																								*/

				TIM1->CNT = 0;													/*
																									Intializing Counter of Timer1
																									beware from multiple intializations
																								*/
		switch(pinNumber)
		{
		case 8:
			TIM1->CCMR1 |= TIM_CCMR1_PWM_MODE1_CH1; /*Setting channel 1 for PWM mode1*/
		break;
		case 9:
			TIM1->CCMR1 |= TIM_CCMR1_PWM_MODE1_CH2;	/*Setting channel 2 for PWM mode1*/
		break;
		case 10:
			TIM1->CCMR2 |= TIM_CCMR2_PWM_MODE1_CH3;	/*Setting channel 3 for PWM mode1*/
		break;
		case 11:
			TIM1->CCMR2 |= TIM_CCMR2_PWM_MODE1_CH4;	/*Setting channel 4 for PWM mode1*/
		break;

		default:
		break;
		}
		TIM1->BDTR |= 0x8000;
		TIM1->CR1 |= 1;
	}
	else if(port == GPIOA && (pinNumber == 0 || pinNumber == 1 || pinNumber == 2 || pinNumber == 3))
	{
		RCC->APB2ENR |= RCC_APB1ENR_TIM2EN;			/* Enabling CLK for Timer1 Module*/

		TIM2->PSC = Prescalar-1;									/*
																							 Setting prescalar value for timer 1
																							 where Ftimer = Fclk/(Prescalar+1)
																						*/

		TIM2->ARR = ReloadVal;									/*
																							Setting Reload value at which Timer1
																							counter resets
																						*/

		TIM2->CNT = 0;													/*
																							Intializing Counter of Timer1
																							beware from multiple intializations
																						*/
		switch(pinNumber)
		{
			case 0:
				TIM2->CCMR1 |= TIM_CCMR1_PWM_MODE1_CH1; /*Setting channel 1 for PWM mode1*/
			break;
			case 1:
				TIM2->CCMR1 |= TIM_CCMR1_PWM_MODE1_CH2;	/*Setting channel 2 for PWM mode1*/
			break;
			case 2:
				TIM2->CCMR2 |= TIM_CCMR2_PWM_MODE1_CH3;	/*Setting channel 3 for PWM mode1*/
			break;
			case 3:
				TIM2->CCMR2 |= TIM_CCMR2_PWM_MODE1_CH4;	/*Setting channel 4 for PWM mode1*/
			break;

			default:
			break;
		}

		TIM2->BDTR |= 0x8000;											/*Not needed*/
		TIM2->CR1 |= 1;
	}
	else if(
			(port == GPIOA && (pinNumber == 6 || pinNumber == 7)) ||
			(port == GPIOB && (pinNumber == 0 || pinNumber == 1)))
	{
		RCC->APB2ENR |= RCC_APB1ENR_TIM3EN;			/* Enabling CLK for Timer1 Module*/

		TIM3->PSC = Prescalar-1;									/*
																							 Setting prescalar value for timer 1
																							 where Ftimer = Fclk/(Prescalar+1)
																						*/

		TIM3->ARR = ReloadVal;									/*
																							Setting Reload value at which Timer1
																							counter resets
																						*/

		TIM3->CNT = 0;													/*
																							Intializing Counter of Timer1
																							beware from multiple intializations
		 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 */

		switch(pinNumber)
		{
			case 6:
				TIM3->CCMR1 |= TIM_CCMR1_PWM_MODE1_CH1; /*Setting channel 1 for PWM mode1*/
			break;
			case 7:
				TIM3->CCMR1 |= TIM_CCMR1_PWM_MODE1_CH2;	/*Setting channel 2 for PWM mode1*/
			break;
			case 0:
				TIM3->CCMR2 |= TIM_CCMR2_PWM_MODE1_CH3;	/*Setting channel 3 for PWM mode1*/
			break;
			case 1:
				TIM3->CCMR2 |= TIM_CCMR2_PWM_MODE1_CH4;	/*Setting channel 4 for PWM mode1*/
			break;

			default:
			break;
		}

		TIM3->BDTR |= 0x8000;                  /*Not needed*/
		TIM3->CR1 |= 1;
	}

}
//void PWM_Init(uint8 PinNum, uint16 Prescalar, uint16 ReloadVal)
//{
//	if( PinNum == PA8 || PinNum == PA9 || PinNum == PA10 || PinNum == PA11 )
//	{
//		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;			/* Enabling CLK for Timer1 Module*/
//
//		TIM1->PSC = Prescalar-1;									/*
//																							 Setting prescalar value for timer 1
//																							 where Ftimer = Fclk/(Prescalar+1)
//																						*/
//
//		TIM1->ARR = ReloadVal;									/*
//																							Setting Reload value at which Timer1
//																							counter resets
//																						*/
//
//		TIM1->CNT = 0;													/*
//																							Intializing Counter of Timer1
//																							beware from multiple intializations
//																						*/
//		switch(PinNum)
//		{
//			case PA8:
//				TIM1->CCMR1 |= TIM_CCMR1_PWM_MODE1_CH1; /*Setting channel 1 for PWM mode1*/
//			break;
//			case PA9:
//				TIM1->CCMR1 |= TIM_CCMR1_PWM_MODE1_CH2;	/*Setting channel 2 for PWM mode1*/
//			break;
//			case PA10:
//				TIM1->CCMR2 |= TIM_CCMR2_PWM_MODE1_CH3;	/*Setting channel 3 for PWM mode1*/
//			break;
//			case PA11:
//				TIM1->CCMR2 |= TIM_CCMR2_PWM_MODE1_CH4;	/*Setting channel 4 for PWM mode1*/
//			break;
//
//			default:
//			break;
//		}
//
//		TIM1->BDTR |= 0x8000;
//		TIM1->CR1 |= 1;
//	}
//	else if( PinNum == PA0 || PinNum == PA1 || PinNum == PA2 || PinNum == PA3 )
//	{
//		RCC->APB2ENR |= RCC_APB1ENR_TIM2EN;			/* Enabling CLK for Timer1 Module*/
//
//		TIM2->PSC = Prescalar-1;									/*
//																							 Setting prescalar value for timer 1
//																							 where Ftimer = Fclk/(Prescalar+1)
//																						*/
//
//		TIM2->ARR = ReloadVal;									/*
//																							Setting Reload value at which Timer1
//																							counter resets
//																						*/
//
//		TIM2->CNT = 0;													/*
//																							Intializing Counter of Timer1
//																							beware from multiple intializations
//																						*/
//		switch(PinNum)
//		{
//			case PA0:
//				TIM2->CCMR1 |= TIM_CCMR1_PWM_MODE1_CH1; /*Setting channel 1 for PWM mode1*/
//			break;
//			case PA1:
//				TIM2->CCMR1 |= TIM_CCMR1_PWM_MODE1_CH2;	/*Setting channel 2 for PWM mode1*/
//			break;
//			case PA2:
//				TIM2->CCMR2 |= TIM_CCMR2_PWM_MODE1_CH3;	/*Setting channel 3 for PWM mode1*/
//			break;
//			case PA3:
//				TIM2->CCMR2 |= TIM_CCMR2_PWM_MODE1_CH4;	/*Setting channel 4 for PWM mode1*/
//			break;
//
//			default:
//			break;
//		}
//
//		TIM2->BDTR |= 0x8000;											/*Not needed*/
//		TIM2->CR1 |= 1;
//	}
//	else if( PinNum == PA6 || PinNum == PA7 || PinNum == PB0 || PinNum == PB1 )
//	{
//		RCC->APB2ENR |= RCC_APB1ENR_TIM3EN;			/* Enabling CLK for Timer1 Module*/
//
//		TIM3->PSC = Prescalar-1;									/*
//																							 Setting prescalar value for timer 1
//																							 where Ftimer = Fclk/(Prescalar+1)
//																						*/
//
//		TIM3->ARR = ReloadVal;									/*
//																							Setting Reload value at which Timer1
//																							counter resets
//																						*/
//
//		TIM3->CNT = 0;													/*
//																							Intializing Counter of Timer1
//																							beware from multiple intializations
//																						*/
//		switch(PinNum)
//		{
//			case PA6:
//				TIM3->CCMR1 |= TIM_CCMR1_PWM_MODE1_CH1; /*Setting channel 1 for PWM mode1*/
//			break;
//			case PA7:
//				TIM3->CCMR1 |= TIM_CCMR1_PWM_MODE1_CH2;	/*Setting channel 2 for PWM mode1*/
//			break;
//			case PB0:
//				TIM3->CCMR2 |= TIM_CCMR2_PWM_MODE1_CH3;	/*Setting channel 3 for PWM mode1*/
//			break;
//			case PB1:
//				TIM3->CCMR2 |= TIM_CCMR2_PWM_MODE1_CH4;	/*Setting channel 4 for PWM mode1*/
//			break;
//
//			default:
//			break;
//		}
//
//		TIM3->BDTR |= 0x8000;                  /*Not needed*/
//		TIM3->CR1 |= 1;
//	}
//
//}

/*******************************************************************************
* Service Name: PWM_Start
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): PinNum - Pin number to start generating PWM signal on
*									 Duty   -	Duty cycle of the generated PWM signal
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Begin generating PWM signal with the specified duty cycle on the
*							 specified pin.
********************************************************************************/
void PWM_Start(GPIO_TypeDef *port, uint32_t pinNumber, uint16 Duty)
{
	if(port == GPIOA)
	{
		switch(pinNumber){
			case 0:
				TIM2->CCR1 = Duty;
				TIM2->CCER |= (1<<0);
				break;
			case 1:
				TIM2->CCR2 = Duty;
				TIM2->CCER |= (1<<1);
				break;
			case 2:
				TIM2->CCR3 = Duty;
				TIM2->CCER |= (1<<2);
				break;
			case 3:
				TIM2->CCR4 = Duty;
				TIM2->CCER |= (1<<3);
				break;
			case 6:
				TIM3->CCR1 = Duty;
				TIM3->CCER |= (1<<0);
				break;
			case 7:
				TIM3->CCR2 = Duty;
				TIM3->CCER |= (1<<1);
				break;
		}
	}
	else if(port == GPIOB)
	{
		switch(pinNumber){
			case 0:
				TIM3->CCR3 = Duty;
				TIM3->CCER |= (1<<2);
				break;
			case 1:
				TIM3->CCR4 = Duty;
				TIM3->CCER |= (1<<3);
				break;
			default:
				break;
			}
	}
}
//
//void PWM_Start(uint8 PinNum, uint16 Duty)
//{
//	switch(PinNum)
//	{
//		case PA0:
//			TIM2->CCR1 = Duty;
//			TIM2->CCER |= (1<<0);
//		break;
//		case PA1:
//			TIM2->CCR2 = Duty;
//			TIM2->CCER |= (1<<1);
//		break;
//		case PA2:
//			TIM2->CCR3 = Duty;
//			TIM2->CCER |= (1<<2);
//		break;
//		case PA3:
//			TIM2->CCR4 = Duty;
//			TIM2->CCER |= (1<<3);
//		break;
//		case PA6:
//			TIM3->CCR1 = Duty;
//			TIM3->CCER |= (1<<0);
//		break;
//		case PA7:
//			TIM3->CCR2 = Duty;
//			TIM3->CCER |= (1<<1);
//		break;
//		case PA8:
//			TIM1->CCR1 = Duty;
//			TIM1->CCER |= 0x1;
//		break;
//		case PA9:
//			TIM1->CCR2 = Duty;
//			TIM1->CCER |= 0x10;
//		break;
//		case PA10:
//			TIM1->CCR3 = Duty;
//			TIM1->CCER |= (1<<2);
//		break;
//		case PA11:
//			TIM1->CCR4 = Duty;
//			TIM1->CCER |= (1<<3);
//		break;
//		case PB0:
//			TIM3->CCR3 = Duty;
//			TIM3->CCER |= (1<<2);
//		break;
//		case PB1:
//			TIM3->CCR4 = Duty;
//			TIM3->CCER |= (1<<3);
//		break;
//		default:
//		break;
//	}
//}

#endif /* PWM_SRC_PWM_C_ */
