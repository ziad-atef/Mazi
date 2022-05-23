
#ifndef _sensors_H_
#define _sensors_H_


//#include <HardwareSerial.h>
#include "_HAL_GPIO.h"
#include "ADC.h"


#define INV 850

#define CL0 350
#define CL4 200

#define _numSensors 5


GPIO_TYPE IR0_GPIO={
	.port 			= PORTA,
	.pin 				= 0,
	.mode 			= INPUT_MODE,
	.mode_type 	= INPUT_ANALOG,
	.speed			= SPEED_50MHZ
};

GPIO_TYPE IR1_GPIO={
	.port 			= PORTA,
	.pin 				= 1,
	.mode 			= INPUT_MODE,
	.mode_type 	= INPUT_ANALOG,
	.speed			= SPEED_50MHZ
};

GPIO_TYPE IR2_GPIO={
	.port 			= PORTA,
	.pin 				= 2,
	.mode 			= INPUT_MODE,
	.mode_type 	= INPUT_ANALOG,
	.speed			= SPEED_50MHZ
};

GPIO_TYPE IR3_GPIO={
	.port 			= PORTA,
	.pin 				= 3,
	.mode 			= INPUT_MODE,
	.mode_type 	= INPUT_ANALOG,
	.speed			= SPEED_50MHZ
};

GPIO_TYPE IR4_GPIO={
	.port 			= PORTA,
	.pin 				= 4,
	.mode 			= INPUT_MODE,
	.mode_type 	= INPUT_ANALOG,
	.speed			= SPEED_50MHZ
};

void get_readings(int *sensors_readings);

void calibrate_readings(int *sensors_readings);

unsigned read_line(int *sensors_readings);

//void log_readings(int *sensors_readings, int proportional);

#endif







