 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for STM32 Microcontroller - Port Driver.
 *
 * Author: 
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/

#include "stm32f10x.h"                         /* 
																									Device header which includes 
																									all the definitions of the 
																									device registers
																							 */
#include "../../../Includes/Std_Types.h"			 /* 
																									Includes the generic types to 
																									be used
																							 */
#include "../../../Includes/Common_Macros.h"	 /* 
																									Includes important macros to 
																									be used
																							 */

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
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): PortConfigiration -  configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initialize ALL ports and port pins with the configuration set pointed 
*              to by the parameter ConfigPtr
************************************************************************************/
void Port_Init(PortConfigiration);


/************************************************************************************
* Service Name: Port_SetPinMode
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port pin Id number
*                  Mode  - New Port Pin mode to be set on port pin. 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode.  
************************************************************************************/
void Port_SetPinMode(uint8 Pin,uint8 Mode); 



/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
//Here add any extern that will be used

#endif /* PORT_H */