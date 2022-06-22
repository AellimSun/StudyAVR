///*
 //* TimerCounter_LED.c
 //*
 //* Created: 22-06-22 오전 10:16:41
 //*  Author: PKNU
 //*/ 
//
//#define F_CPU 7372800UL
//#include <avr/io.h>
//#include <avr/interrupt.h>
//
//volatile unsigned char LED_Data = 0x00;
////unsigned char timer1Cnt = 0;	//
//
//int main(void)
//{
	//DDRC = 0xFF;
	//
	//TCCR1A = 0x00;						//normal port/ OCnA/OCnB/OCnnC 분리
	//TCCR1B |= (1 << CS12);				//프리스케일 256
	//TCNT1 = 36736;							//초기값 2^16 - 28800 = 65536 - 28800
	//
	//TIMSK |= (1 << TOIE1);					//time interrupt 1 설정
	//TIFR |= (1 << TOV1);						//
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
//SIGNAL(TIMER1_OVF_vect)
//{
	//cli();
	//
	//TCNT1 = 36736;							//초기값 2^16 - 28800 = 65536 - 28800
	//
	//if(LED_Data == 0xFF)	LED_Data = 0;
	//LED_Data++;
	//
	////timer1Cnt++;
	//
	////if(timer1Cnt == 127)
	////{
		////LED_Data++;
		////if(LED_Data > 0x0F)	LED_Data = 0;
		////
		////timer1Cnt = 0;
	////}
	//
	//
	////timer1Cnt = 0;
	//
	//sei();
//}