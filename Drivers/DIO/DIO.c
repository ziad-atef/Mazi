
#include "DIO.h"

/************************************************************************************
* Service Name: Dio_ReadChannel
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ChannelId -  ID of the channel(pin) required to read from
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType - voltage level on the channel (HIGH or LOW)
* Description: Read Digital value on the required input channel and return it
************************************************************************************/
Dio_LevelType Dio_ReadChannel(ChannelId)
{

}

/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ChannelId -  ID of the channel(pin) required to write on
*                  Level -  Value to be written(HIGH or LOW)
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Write provided voltage level to the mentioned channel
************************************************************************************/
void Dio_WriteChannel(ChannelId,Level)
{

}