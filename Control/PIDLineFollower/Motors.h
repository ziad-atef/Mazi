/******************************************************************************
 *
 * Module: Motors
 *
 * File Name: Motors.h
 *
 * Description: Header file for Motors Interface.
 *
 ******************************************************************************/

#ifndef _Motors_H_
#define _Motors_H_

/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/
#include <Arduino.h>

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define MS1 9
#define MS2 10
#define MAX_SPEED 120

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

/*******************************************************************************
 * Service Name: setup_motors
 * Return value: void
 * Description: Set all motors pins as output pins includeind PWM pins.
 ********************************************************************************/
void setup_motors();

/*******************************************************************************
 * Service Name: init_motors
 * Return value: void
 * Description: Initialize two motors to start working with max speed.
 ********************************************************************************/
void init_motors();

/*******************************************************************************
 * Service Name: change_speed
 * Parameters (in): motor1_speed    - required speed for first motor
 *                  motor2_speed    - required speed for second motor
 * Return value: void
 * Description: Set motors speed with given values.
 ********************************************************************************/
void change_speed(int motor1_speed, int motor2_speed);

#endif