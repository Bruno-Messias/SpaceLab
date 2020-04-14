/*
 * Button_Holder.c
 *
 * This project contains a function that hold 
 * the pressed button until press again.
 *
 * Device: ATMEGA328P(Arduino UNO)
 *
 * Created: 14/04/2020 08:38:00
 * Author : Bruno
 */ 

// -- Frequency --
#define F_CPU 16000000			//Define clock cycle of the device

// -- Librarys --
#include <avr/io.h>
#include <util/delay.h>

// -- Macros --
#define set_bit(reg,bit)		(reg |= (1<<bit))		//Creating macros to easy use
#define reset_bit(reg,bit)		(reg &= ~(1<<bit))
#define read_byte(reg,bytex)	(reg && bytex)
																			
// -- Prototype --
int button_hold(unsigned char regi, unsigned char bits);

// -- Main -- 
int main (void)
{
	
	reset_bit(DDRB,PORTB4); //Setando PORTB4 como entrada(Pino 12 do arduino)
	set_bit(DDRB,PORTB5);	//Setando	PORTB5 como saída(Pino 13 /LED) 
    
    while (1) 
    {
		if (button_hold(PINB,(1<<PORTB4)))
		{
			set_bit(PORTB,PORTB5);
		}
		else
		{
			reset_bit(PORTB,PORTB5);
		}
	}	

}

// -- Function Button_holder --
int button_hold(unsigned char regi, unsigned char bits)
{
	while(1)
	{
		if (read_byte(regi,bits))
		{
			while(read_byte(regi,bits))
			{
				return 0;
			}
			
			while(1)
			{
				return 1;
				if (read_byte(regi,bits))
				{
					break;
				}
			}
		}
		
		return 0;
			
	}
}


//Test
/*
if(read_bit(PINB,PORTB4)
{
	set_bit(PORTB,PORTB5);
}
else
{
	reset_bit(PORTB,PORTB5);
}


*/