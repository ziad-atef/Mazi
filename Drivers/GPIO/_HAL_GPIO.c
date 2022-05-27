#ifndef GPIO_SRC_PWM_C_
#define GPIO_SRC_PWM_C_

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
	
		uint32_t right_bit_setter;
		uint32_t left_bit_setter;
	
	if(pinNumber>=8) //CONTROL HIGH REGISTER
	{
		switch( Mode_type)
		{ // OUTPUT & INPUT MODES
			case OUTPUT_GEN_PURPOSE:
				left_bit_setter = ~(1<<CNF_POS_BIT2);
				right_bit_setter = ~(1<<CNF_POS_BIT1);
			
				port->CRH &= left_bit_setter;
				port->CRH &= right_bit_setter;
				break;
			//case INPUT_ANALOG:
			//	port->CRH &=~((1<<CNF_POS_BIT1) | (1<<CNF_POS_BIT2));
			//	break;
			
			case OUTPUT_OD:
				left_bit_setter = ~(1<<CNF_POS_BIT2);
				right_bit_setter = (1<<CNF_POS_BIT1);
			
				port->CRH &= left_bit_setter;
			  port->CRH |= right_bit_setter;
				break;
			//case INPUT_FLOATING:
			//	port->CRH &= ~(1<<CNF_POS_BIT2);
			//  port->CRH |= (1<<CNF_POS_BIT1);
			//	break;
			
			case OUTPUT_ALT_FUNCTION:
				left_bit_setter = 1 << CNF_POS_BIT2;
				right_bit_setter = ~(1<<CNF_POS_BIT1);
				
				port->CRH |= left_bit_setter;
				port->CRH &= right_bit_setter;
				break;
			//case INPUT_PU_PD:
			//	port->CRH |=OUTPUT_ALT_FUNCTION<<(CNF_POS_BIT1);
			//	break;
			case OUTPUT_ALT_FUNCTION_OD:
				port->CRH |=OUTPUT_ALT_FUNCTION_OD<<(CNF_POS_BIT1);
			break;
			
			
		}//end switch
	}
	else //CONTROL LOW REGISTER
	{
			switch( Mode_type)
		{ // OUTPUT & INPUT MODES
//			case OUTPUT_GEN_PURPOSE |INPUT_ANALOG:
				case OUTPUT_GEN_PURPOSE:
					left_bit_setter = ~(1<<CNF_POS_BIT1);
					right_bit_setter = ~(1<<CNF_POS_BIT2);
					port->CRL &= left_bit_setter;
					port->CRL &= right_bit_setter;
				//port->CRL &=~((1<<CNF_POS_BIT1) | (1<<CNF_POS_BIT2));
					break;
			
//			case OUTPUT_OD | INPUT_FLOATING:
				case OUTPUT_OD:
					left_bit_setter = ~(1<<CNF_POS_BIT2);
					right_bit_setter = (1<<CNF_POS_BIT1);
					port->CRL &= left_bit_setter;
					port->CRL |= right_bit_setter;
					break;
			
//			case OUTPUT_ALT_FUNCTION |INPUT_PU_PD:
				case OUTPUT_ALT_FUNCTION:
					left_bit_setter = 1<<CNF_POS_BIT2;
					right_bit_setter = ~(1<<CNF_POS_BIT1);
					port->CRL |= left_bit_setter;
					port->CRL &= right_bit_setter;
//					port->CRL |=OUTPUT_ALT_FUNCTION<<(CNF_POS_BIT1);
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
		
		port->BSRR=(1<<pinNumber);
		
		
	}
	else 
	{
		
		
		port->BSRR=(1<<(pinNumber + 16));
		
		
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

uint8_t gpio_read(GPIO_TypeDef *port,uint32_t pinNumber)
{
	return (port->IDR & (1<<pinNumber));

}

#endif
