/*
 * step1_2Phase.c
 *
 * Created: 22-06-23 오후 3:32:56
 *  Author: PKNU
 */ 

//1,2상 혼합(2상-1상이 반복됨. 명령당 3.75도 회전

#define F_CPU 7372800
#include <avr/io.h>
#include <util/delay.h>

unsigned char Step[8] = {0x90,0x80,0xC0,0x40,0x60,0x20,0x30,0x10};
	
int main()
{
	unsigned char i, t =0;
	
	DDRB = 0x20;
	DDRD = 0xF0;
	PORTB &= ~0x20;	//DC motor 정지
	
	while(1)
	{
		for(i = 0; i <24; i++)
		{
			PORTD = Step[t];
			t++;
			if(t>7) t = 0;
			_delay_ms(500);
		}
	}
	
}