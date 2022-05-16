/******************************************************************************
 *
 * Module: Sensors
 *
 * File Name: Sensors.h
 *
 * Description: Header file for Sensors Interface.
 *
 ******************************************************************************/

#ifndef _Sensors_H_
#define _Sensors_H_

/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/
#include <HardwareSerial.h>
#include <Arduino.h>

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/
#define IR0 A3 // Most right sensor
#define IR1 A0
#define IR2 A1
#define IR3 A2
#define IR4 A4 // Most left sensor

#define INV 850 // Value used to reverse IR readings to be heigh for dark colors

#define CL0 350 // Value used to calibrate IR0 sensor
#define CL4 200 // Value used to calibrate IR4 sensor

#define _numSensors 5

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

/*******************************************************************************
 * Service Name: get_readings
 * Parameters (in): sensors_readings  - array to store readings
 * Return value: void
 * Description: Read inputs from 5 IR sensors.
 ********************************************************************************/
void get_readings(int *sensors_readings);

/*******************************************************************************
 * Service Name: calibrate_readings
 * Parameters (in): sensors_readings  - array that contains sensors readings
 * Return value: void
 * Description:  Correct readings from sensors to match. Currently it only corrects
 *               IR0 & IR4 to match other sensors range
 ********************************************************************************/
void calibrate_readings(int *sensors_readings);

/*******************************************************************************
 * Service Name: read_line
 * Parameters (in): sensors_readings  - array that contains sensors readings
 * Return value: void
 * Description:  Get the position of the robot relative to the line
 *               range from 0 to 2000 (1000 is on the line)
 ********************************************************************************/
unsigned read_line(int *sensors_readings);

/*******************************************************************************
 * Service Name: log_readings
 * Parameters (in): sensors_readings  - array that contains sensors readings
 * Return value: void
 * Description:  Output readings and current postion error to Serial
 ********************************************************************************/
void log_readings(int *sensors_readings, int proportional);

#endif