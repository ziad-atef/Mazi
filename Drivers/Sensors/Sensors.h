//#include <HardwareSerial.h>

#ifndef _sensors_H_
#define _sensors_H_


#include "../GPIO/_HAL_GPIO.h"
#include "../ADC/ADC.h"


#define INV 850

#define CL0 350
#define CL4 200

#define _numSensors 5



void get_readings(int *sensors_readings);

void calibrate_readings(int *sensors_readings);

unsigned read_line(int *sensors_readings);

//void log_readings(int *sensors_readings, int proportional);

#endif







