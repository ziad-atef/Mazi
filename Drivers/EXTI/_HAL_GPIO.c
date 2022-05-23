#include "_HAL_GPIO.h"
#include <stdint.h>

uint32_t PINPOS [16]={


	(0x00),
	(0x04),
	(0x08),
	(0x0C),
	(0x10),
	(0x14),
	(0x18),
	(0x1C),
	(0x00), //pin 8
	(0x04), 
	(0x08),
	(0x0C),
	(0x10),
	(0x14),
	(0x18),
	(0x1C)




};
//configure bits
static void config_pin(GPIO_TypeDef *port,uint32_t pinNumber,uint32_t  Mode_type)
{
	
	 
	if(pinNumber>=8) //CONTROL HIGH REGISTER
	{
		switch( Mode_type)
		{ // OUTPUT & INPUT MODES
			case OUTPUT_GEN_PURPOSE |INPUT_ANALOG:
				port->CRH &=~((1<<CNF_POS_BIT1) | (1<<CNF_POS_BIT2));
			break;
			
			case OUTPUT_OD | INPUT_FLOATING:
				port->CRH &= ~(1<<CNF_POS_BIT2);
			  port->CRH |= (1<<CNF_POS_BIT1);
			break;
			
			case OUTPUT_ALT_FUNCTION |INPUT_PU_PD:
				port->CRH |=OUTPUT_ALT_FUNCTION<<(CNF_POS_BIT1);
			break;
			case OUTPUT_ALT_FUNCTION_OD:
				port->CRH |=OUTPUT_ALT_FUNCTION_OD<<(CNF_POS_BIT1);
			break;
			
			
		}//end switch
		
		
	}
	else //CONTROL LOW REGISTER
		
	
	{
			switch( Mode_type)
		{ // OUTPUT & INPUT MODES
			case OUTPUT_GEN_PURPOSE |INPUT_ANALOG:
				port->CRL &=~((1<<CNF_POS_BIT1) | (1<<CNF_POS_BIT2));
			break;
			
			case OUTPUT_OD | INPUT_FLOATING:
				port->CRL &= ~(1<<CNF_POS_BIT2);
			  port->CRL |= (1<<CNF_POS_BIT1);
			break;
			
			case OUTPUT_ALT_FUNCTION |INPUT_PU_PD:
				port->CRL |=OUTPUT_ALT_FUNCTION<<(CNF_POS_BIT1);
			break;
			case OUTPUT_ALT_FUNCTION_OD:
				port->CRL |=OUTPUT_ALT_FUNCTION_OD<<(CNF_POS_BIT1);
			break;
			
			
		}//end switch
		
		
		
	}
}


static void config_pin_speed(GPIO_TypeDef *port,uint32_t pinNumber,uint32_t pinSpeed,uint32_t  mode)
{
	
	if(pinNumber>=8)
	{
	if(mode==INPUT_MODE)
		port->CRH &= ~(1<<(PINPOS[pinNumber])|1<<(PINPOS[pinNumber]+1));

	else
		port->CRH |=(pinSpeed<<(PINPOS[pinNumber]));
	}
	else
	{
		
		if(mode==INPUT_MODE)
		port->CRL &= ~(1<<(PINPOS[pinNumber])|1<<(PINPOS[pinNumber]+1));

	else
		port->CRL |=(pinSpeed<<(PINPOS[pinNumber]));
		
	}
}



void gpio_write(GPIO_TypeDef *port,uint32_t pinNumber,uint8_t state)
{
	if(state)
	{
		
		port->BSRR=(1<<(pinNumber + 16));
		
		
	}
	else 
	{
		
		port->BSRR=(1<<pinNumber);
		
		
	}
	
	
	
}




void gpio_toggle(GPIO_TypeDef *port,uint32_t pinNumber)
{
	
	port ->ODR ^=(1<<pinNumber);
	
}
void gpio_init(GPIO_TYPE gpio_type)
{
	if(gpio_type.port==PORTA)
		GPIO_CLOCK_ENABLE_PORTA;
	if(gpio_type.port==PORTB)
		GPIO_CLOCK_ENABLE_PORTB;
	if(gpio_type.port==PORTC)
		GPIO_CLOCK_ENABLE_PORTC;
	if(gpio_type.port==PORTD)
		GPIO_CLOCK_ENABLE_PORTD;
	
	 
	config_pin(gpio_type.port,gpio_type.pin,gpio_type.mode_type);
	config_pin_speed(gpio_type.port,gpio_type.pin,gpio_type.speed,gpio_type.mode);
	
	
}

