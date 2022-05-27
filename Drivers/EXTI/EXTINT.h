#ifndef _EXTINT
#define _EXTINT

#include "../../Includes/stm32/stm32f10x.h"
#include "../GPIO/_HAL_GPIO.h"
#include "../../Includes/Std_Types.h"		/* 
																									Includes the generic types to 
																									be used
																							 */

#define EXTI_LINES_NUM 7

typedef enum
{
	FALLING,
	RISING,
	ON_CHANGE
} triggeringEdge;

typedef enum
{
	PULL_UP,
	PULL_DOWN
} state;

typedef struct
{
	GPIO_TypeDef* PORT;
	uint32_t PIN;
	triggeringEdge interrupt_edge;
	state default_state;
	void (*intHandler)(void);
} _EXTINTType;

static void (*EXTI_Handler[EXTI_LINES_NUM])(void);

void _EXTINT_init(GPIO_TypeDef* PORT, uint32_t PIN, triggeringEdge interrupt_edge, state default_state, void (*intHandler)(void));

#endif