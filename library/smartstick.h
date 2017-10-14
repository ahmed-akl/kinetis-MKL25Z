/* Prevention from multiple including the same memory map */
#if !defined(smartstick_H_)  /* Check if memory map has not been already included */
#define smartstick_H_
#endif

#define ON 0x1
#define OFF 0x0
#define GREEN_LED 0x1
#define RED_LED 0x2
#define BLUE_LED 0x3

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@ Functions @@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//@@@@@@@@@@@@@@@@@@@@@@@@@@ initialize_LED @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//It initializes the registers required associated with the LED pins
// PTB[18] is for RED LED
// PTB[19] is for GREEN LED
// PTD[1]  is fof Blue LED
void initialize_LED(void){
	SIM->SCGC5 |= (1<<10);  //clock for PORTB enabled
	SIM->SCGC5 |= (1<<9);  //clock for PORTA enabled
	SIM->SCGC5 |= (1<<12);  //clock for PORTD enabled
	
	// Pin Mux Control: 001 = Alternate 1
	PORTB->PCR[18] |= (1<<8);
	PORTB->PCR[19] |= (1<<8);
	PORTD->PCR[1] |= (1<<8);
	
	// Pins are configured as general-purpose output
	PTB->PDDR |= (1<<18);
	PTB->PDDR |= (1<<19);
	PTD->PDDR |= (1<<1);
	
	//Switching the LEDs off
	PTB->PSOR |= (1<<18);
	PTB->PSOR |= (1<<19);
	PTD->PSOR |= (1<<1);
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@ LED @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//This function switches the LED ON or OFF
// Note that the LEDs are switched ON when logic 0 is applied
void LED(char led, char state ){
	
	switch (led)
	{
		case RED_LED:
			if (state == ON) 
					{PTB->PCOR |= (1<<18);}
					else{PTB->PSOR |= (1<<18);}
			break;
					
		case GREEN_LED:
			if (state == ON) {PTB->PCOR |= (1<<19);}
					else{PTB->PSOR |= (1<<19);}
			break;
					
		case BLUE_LED:
			if (state == ON) {PTD->PCOR |= (1<<1);}
					else{PTD->PSOR |= (1<<1);}			
			break;
	}
				
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@ wait @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void wait (void)  {
  int  d;

  for (d = 0; d < 3000000; d++);             /* only to delay for LED flashes */
}
