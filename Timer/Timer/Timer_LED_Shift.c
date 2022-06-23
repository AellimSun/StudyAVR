///*
 //* Timer_LED_Shift.c
 //*
 //* Created: 22-06-21 오후 4:08:25
 //*  Author: PKNU
 //*/ 
//
//#include <avr/io.h>
//#include <avr/interrupt.h>
//
//volatile unsigned char LED_Data = 0x01;
//unsigned char timer2Cnt = 0, Shift_Flag = 0;
//
//SIGNAL(TIMER2_OVF_vect);
//
//int main()
//{
	//DDRC = 0xFF;
	//
	//TCCR2 = 0x05;	// 분주비 1024
	//
	//TCNT2 = 184;	//7372800/1024/(255-x) = 0.01s;
	//TIMSK = 0x40;
	//TIFR |=1 << TOV2;
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
//SIGNAL(TIMER2_OVF_vect)
//{
	//cli();
	//TCNT2 = 184;
	//timer2Cnt++;
	//
	//if(timer2Cnt == 50)
	//{
		//if(Shift_Flag == 0)
		//{
			//LED_Data <<= 1;
			//if(LED_Data == 0x80)	Shift_Flag = 1;
		//}
		//else
		//{
			//LED_Data >>= 1;
			//if(LED_Data == 0x01)	Shift_Flag = 0;
		//}
		//timer2Cnt = 0;
	//}
	//sei();
//}