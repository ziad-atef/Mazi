
 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.h
 *
 * Description: Header file for STM32 Microcontroller - PWM Driver.
 *
 * Author: Ziad Atef
 ******************************************************************************/

#ifndef _PWM_H_
#define _PWM_H_

/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/

#include "stm32f10x.h"                         /* 
																									Device header which includes 
																									all the definitions of the 
																									device registers
																							 */
#include "Includes/Std_Types.h"			 /* 
																									Includes the generic types to 
																									be used
																							 */
#include "Includes/Common_Macros.h"	 /* 
																									Includes important macros to 
																									be used
																							 */


/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/
#define PA0   0
#define PA1   1
#define PA2   2
#define PA3   3

#define PA6   6
#define PA7   7

#define PA8		8
#define PA9		9
#define PA10	10
#define PA11	11

#define PB0		16
#define PB1		17
#define TIM_CCMR1_PWM_MODE1_CH1 ((uint16_t)0x0060)
#define TIM_CCMR1_PWM_MODE1_CH2 ((uint16_t)0x6000)
#define TIM_CCMR2_PWM_MODE1_CH3 ((uint16_t)0x0060)
#define TIM_CCMR2_PWM_MODE1_CH4 ((uint16_t)0x6000)

#define TIM_CCMR1_PWM_MODE2_CH1 ((uint16_t)0x0070)
#define TIM_CCMR1_PWM_MODE2_CH2 ((uint16_t)0x7000)
#define TIM_CCMR2_PWM_MODE2_CH3 ((uint16_t)0x0070)
#define TIM_CCMR2_PWM_MODE2_CH4 ((uint16_t)0x7000)
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/


/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

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
void PWM_Init(uint8 PinNum, uint16 Prescalar, uint16 ReloadVal);

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
void PWM_Start(uint8 PinNum, uint16 Duty);
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

#endif /* PWM_H */
