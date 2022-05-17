#ifndef _EXTINT
#define _EXTINT

#include "stm32f10x.h"
#include "gp_drive.h"

#define EXTI_LINES_NUM 7



typedef enum {
	FALLING,
	RISING,
	ON_CHANGE
}triggeringEdge;

typedef enum{
	PULL_UP,
	PULL_DOWN
}state;


typedef struct{
	unsigned short PORT;
	unsigned short PIN;
	triggeringEdge interrupt_edge;
	state default_state;
	void (*intHandler)(void);
}_EXTINTType;

static void (*EXTI_Handler[EXTI_LINES_NUM])(void);

void _EXTINT_init(unsigned short PORT,unsigned short PIN, triggeringEdge interrupt_edge, state default_state, void (*intHandler)(void));




#endif