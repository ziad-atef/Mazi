/*
 * motors.h
 *
 *  Created on: May 17, 2022
 *      Author: passantabdelgalil
 */

#ifndef _Motors_H_
#define _Motors_H_

#include "../GPIO/_HAL_GPIO.h"
#include "../PWM/PWM.h"
#include "../../Includes/systick_time.h"
#define GPIO_SPEED SPEED_50MHZ
#define MAX_SPEED 120
#define PWM_Prescalar 2
#define PWM_MaxValue 60000

void setup_motors();

void init_motors();

void change_speed(int motor1_speed, int motor2_speed);

void turn_left();

void turn_right();

void forward();

void stop();

void backward();

#endif
