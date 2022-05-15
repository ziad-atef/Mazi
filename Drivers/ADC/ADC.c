
#include "ADC.h"
#define adc1 1
#define adc2 2

/*******************************************************************************
 * Service Name: ADC_init
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ADC_Confiration -  configuration data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: short channel    -   channel number - it's -1 on configuration failure
 * Description: Initialize the ADC module.
 ********************************************************************************/
short ADC_init(char adc, short port, short pin)
{
    /*
    port->  pin
    PA0 ->  ADC12_IN0
    PA1 ->  ADC12_IN1
    PA2 ->  ADC12_IN2
    PA3 ->  ADC12_IN3
    PA4 ->  ADC12_IN4
    PA5 ->  ADC12_IN5
    PA6 ->  ADC12_IN6
    PA7 ->  ADC12_IN7

    PB0 ->  ADC12_IN8
    PB1 ->  ADC12_IN9

    PC0 ->  ADC12_IN10
    PC1 ->  ADC12_IN11
    PC2 ->  ADC12_IN12
    PC3 ->  ADC12_IN13
    PC4 ->  ADC12_IN14
    PC5 ->  ADC12_IN15
    */
    char channel;
    switch (port)
    {
    case PA:
        if (pin < 8)
            channel = pin;
        else
            return -1;
        break;
    case PB:
        if (pin < 2)
            channel = 8 + pin;
        else
            return -1;
        break;
    case PC:
        if (pin < 6)
            channel = 10 + pin;
        else
            return -1;
        break;
    default:
        return -1;
    }
    // init_GP(port, pin, IN, IN_ANALOG);
    if (adc == adc1)
    {
        // peropheral clock enable register
        // set bit 9 and bit 0 to 1
        RCC->APB2ENR |= 0x201;
        // clean configurations for adc1
        ADC1->CR2 = 0;
    }
    else if (adc == adc2)
    {
        // peropheral clock enable register
        // set bit 10 and bit 0 to 1
        RCC->APB2ENR |= 0x401;
        // clean configurations for adc1
        ADC2->CR2 = 0;
    }
    return channel;
}

/*******************************************************************************
 * Service Name: ADC_startConversion
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): module       - ADC module number
 *                  channel      - Channel number to start conversion on
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Start the conversion of the ADC.
 ********************************************************************************/
void ADC_startConversion(module, channel)
{
    if (module == adc1)
    {
        // select the channel to scan
        ADC1->SQR3 = channel;
        // set ADON bit to 1 to wake up the ADC from power down state
        ADC1->CR2 |= 1;
        // wait for t_STAB
        DelayMs(100);
        // set ADON bit to 1 again to start conversion
        ADC1->CR2 |= 1;
        // set CONT bit to 1 to setup for contiuous conversion
        // ADC1->CR2 |= 2;
    }
    else if (module == 2)
    {
        // select the channel to scan
        ADC2->SQR3 = channel;
        // set ADON bit to 1 to wake up the ADC from power down state
        ADC2->CR2 |= 1;
        // wait for t_STAB
        DelayMs(100);
        // set ADON bit to 1 again to start conversion
        ADC2->CR2 |= 1;
        // set CONT bit to 1 to setup for contiuous conversion
        // ADC2->CR2 |= 2;
    }
}

/*******************************************************************************
 * Service Name: ADC_conversionDone
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): module       - ADC module number
 *                  channel      - Channel number to check if it finished conversion
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: boolean
 * Description: Check whether a channel has finished a sample conversion.
 ********************************************************************************/
boolean ADC_conversionDone(module, channel)
{
    // check bit 1 EOC,
    // 0 -> Conversion is not done, 1-> Conversion complete

    if (module == 1)
        return (ADC1->SR & 2) != 0;
    else if (module == 2)
        return (ADC2->SR & 2) != 0;
}

/*******************************************************************************
 * Service Name: ADC_getData
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): module       - ADC module number
 *                  sequencer    - Sample sequencer number in that module
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: int - Result from ADC conversion
 * Description: Obtain the converted data from the register.
 ********************************************************************************/
int ADC_getData(module, channel)
{
    if (module == adc1)
        return (ADC1->DR) * 1000 / 0xfff;
    else if (module == adc2)
        return (ADC2->DR) * 1000 / 0xfff;
}