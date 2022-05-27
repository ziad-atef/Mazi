//#include "_HAL_GPIO.h"
//#include "DELAY.h"
//
//int main(void)
//{
//	GPIO_TYPE gp1 = {
//		.port = PORTA,
//		.pin = 7,
//		.mode = INPUT_MODE,
//		.mode_type = INPUT_PU_PD,
//		.speed = SPEED_50MHZ
//	};
//	gpio_init(gp1);
//
//	GPIO_TYPE gp2 = {
//		.port = PORTA,
//		.pin = 6,
//		.mode = OUTPUT_MODE,
//		.mode_type = OUTPUT_GEN_PURPOSE,
//		.speed = SPEED_50MHZ
//	};
//
//	gpio_init(gp2);
//
//	GPIO_TYPE myGPIO = {
//		.port = PORTC,
//		.pin = 13,
//		.mode = OUTPUT_MODE,
//		.mode_type = OUTPUT_GEN_PURPOSE,
//		.speed = SPEED_50MHZ
//	};
//
//	gpio_init(myGPIO);
//
//	while (1)
//	{
//		gpio_toggle(PORTC, 13);
//		delay(1000);
//
//		if (gpio_read(PORTA, 7))
//		{
//			gpio_write(PORTA, 6, 0);
//			while (gpio_read(PORTA, 7))
//			{
//			}
//		}
//		else
//		{
//			gpio_write(PORTA, 6, 1);
//		}
//	}
//}
