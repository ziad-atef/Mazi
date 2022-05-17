#include "Motors.h"

void setup_motors()
{
    // define motors output pins
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // PWM pins for motors speed
    pinMode(MS1, OUTPUT);
    pinMode(MS2, OUTPUT);
}

void init_motors()
{
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);

    analogWrite(MS1, MAX_SPEED);
    analogWrite(MS2, MAX_SPEED);
}

void change_speed(int motor1_speed, int motor2_speed)
{
    analogWrite(MS1, motor1_speed);
    analogWrite(MS2, motor2_speed);
}
