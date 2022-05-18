#include "stm32f10x.h"                  // Device header
#include "_HAL_GPIO.h"
#include"DELAY.h"
int main(void)
{
	GPIO_TYPE gp1;
	gp1.port=PORTA;
	gp1.pin= 7;
	gp1.mode=INPUT_MODE;
	gp1.mode_type=INPUT_PU_PD;
	gp1.speed=SPEED_50MHZ;
	
	gpio_init(gp1);
	
	GPIO_TYPE gp2;
	gp2.port=PORTA;
	gp2.pin= 6;
	gp2.mode=OUTPUT_MODE;
	gp2.mode_type=OUTPUT_GEN_PURPOSE;
	gp2.speed=SPEED_50MHZ;
	
	gpio_init(gp2);
	
	GPIO_TYPE myGPIO;
	myGPIO.port=PORTC;
	myGPIO.pin=13;
	myGPIO.mode=OUTPUT_MODE;
	myGPIO.mode_type=OUTPUT_GEN_PURPOSE;
	myGPIO.speed=SPEED_50MHZ;
	gpio_init(myGPIO);
	
	
	
	
		while(1)
	{
		gpio_toggle(PORTC,13);
  		delay(1000);

		if(gpio_read(PORTA,7))
		{
			gpio_write(PORTA,6,0);
			while(gpio_read(PORTA,7)){}
		}
		else
			{
			gpio_write(PORTA,6,1);
		}	
	}
	
	
		
		
	
	
	
	
	
	
	
	
	
}

