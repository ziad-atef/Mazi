#include "Drivers/ADC/ADC.h"
#include "Drivers/PWM/PWM.h"
#include "Drivers/GPIO/_HAL_GPIO.h"

#include "Drivers/Motors/Motors.h"
#include "Drivers/Sensors/Sensors.h"

#define WHITE_THRESH 500
#define WHITE_LINE(sensor_reading) sensor_reading > WHITE_THRESH 


// char num[10];
int analog_rx = 0;
int main(void)
{

  setup_motors();
  init_motors();

  // // Initialize the ADC
  // 	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
  // 	systick_init();
  // 	ADC_init(adc1, PORTA, 0);

  // 	GPIO_TYPE gp = {
  //     .port=PORTA,
  //     .pin= 8,
  //     .mode=OUTPUT_MODE,
  //     .mode_type=OUTPUT_ALT_FUNCTION,
  //     .speed=SPEED_50MHZ
  //   };
  // 	gpio_init(gp);
  // 	PWM_Init(PORTA,8, 2, 60000);

  // 	GPIO_TYPE gp1 = {
  //     .port=PORTA,
  //     .pin=7,
  //     .mode=INPUT_MODE,
  //     .mode_type=INPUT_PU_PD,
  //     .speed=SPEED_50MHZ
  //   };
  // 	gpio_init(gp1);

  // 	GPIO_TYPE gp2= {
  //     .port=PORTA,
  //     .pin=6,
  //     .mode=OUTPUT_MODE,
  //     .mode_type=OUTPUT_GEN_PURPOSE,
  //     .speed=SPEED_50MHZ
  //   };
  // 	gpio_init(gp2);

  while (1)
  {
    int sensors_readings[5];
    get_readings(sensors_readings);
    calibrate_readings(sensors_readings);

    if(WHITE_LINE(sensors_readings[0]) && !WHITE_LINE(sensors_readings[1]) && WHITE_LINE(sensors_readings[2]))
    {// straight line only

    }
    else if (sensors_readings[0] >=WHITE_THRESH && sensors_readings[1] < WHITE_THRESH && sensors_readings[2] < WHITE_THRESH)
    {// straight line and right turn

    }
    else if(sensors_readings[0] < WHITE_THRESH && sensors_readings[1] < WHITE_THRESH && sensors_readings[2]>= WHITE_THRESH)
    {// straight line and left turn

    }
    else if(sensors_readings[0] < WHITE_THRESH && sensors_readings[1]< WHITE_THRESH && sensors_readings[2] < WHITE_THRESH)
    {// straight line, right turn, left turn

    }
    // if(ADC_checkData(adc1))
    // {
    //   analog_rx=ADC_getData(adc1);
    //   PWM_Start(PORTA,8,  analog_rx*6);
    // }
    // if(gpio_read(PORTA,7))
    // {
    //   gpio_write(PORTA,6,0);
    //   while(gpio_read(PORTA,7)){}
    // }
    // else
    // {
    //   gpio_write(PORTA,6,1);
    // }
  }
}
