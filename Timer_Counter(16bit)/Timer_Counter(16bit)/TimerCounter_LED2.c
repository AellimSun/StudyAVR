///*
 //* TimerCounter_LED2.c
 //*
 //* Created: 22-06-22 오전 11:50:00
 //*  Author: PKNU
 //*/ 
//
//#define F_CPU 7372800UL
//#include <avr/io.h>
//#include <avr/interrupt.h>
//
//volatile unsigned char LED_Data = 0x00;
//
//int main()
//{
	//DDRC = 0xFF;
	//
	//TCCR3A = 0x00;							//normal모드
	//TCCR3B = (1 << CS32) | (1 << CS30);		//1024분주
	//TCNT3 = 58336;							//65536 - (7372800/1024)
	//
	//ETIMSK |= (1<<TOIE3);					//타이머 3번 enable
	//ETIFR |= (1<<TOV3);						//타이머 3이 발생하는 인터럽트 플래그 저장 레지스터
	//
	//
	//sei();
	//
	//while(1)
	//{
		//PORTC = LED_Data;
	//}
	//return 0;
//}
//
//SIGNAL(TIMER3_OVF_vect)
//{
	//cli();
	//
	//TCNT3 = 58336;
	//LED_Data++;
	//
	//if(LED_Data > 0x0F) LED_Data = 0;
	//
	//sei();
//}