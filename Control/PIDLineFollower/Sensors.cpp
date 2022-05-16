#include "Sensors.h"

void get_readings(int *sensors_readings)
{
    sensors_readings[0] = INV - analogRead(IR0); // most right sensor
    sensors_readings[1] = INV - analogRead(IR1);
    sensors_readings[2] = INV - analogRead(IR2);
    sensors_readings[3] = INV - analogRead(IR3);
    sensors_readings[4] = INV - analogRead(IR4); // most left sensor
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

void log_readings(int *sensors_readings, int proportional)
{
    Serial.print("sensors: ");
    for (int i = 0; i < _numSensors; i++)
    {
        Serial.print(sensors_readings[i]);
        Serial.print("  ");
    }

    Serial.print("  position: ");
    Serial.println(proportional);
}
