#include "ADC.h"
#include "gpio.h"

int main(void) //test ADC
{
    //systick_init();
    ADC_init(adc1, PA, 0);

    while (1)
    {
        if( ADC_startConversion(adc1, PA, 0) )
        {
            if( ADC_conversionDone(adc1, PA, 0) ) 
                {
                    ADC_getData(adc1, PA, 0);
                }
        }
    }
}