
#include "Port.h"

int main() 
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	return 0;
}
