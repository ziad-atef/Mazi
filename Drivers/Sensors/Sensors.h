/******************************************************************************
*    Header File for Functions that interact with sensors.
*    It also includes sensors pin number as #define's to change easily
 *******************************************************************************/



#ifndef _sensors_H_
#define _sensors_H_


/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/

#include "../GPIO/_HAL_GPIO.h"
#include "../ADC/ADC.h"

/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/

#define INV 850

#define CL0 350
#define CL4 200

#define _numSensors 5

#define IR0_Pin 0
#define IR1_Pin 1
#define IR2_Pin 2
#define IR3_Pin 3
#define IR4_Pin 4


/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

/*
*   Function to read sensors value
*   
*   This function uses ADC API to read the sensors value because
*   we use analog IR sensors not digital.
*   
*   @param sensors_readings: an array of size 5 (number of sensors) to store
*   each sensor value in its corresponding cell
*/
void get_readings(int *sensors_readings);

void calibrate_readings(int *sensors_readings);


#endif







