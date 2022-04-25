
#include "ADC.h"

/*******************************************************************************
* Service Name: ADC_init
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ADC_Confiration -  configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initialize the ADC module.
********************************************************************************/
void ADC_init(ADC_Confiration)
{
    
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

}

/*******************************************************************************
* Service Name: ADC_getData
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): module       - ADC module number
*                  sequencer    - Sample sequencer number in that module
* Parameters (inout): None
* Parameters (out): None
* Return value: conversionResult - Result from ADC conversion
* Description: Obtain the converted data from the register.
********************************************************************************/
conversionResult ADC_getData(module, channel)
{

}