#include "Drivers\ADC\ADC.h"
#include "Drivers\GPIO\_HAL_GPIO.h"

int main(void) // test ADC
{


	GPIO_TYPE potentiometer_GPIO;
	potentiometer_GPIO.port=GPIOA;
	potentiometer_GPIO.pin=7;
	potentiometer_GPIO.mode=INPUT_MODE;
	potentiometer_GPIO.mode_type=INPUT_ANALOG ;
	potentiometer_GPIO.speed=SPEED_50MHZ;
	gpio_init(potentiometer_GPIO);
	
	
    GPIO_TYPE LED_GPIO;
	LED_GPIO.port=GPIOA;
	LED_GPIO.pin=8;
	LED_GPIO.mode=OUTPUT_MODE;
	LED_GPIO.mode_type=OUTPUT_ALT_FUNCTION ;
	LED_GPIO.speed=SPEED_50MHZ;
	gpio_init(LED_GPIO);
	

    // systick_init();
    ADC_init(adc1, potentiometer_GPIO, potentiometer_GPIO.pin);
    int analog = 0;

    while (1)
    {
        if (ADC_startConversion(adc1, potentiometer_GPIO.pin))
        {
            if (ADC_conversionDone(adc1, potentiometer_GPIO.pin)) // instead of check
            {
                analog = ADC_getData(adc1, potentiometer_GPIO.pin);
                
            }
        }
    }
}