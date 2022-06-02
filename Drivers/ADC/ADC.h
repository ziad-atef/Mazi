 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description: Header file for STM32 Microcontroller - 
 * Analog to Digital Converter Driver.
 *
 ******************************************************************************/

#ifndef _ADC_H_
#define _ADC_H_

/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/

//Here you should include any file you may need
//#include "DELAY.h"
#include "../GPIO/_HAL_GPIO.h"
#include "../../Includes/systick_time.h"

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/
//Here you should add any #define that you may require in your work
#define adc1	 1
#define adc2	 2
// #define PA       1
// #define PB       2
// #define PC       3
#define I_AN 	 0 //input analog
#define  IN      0 //input

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
//Here you should define any struct or typedef that may help you in your coding


/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

char ADC_init(char adc, GPIO_TypeDef* port, short pin);
char ADC_checkData(char adc);
int ADC_getData(char adc);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
//Here add any extern that will be used

#endif /* ADC_H */
