#ifndef SENSORS_SRC_PWM_C_
#define SENSORS_SRC_PWM_C_

#include "Sensors.h"

GPIO_TYPE IR0_GPIO = {
	.port = PORTA,
	.pin = IR0_Pin,
	.mode = INPUT_MODE,
	.mode_type = INPUT_ANALOG,
	.speed = SPEED_50MHZ};

GPIO_TYPE IR1_GPIO = {
	.port = PORTA,
	.pin = IR1_Pin,
	.mode = INPUT_MODE,
	.mode_type = INPUT_ANALOG,
	.speed = SPEED_50MHZ};

GPIO_TYPE IR2_GPIO = {
	.port = PORTA,
	.pin = IR2_Pin,
	.mode = INPUT_MODE,
	.mode_type = INPUT_ANALOG,
	.speed = SPEED_50MHZ};

GPIO_TYPE IR3_GPIO = {
	.port = PORTA,
	.pin = IR3_Pin,
	.mode = INPUT_MODE,
	.mode_type = INPUT_ANALOG,
	.speed = SPEED_50MHZ};

GPIO_TYPE IR4_GPIO = {
	.port = PORTA,
	.pin = IR4_Pin,
	.mode = INPUT_MODE,
	.mode_type = INPUT_ANALOG,
	.speed = SPEED_50MHZ};

void get_readings(int *sensors_readings)
{
	ADC_init(adc1, IR0_GPIO.port, IR0_GPIO.pin);
	ADC_checkData(adc1);
	sensors_readings[0] = INV - ADC_getData(adc1);

	ADC_init(adc1, IR1_GPIO.port, IR1_GPIO.pin);
	ADC_checkData(adc1);
	sensors_readings[1] = INV - ADC_getData(adc1);

	ADC_init(adc1, IR2_GPIO.port, IR2_GPIO.pin);
	ADC_checkData(adc1);
	sensors_readings[2] = INV - ADC_getData(adc1);

	ADC_init(adc1, IR3_GPIO.port, IR3_GPIO.pin);
	ADC_checkData(adc1);
	sensors_readings[3] = INV - ADC_getData(adc1);

	ADC_init(adc1, IR4_GPIO.port, IR4_GPIO.pin);
	ADC_checkData(adc1);
	sensors_readings[4] = INV - ADC_getData(adc1);
}

void calibrate_readings(int *sensors_readings)
{
	if (sensors_readings[0] <= CL0)
		sensors_readings[0] = 0;
	if (sensors_readings[4] <= CL4)
		sensors_readings[4] = 0;
}

#endif
