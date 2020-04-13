/*
 * GccApplication1.c
 *
 * Created: 13/04/2020 18:51:02
 * Author : Bruno Messias
 */ 

//--Frequência --
#define F_CPU 16000000		//Definindo frequencia do cristal

// --Bibliotecas --
//#include <arduino.h> --> funções da IDE do arduino
#include <avr/io.h>
#include <util/delay.h>

#define set_bit(reg,bit)	(reg |= (1<<bit))
#define reset_bit(reg,bit)	(reg &= ~(1<<bit))


int main(void)
{
	set_bit(DDRB,PORTB5);		//Definindo saída no pino 13 ou PORTB5
	
    while (1) 
    {
		set_bit(PORTB,PORTB5);		//Ligando led
		_delay_ms(500);
		reset_bit(PORTB,PORTB5);	//Desligando led
		_delay_ms(500);
    }
}

