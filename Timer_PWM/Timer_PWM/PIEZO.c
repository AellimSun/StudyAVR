/*
 * PIEZO.c
 *
 * Created: 22-06-22 오후 5:21:01
 *  Author: PKNU
 */ 

//

#define F_CPU 7372800
#include <avr/io.h>
#include <util/delay.h>

unsigned int DoReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046};
	
int main(void)
{
	unsigned char piano = 0;
	
	DDRB = 0x80;
	
	TCCR1A = (1 << COM1C1) | (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS30);		//
	
}