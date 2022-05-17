#include "Drivers/ADC/ADC.h"
//#include "help_func.h"
#include "Drivers/PWM/Code/PWM.h"       

//char num[10];
int analog_rx = 0;
int main(void)
{
// Initialize the ADC
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	systick_init();
	ADC_init(adc1, PORTA, 0);
	
	
//	init_GP(PA,8,OUT50,O_AF_PP);
	
	GPIO_TYPE gp;
	gp.port=PORTA;
	gp.pin= 8;
	gp.mode=OUTPUT_MODE;
	gp.mode_type=OUTPUT_ALT_FUNCTION;
//	gp.pull;
	gp.speed=SPEED_50MHZ;
//	RCC->APB2ENR |= (1<<0); //gp.alt_func;GPIO_CLOCK_ENABLE_ALT_FUNC
//	RCC->APB2ENR |= (1<<2); //GPIO_CLOCK_ENABLE_PORTA
	
	gpio_init(gp);
	PWM_Init(PA8, 2, 60000);
	
while(1)
{
	if(ADC_checkData(adc1))
	{
		analog_rx=ADC_getData(adc1);
		PWM_Start(PA8,  analog_rx*6);
	}
}
}
