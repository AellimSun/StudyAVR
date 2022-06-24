/*
 * PIEZO_Switch.c
 *
 * Created: 22-06-23 오전 10:12:02
 *  Author: PKNU
 */ 

#define F_CPU 7372800UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned int DoReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046};
volatile unsigned char sound_flag = 1;

int main()
{
	DDRE = 0x08;	//PE3 출력
	
	//CTC(모드 12), 분주비 1                                                                                                                              
	TCCR3A = 0x00;
	TCCR3B = (1<<CS30) | (1 << WGM32) | (1 << WGM33);
	TCCR3C = 0x00;	//
	TCNT3 = 0x0000;	//타이머3 카운터 초기화
	
	EICRB = 0xFF;
	EIMSK = 0xF0;	//int4,5,6,7 활성화
	EIFR = 0xF0;	//int4,5,6,7 플래그 클리어
	sei();
	
	while(1)
	{
		if(sound_flag)
		{
			_delay_ms(2000);
			TCCR3A = 0x00;	//부저소리 끔
			sound_flag = 0;
		}
	}
}

SIGNAL(INT4_vect)
{
	cli();
	ICR3 = 7372800/DoReMi[0]/16;	//도 파장
	
	TCCR3A = 0x40;		//PE3로 출력
	sound_flag = 1;		//부저음 발생
	sei();
}
SIGNAL(INT5_vect)
{
	cli();
	ICR3 = 7372800/DoReMi[1]/16;	//레 파장
	TCCR3A = 0x40;		//PE3로 출력
	sound_flag = 1;		//부저음 발생
	sei();
}
SIGNAL(INT6_vect)
{
	cli();
	ICR3 = 7372800/DoReMi[2]/16;	//미 파장
	TCCR3A = 0x40;		//PE3로 출력
	sound_flag = 1;		//부저음 발생
	
	
	sei();
}
SIGNAL(INT7_vect)
{
	cli();
	ICR3 = 7372800/DoReMi[3]/16;	//레 파장
	TCCR3A = 0x40;		//PE3로 출력
	sound_flag = 1;		//부저음 발생
	
	sei();
}