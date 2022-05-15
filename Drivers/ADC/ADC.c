#include "ADC.h"
#define adc1 1
#define adc2 2

/*******************************************************************************
 * Service Name: ADC_init
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ADC_Confiration -  configuration data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: short channel    -   channel number - it's -1 on configuration failure
 * Description: Initialize the ADC module.
 ********************************************************************************/
char ADC_init(char adc, GPIO_TypeDef *port, short pin)
// void ADC_init(ADC_Confiration)
{
    char channel = 0; // we've 16 channels
    char result = 0;  // value read from adc
    GPIO_TYPE gp;
    gp.mode = INPUT_MODE;
    gp.mode_type = INPUT_ANALOG;

    // get channel according to pin and port used
    // get it from data sheet

    if (port == GPIOA)
    {
        if (pin < 8)
        {
            result = 1; // we reached a channel successfully
            channel = pin;
            gp.port = GPIOA;
            gp.pin = pin;
        }
    }
    else if (port == GPIOB)
    {
        if (pin < 2)
        {
            result = 1; // we reached a channel successfully
            channel = pin + 8;
            gp.port = GPIOB;
            gp.pin = pin;
        }
    }
    else if (port == GPIOC)
    {
        if (pin < 6)
        {
            result = 1; // we reached a channel successfully
            channel = pin + 10;
            gp.port = GPIOC;
            gp.pin = pin;
        }
    }
    if (result)
    {
        //		HAL_GPIO_Init(port, pin, IN, I_AN);
        //		HAL_GPIO_Init(GPIOx, GPIO_Init);
        //		MX_GPIO_Init();

        gpio_init(gp);

        if (adc == adc1)
        {
            // peripheral clock enable register
            // set bit 9 and bit 0 in RCC to 1
            RCC->APB2ENR |= 0x201;
            // clean configurations for adc1 to make sure there is
            // no extra setup make control register=0
            ADC1->CR2 = 0;
            // put #of channel in regular sequence register
            // SQ1
            ADC1->SQR3 = channel;
            // power on the adc from control register
            // ADON A/D converter on/off, we must set it 1 twice
            ADC1->CR2 |= 1;
            //			HAL_Delay(100);
            delay(100);
            ADC1->CR2 |= 1;

            // make continuous conversion,
            // whenever we need conversion, begin conversion again and again
            ADC1->CR2 |= 2;
        }
        else if (adc == adc2)
        {
            // peripheral clock enable register
            // set bit 10 and bit 0 in RCC to 1
            RCC->APB2ENR |= 0x401;
            // clean configurations for adc2 to make sure there is
            // no extra setup make control register=0
            ADC2->CR2 = 0;
            // put #of channel in regular sequence register
            // SQ1
            ADC2->SQR3 = channel;

            // make continuous conversion,
            // whenever we need conversion, begin conversion again and again
            // I think this will be used if we don't make continuous conversion

            // ADC2->CR2 |= 2;
        }
    }
    return result;
}

// check if the data is ready
// char adc_check(char adc, short port, short pin)
//{
//	char check = 0;
//	if(adc == adc1)
//		{
//			//status register
//			if(ADC1->SR & 2)
//			{
//				check  = 1;
//			}
//		}
//		else if(adc == adc2)
//		{
//			if(ADC2->SR & 2)
//			{
//				check  = 1;
//			}
//		}
//
//
//	return check;
//}
/*******************************************************************************
 * Service Name: ADC_startConversion
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): module       - ADC module number
 *                  channel      - Channel number to start conversion on
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Start the conversion of the ADC.
 ********************************************************************************/

char ADC_startConversion(char adc, short pin)
{
    // this code was put in init
    // power on the adc from control register
    // ADON A/D converter on/off, we must set it 1 twice
    // this is my code :')
    // check the start bit in the status register
    char checkIfStarted = 0;
    if (adc == adc1)
    {
        // set ADON bit to 1 to wake up the ADC from power down state
        ADC2->CR2 |= 1;
        // wait for t_STAB
        HAL_Delay(100);
        // set ADON bit to 1 again to start conversion
        ADC2->CR2 |= 1;
        // status register
        if (ADC1->SR & 16)
            checkIfStarted = 1;

    }
    else if (adc == adc2)
    {
        // select the channel to scan
        ADC2->SQR3 = channel;
        // set ADON bit to 1 to wake up the ADC from power down state
        ADC2->CR2 |= 1;
        // wait for t_STAB
        DelayMs(100);
        // set ADON bit to 1 again to start conversion
        ADC2->CR2 |= 1;
        // set CONT bit to 1 to setup for contiuous conversion

        // ADC2->CR2 |= 2;
        // status register
        if (ADC2->SR & 16)
            checkIfStarted = 1;
    }

    return checkIfStarted;
}

/*******************************************************************************
 * Service Name: ADC_conversionDone
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): module       - ADC module number
 *                  channel      - Channel number to check if it finished conversion
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: boolean
 * Description: Check whether a channel has finished a sample conversion.
 *                  check EOC in ADCx->SR & 2 for end of conversion
 *                  EOC -> 0 : conversion not complete
 *                  EOC -> 1: conversion complete
 ********************************************************************************/
char ADC_conversionDone(char adc, short pin)
{
    char checkIfDone = 0;
    if (adc == adc1)
    {
        // status register
        if (ADC1->SR & 2)
        {
            checkIfDone = 1;
        }
    }
    else if (adc == adc2)
    {
        if (ADC2->SR & 2)
        {
            checkIfDone = 1;
        }
    }

    return checkIfDone;
}

/*******************************************************************************
 * Service Name: ADC_getData
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): module       - ADC module number
 *                  sequencer    - Sample sequencer number in that module
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: int - Result from ADC conversion
 * Description: Obtain the converted data from the register.
 ********************************************************************************/
int ADC_getData(char adc, short pin)
{
    int result = 0;
    int data = 0;
    if (adc == adc1)
    {
        // data register
        // 12 bit to be read
        data = ADC1->DR;
    }
    else if (adc == adc2)
    {
        data = ADC2->DR;
    }

    result = (data * 1000) / 0xfff;

    return result;
}
