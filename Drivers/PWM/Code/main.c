
#include "PWM.h"
int main()
{
	/* u need to configure pin tp be af */
	PWM_Init(PA8, 1024, 60000);
	PWM_Start(PA8, 10000);
	
	PWM_Init(PA6, 1024, 60000);
	PWM_Start(PA6, 10000);
	while(1)
	{
		
	}
	return 0;
}
