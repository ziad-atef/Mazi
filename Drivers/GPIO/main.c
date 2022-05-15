#include "stm32f10x.h"                  // Device header
#include "_HAL_GPIO.h"
#include"DELAY.h"
int main(void)
{
	
	
	
	


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
	}
	
	
		
		
	
	
	
	
	
	
	
	
	
}

