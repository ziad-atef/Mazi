#include "sensors.h"

void get_readings(int *sensors_readings)
{
	ADC_init(adc1,IR0_GPIO.port,IR0_GPIO.pin);
	ADC_checkData(adc1);
	sensors_readings[0]= INV - ADC_getData(adc1);
	
	ADC_init(adc1,IR1_GPIO.port,IR1_GPIO.pin);
	ADC_checkData(adc1);
	sensors_readings[1]= INV - ADC_getData(adc1);
	
	ADC_init(adc1,IR2_GPIO.port,IR2_GPIO.pin);
	ADC_checkData(adc1);
	sensors_readings[2]= INV - ADC_getData(adc1);

	ADC_init(adc1,IR3_GPIO.port,IR3_GPIO.pin);
	ADC_checkData(adc1);
	sensors_readings[3]= INV - ADC_getData(adc1);

	ADC_init(adc1,IR4_GPIO.port,IR4_GPIO.pin);
	ADC_checkData(adc1);
	sensors_readings[4]= INV - ADC_getData(adc1);
 
}

void calibrate_readings(int *sensors_readings)
{
    if (sensors_readings[0] <= CL0)
        sensors_readings[0] = 0;
    if (sensors_readings[4] <= CL4)
        sensors_readings[4] = 0;
}


unsigned read_line(int *sensors_readings)
{
    unsigned char i, on_line = 0;
    unsigned long avg;         // this is for the weighted total, which is long
                               // before division
    unsigned int sum;          // this is for the denominator which is <= 64000
    static int last_value = 0; // assume initially that the line is left.

    avg = 0;
    sum = 0;

    for (i = 0; i < _numSensors; i++)
    {
        int value = sensors_readings[i];

        // keep track of whether we see the line at all
        if (value > 200)
        {
            on_line = 1;
        }

        // only average in values that are above a noise threshold
        if (value > 50)
        {
            avg += (long)(value) * (i * 1000);
            sum += value;
        }
    }

    if (!on_line)
    {
        // If it last read to the left of center, return 0.
        if (last_value < (_numSensors - 1) * 1000 / 2)
            return 0;

        // If it last read to the right of center, return the max.
        else
            return (_numSensors - 1) * 1000;
    }

    last_value = avg / sum;

    return last_value / 2;
}



