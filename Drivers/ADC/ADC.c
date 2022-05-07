
#include "ADC.h"
#include "gpio.h"

/*******************************************************************************
* Service Name: ADC_init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ADC_Confiration -  configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initialize the ADC module.
********************************************************************************/
// void ADC_init(ADC_Confiration)
// {
    
// }

char ADC_init(char adc, short port, short pin)
//void ADC_init(ADC_Confiration)
{
	char channel = 0; //we've 16 channels
	char result = 0; //value read from adc

	//get channel according to pin and port used
	//get it from data sheet

	if(port == PA)
	{
		if(pin < 8)
		{
			result =1; //we reached a channel successfully
			channel = pin;
		}
	}
	else if(port == PB)
	{
		if(pin < 2)
		{
			result =1; //we reached a channel successfully
			channel = pin + 8;
		}
	}
	else if(port == PC)
	{
		if(pin < 6)
		{
			result =1; //we reached a channel successfully
			channel = pin + 10;
		}
	}
	if(result)
	{
//		HAL_GPIO_Init(port, pin, IN, I_AN); ///>???
//		HAL_GPIO_Init(GPIOx, GPIO_Init);


		if(adc == adc1)
		{
			//activate clk register RCC at bit 9
			RCC->APB2ENR |= 0x201;
			//to make sure there is no extra setup make control register =0
			ADC1->CR2 = 0;
			//put #of channel in regular sequence register
			//SQ1
			ADC1->SQR3 =channel;
			//power on the adc from control register
			//ADON A/D converter on/off, we must set it 1 twice
			ADC1->CR2 |= 1;
			HAL_Delay(100);
			ADC1->CR2 |= 1;

			//make continuous conversion,
			//whenever we need conversion, begin conversion again and again
			ADC1->CR2 |= 2;
		}
		else if(adc == adc2)
		{
			//activate clk register RCC at bit 10
			RCC->APB2ENR |= 0x401;
			//to make sure there is no extra setup make control register =0
			ADC2->CR2 = 0;
			//put #of channel in regular sequence register
			//SQ1
			ADC2->SQR3 =channel;


			//make continuous conversion,
			//whenever we need conversion, begin conversion again and again
			//I think this will be used if we don't make continuous conversion

			//ADC2->CR2 |= 2;
		}
	}
	return result;
}

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
// void ADC_startConversion(module, channel)
// {

// }

char ADC_startConversion(char adc, short port, short pin)
{
	//this code was put in init
	//power on the adc from control register
	//ADON A/D converter on/off, we must set it 1 twice
	ADC2->CR2 |= 1;
	HAL_Delay(100);
	ADC2->CR2 |= 1;

	//this is my code :')
	//check the start bit in the status register
	char checkIfStarted = 0;
	if(adc == adc1)
		{
			//status register
			if(ADC1->SR & 16)
			{
				checkIfStarted  = 1;
			}
		}
		else if(adc == adc2)
		{
			if(ADC2->SR & 16)
			{
				checkIfStarted  = 1;
			}
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
********************************************************************************/
// boolean ADC_conversionDone(module, channel)
// {

// }
char ADC_conversionDone(char adc, short port, short pin)
{
	char checkIfDone = 0;
	if(adc == adc1)
		{
			//status register
			if(ADC1->SR & 2)
			{
				checkIfDone  = 1;
			}
		}
		else if(adc == adc2)
		{
			if(ADC2->SR & 2)
			{
				checkIfDone  = 1;
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
* Return value: conversionResult - Result from ADC conversion
* Description: Obtain the converted data from the register.
********************************************************************************/
// conversionResult ADC_getData(module, channel)
// {

// }
{
	int result = 0;
	int data = 0;
	if(adc == adc1)
	{
		//data register
		//12 bit to be read
		data = ADC1->DR;
	}
	else if(adc == adc2)
	{
		data = ADC2->DR;
	}

	result = (data*1000)/0xfff;


	return result;
}
