#ifndef _EXTINT
#define _EXTINT

#include "stm32f10x.h"
#include "gp_drive.h"

#define EXTI_LINES_NUM 7

/**
 * @brief 
 * Interrupt Trigger Mode
 * 
 */

typedef enum {
	FALLING,
	RISING,
	ON_CHANGE
}triggeringEdge;

/**
 * @brief State of input pin
 * 
 */

typedef enum{
	PULL_UP,
	PULL_DOWN
}state;

/**
 * @brief Struct contains the data of the pin with its handler
 * 
 */
typedef struct{
	unsigned short PORT;
	unsigned short PIN;
	triggeringEdge interrupt_edge;
	state default_state;
	void (*intHandler)(void);
}_EXTINTType;

/**
 * @brief Pointer to interrupt handler function 
 * 
 */

static void (*EXTI_Handler[EXTI_LINES_NUM])(void);

/**
 * @brief  Configure the pin as EXTI line
 * 
 * @param PORT Port of the pin
 * @param PIN  Pin number 
 * @param interrupt_edge Trigerring edge of the interrupt
 * @param default_state Input pin state
 * @param intHandler Interrupt handler function
 *
 */

void _EXTINT_init(unsigned short PORT,unsigned short PIN, triggeringEdge interrupt_edge, state default_state, void (*intHandler)(void));




#endif