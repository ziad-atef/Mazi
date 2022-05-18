#include "ADC.h"
//#include "help_func.h"
#include "PWM.h"       

//char num[10];
int analog_rx = 0;
int main(void)
{
// Initialize the ADC
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	systick_init();
	ADC_init(adc1, PORTA, 0);
	
	
//	init_GP(PA8,OUT50,O_AF_PP);
	
	GPIO_TYPE gp;
	gp.port=PORTA;
	gp.pin= 8;
	gp.mode=OUTPUT_MODE;
	gp.mode_type=OUTPUT_ALT_FUNCTION;
	gp.speed=SPEED_50MHZ;
	
	gpio_init(gp);
	PWM_Init(PORTA,8, 2, 60000);
	
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
	
while(1)
{
	if(ADC_checkData(adc1))
	{
		analog_rx=ADC_getData(adc1);
		PWM_Start(PORTA,8,  analog_rx*6);
	}
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
