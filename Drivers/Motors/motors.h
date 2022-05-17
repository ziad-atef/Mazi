/*
 * motors.h
 *
 *  Created on: May 17, 2022
 *      Author: passantabdelgalil
 */


#ifndef _Motors_H_
#define _Motors_H_

#include "../../GPIOs/Inc/_HAL_GPIO.h"
#include "../../PWM/Inc/PWM.h"

#define GPIO_SPEED SPEED_50MHZ
#define MAX_SPEED 120
#define PWM_Prescalar 2
#define PWM_MaxValue 60000

GPIO_TYPE IN1_GPIO = {
	.port 			= PORTB,
	.pin 			= 3,
	.mode 			= OUTPUT_MODE,
	.mode_type 		= OUTPUT_GEN_PURPOSE,
	.speed			= SPEED_50MHZ
};
GPIO_TYPE IN2_GPIO = {
	.port 			= PORTB,
	.pin 			= 4,
	.mode 			= OUTPUT_MODE,
	.mode_type 		= OUTPUT_GEN_PURPOSE,
	.speed			= SPEED_50MHZ
};
GPIO_TYPE IN3_GPIO = {
	.port 			= PORTB,
	.pin 			= 5,
	.mode 			= OUTPUT_MODE,
	.mode_type 		= OUTPUT_GEN_PURPOSE,
	.speed			= SPEED_50MHZ
};
GPIO_TYPE IN4_GPIO = {
	.port 			= PORTB,
	.pin 			= 6,
	.mode 			= OUTPUT_MODE,
	.mode_type 		= OUTPUT_GEN_PURPOSE,
	.speed			= SPEED_50MHZ
};

GPIO_TYPE MS1_GPIO = {
	.port 			= PORTA,
	.pin 			= 7,
	.mode 			= OUTPUT_MODE,
	.mode_type 		= OUTPUT_ALT_FUNCTION,
	.speed			= SPEED_50MHZ
};

GPIO_TYPE MS2_GPIO = {
	.port 			= PORTA,
	.pin 			= 8,
	.mode 			= OUTPUT_MODE,
	.mode_type 		= OUTPUT_ALT_FUNCTION,
	.speed			= SPEED_50MHZ
};



void setup_motors();



void init_motors();



void change_speed(int motor1_speed, int motor2_speed);

#endif
