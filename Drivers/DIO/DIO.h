/******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.h
 *
 * Description: Header file for STM32 Microcontroller - Dio Driver
 *
 * Author: 
 ******************************************************************************/

#ifndef DIO_H
#define DIO_H

/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/

//Here you should include any file you may need
#include "Std_Types.h"
#include "Common_Macros.h"


/*******************************************************************************
 *                                  Definitions                                *
 *******************************************************************************/
//Here you should add any #define that you may require in your work


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
//Here you should define any struct or typedef that may help you in your coding


/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/


/************************************************************************************
* Service Name: Dio_ReadChannel
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ChannelId -  ID of the channel(pin) required to read from
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType (HIGH or LOW)
* Description: Read Digital value on the required input channel and return it
************************************************************************************/
Dio_LevelType Dio_ReadChannel(ChannelId);

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
void Dio_WriteChannel(ChannelId,Level);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

#endif /* DIO_H */
