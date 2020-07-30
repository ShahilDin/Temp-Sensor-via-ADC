/*
 * Temp Sen with Heater ADC 3.0.c
 *
 * Created: 9/02/2020 9:57:18 PM
 * Author : bulle
 */ 

/*
 * Learning ADC 2.0.c
 *
 * Created: 9/02/2020 3:06:20 PM
 * Author : bulle
 */ 




#define F_CPU 8000000UL // Clock SpeedThis is a macro that will be used by the compiler to calculate delay loops, and states it to be 8MHz, without this line the program defaults to some other value (1000000) and all the timing would be wrong.
#include <util/delay.h> // included to use delay function
#include <avr/io.h> // include the chip

void setup(void);
 
int main(void)
{
	
	 
 setup();



    while (1) 
    {
		 
		
	      
		  
		  if(PINA&(1<<4)) // testing for pina 4 if true then completed 
		  {
			  PORTD=0b10000000; // turn on heater 
		  }
		  else
		  {
			  PORTD=0x00; // turning off heater
		  }
		  
		  
		  PORTC=ADCH; // PORCT will display the conversion on 8seg 
		
	}
    
}

void setup(void)
{
	DDRC=0xFF; // Setting PORTC as outputs(LED)
	PORTC=0x00;// Setting PORTA as inputs (Switches)
	DDRD=0xFF; // Heater is on port d so output
	DDRA=0x00;// for button input
	

		
	//ADMUX=0b01100010;  another way to write this is below
	//ADCSRA=0b10000111;
	ADMUX = (1<<REFS0) | (1<<ADLAR) | (1<<MUX1) | (1<<MUX0);// AAvcc , left adjusted , ADC3
	
	ADCSRA = (1<<ADEN) |(1<<ADSC) | (1<<ADATE) | (1<<ADPS2) |(1<<ADPS1) | (1<<ADPS0); // Enable ADC, Setting prescaler 128, Started conversion, AUTO enable triggers every pos edge
	
	
}







