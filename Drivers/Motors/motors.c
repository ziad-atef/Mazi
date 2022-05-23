#include "../Inc/motors.h"


void setup_motors(){
	// configure output pins
	gpio_init(IN1_GPIO);
	gpio_init(IN2_GPIO);
	gpio_init(IN3_GPIO);
	gpio_init(IN4_GPIO);

	// PWM pins for motors speed
	PWM_Init(MS1_GPIO.port, MS1_GPIO.pin, PWM_Prescalar, PWM_MaxValue);
	PWM_Init(MS2_GPIO.port, MS2_GPIO.pin, PWM_Prescalar, PWM_MaxValue);
}


void init_motors(){

	gpio_write(IN1_GPIO.port, IN1_GPIO.pin, 1);
	gpio_write(IN2_GPIO.port, IN2_GPIO.pin, 0);
	gpio_write(IN3_GPIO.port, IN3_GPIO.pin, 1);
	gpio_write(IN4_GPIO.port, IN4_GPIO.pin, 0);
	
	PWM_Start(MS1_GPIO.port, MS1_GPIO.pin, MAX_SPEED);
	PWM_Start(MS2_GPIO.port, MS2_GPIO.pin, MAX_SPEED);
}


void change_speed(int motor1_speed, int motor2_speed){
	PWM_Start(MS1_GPIO.port, MS1_GPIO.pin, motor1_speed);
	PWM_Start(MS2_GPIO.port, MS2_GPIO.pin, motor2_speed);
}
