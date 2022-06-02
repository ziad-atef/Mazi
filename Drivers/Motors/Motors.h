/******************************************************************************
 * motors.h
 *
 * Header file that contains functions to interact with motors
 *******************************************************************************/

#ifndef _Motors_H_
#define _Motors_H_


/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/

#include "../GPIO/_HAL_GPIO.h"
#include "../PWM/PWM.h"
#include "../../Includes/systick_time.h"

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

#define GPIO_SPEED SPEED_50MHZ
#define MAX_SPEED 120
#define PWM_Prescalar 2
#define PWM_MaxValue 60000

// Motors Pins number
#define IN1_Pin 3
#define IN2_Pin 4
#define IN3_Pin 5
#define IN4_Pin 6
#define MS1_Pin 7
#define MS2_Pin 8


/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

/*
 *   Setup motors pins
 *
 *   Using defined motors pins, this function calls GPIO Driver function
 *   gpio_init to configure stm32 pins to allow for usage.
 */
void setup_motors();

/*
 *   Initialize motors
 *
 *   This function sets initial speed to both motors and
 *   sets polarity so the motors move forward
 */
void init_motors();

/*
 *    Change motors speed
 *
 *   Using PWM driver function, this function outputs PWM signals on motors pin
 *   to set their speed.
 *
 *   @param motor1_speed: value that will be output on motor 1 pin
 *   to set this motors speed
 *   @param motor2_speed: value that will be output on motor 2 pin
 *   to set this motors speed
 *
 */
void change_speed(int motor1_speed, int motor2_speed);

/*
 *   Turn the car left
 *
 *   This function makes the car turns left by stopping the left motor
 *   and set the right motor polarity to move forward
 */
void turn_left();

/*
 *   Turn the car right
 *
 *   This function makes the car turns right by stopping the right motor
 *   and set the left motor polarity to move forward
 */
void turn_right();

/*
 *   Move the car forward
 *
 *   This function makes the car moves forward by setting both the left and
 *   right motors polarity to move forward
 */
void forward();

/*
 *   Stop the car
 *
 *   This function makes the car stop moving by output 0s on both pins for both
 *   the right and left motor.
 */
void stop();

/*
 *   Move the car forward
 *
 *   This function makes the car moves backward by setting both the left and
 *   right motors polarity to the opposite values of forward move settings.
 */
void backward();

#endif
