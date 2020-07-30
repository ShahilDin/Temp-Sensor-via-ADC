/*
 * ACD 4.0 LDR.c
 *
 * Created: 16/02/2020 12:04:22 PM
 * Author : bulle
 */ 

#define F_CPU 8000000UL // Clock SpeedThis is a macro that will be used by the compiler to calculate delay loops, and states it to be 8MHz, without this line the program defaults to some other value (1000000) and all the timing would be wrong.
#include <util/delay.h> // included to use delay function
#include <avr/io.h> // include the chip

void setup(void);

#define startcon ADCSRA |= (1<<ADSC) // starting conversion 
#define display_ PORTC // 8 seg display
#define Heater_ON PORTD |= (1<<PD7) // turning on bit 7
#define Heater_OFF PORTD &= ~(1<<PD7) // Turning off bit 7 
 
int main(void)
{
	
	 
 setup();



    while (1) 
    {
		 
		startcon; // start conversion
	     while (startcon)
		 {
			// When there is zero light source the 7 seg show 00 but as we show light to the LDR it increases
			display_ =ADCH; // display it on 7 seg 
					 
			if (ADCH <= 0x07) // if its less or = to 7 then
			{
				Heater_ON; // turn on heater
			
			}
			else 
			{
				Heater_OFF; // heater off
			
			}
		
		 }
		  
		
		  
		  
		
	}
    
}

void setup(void)
{
	DDRC=0xFF; // Setting PORTC as outputs(LED)
	PORTC=0x00;// Setting PORTA as inputs (Switches)
	DDRD=0xFF; // as ouput as heater led is on PORTD 


	ADMUX |= (1<< REFS0) | (1<<ADLAR)  ; // AVV with external cap at  as REF, Left Adjusted , ADC0
	
	ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1)| (1<<ADPS0) ; // Enable ADC .. 128 Prescaler 
	
	
	
	
	
}







