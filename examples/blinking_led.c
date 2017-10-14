#include <MKL25Z4.h>
#include "smartstick.h"
void wait (void);

int main(void){
	SystemCoreClockUpdate();
	initialize_LED();
	
	while (1)
	{
		LED(RED_LED,ON);
		wait();
		LED(RED_LED,OFF);
				
		wait();
		LED(GREEN_LED,ON);
		wait();
		LED(GREEN_LED,OFF);
				
		wait();
		LED(BLUE_LED,ON);
		wait();
		LED(BLUE_LED,OFF);
				
		wait();

	}
	
}


