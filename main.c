#include "Drivers\ADC\ADC.h"
#include "Drivers\GPIO\_HAL_GPIO.h"


int main(void) //test ADC
{
    //systick_init();
    ADC_init(adc1, PORTA, 0);
    int analog=0;

    while (1)
    {
        if( ADC_startConversion(adc1, 0) )
        {
            if( ADC_conversionDone(adc1, 0) ) //instead of check
                {
                    analog = ADC_getData(adc1, 0);
                }
        }

        /
    }
}