#include "ADC.h"

char ADC_init(char adc, GPIO_TypeDef* port, short pin)
{
	char channel; //we've 16 channels
	char result = 0; //value read from adc
	GPIO_TYPE gp;
	gp.mode=INPUT_MODE;
	gp.mode_type=INPUT_ANALOG;

	//get channel according to pin and port used
	//get it from data sheet

	if(port == PORTA)
	{
		if(pin < 8)
		{
			result =1; //we reached a channel successfully
			channel = pin;
			gp.port=PORTA;
			gp.pin= pin;
		}
	}
	else if(port == PORTB)
	{
		if(pin < 2)
		{
			result =1; //we reached a channel successfully
			channel = pin + 8;
			gp.port=PORTB;
			gp.pin= pin;

		}
	}
	else if(port == PORTC)
	{
		if(pin < 6)
		{
			result =1; //we reached a channel successfully
			channel = pin + 10;
			gp.port=PORTC;
			gp.pin= pin;

		}
	}
	if(result)
	{
		gpio_init(gp);

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
//			HAL_Delay(100);
//			delay(100);
			DelayMs(100);
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

			ADC2->CR2 |= 2;
			DelayMs(100);
			ADC2->CR2 |= 1;
			ADC2->CR2 |= 2;
		}
	}
	return result;
}

// check if the data is ready
char ADC_checkData(char adc)
{
	char check = 0;
	if(adc == adc1)
		{
			//status register
			if(ADC1->SR & 2)
			{
				check  = 1;
			}
		}
		else if(adc == adc2)
		{
			if(ADC2->SR & 2)
			{
				check  = 1;
			}
		}


	return check;
}

// Reading the ADC value
int ADC_getData(char adc)
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
