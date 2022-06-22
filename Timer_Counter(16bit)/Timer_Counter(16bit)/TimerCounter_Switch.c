///*
 //* TimerCounter_Switch.c
 //*
 //* Created: 22-06-22 오후 12:19:39
 //*  Author: PKNU
 //*/ 
//
////time/counter3 input capure pin => PE7
//
//
//#define F_CPU 7372800UL
//#include <avr/io.h>
//#include <avr/interrupt.h>
//
////unsigned char FND_DATA_TBL[]={0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7C,0X07,0X7F,0X67,0X77,0X7C,0X39,0X5E};
//unsigned char FND_DATA_TBL[]={0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7C,0X07,0X7F,0X67};
//
//volatile unsigned char time_s = 0;
//volatile unsigned char FND_flag = 0, edge_flag = 0;
//
//int main(void)
//{
	//DDRA = 0xFF;
	//DDRE = 0x00;
	//
	//DDRC = 0xFF;
	//
	//TCCR3A = 0x00;										//normal mode
	//TCCR3B = (1 << ICES3) | (1 << CS32) | (1 << CS30);	//
	//ETIMSK = 0x20;
	//ETIFR |= 1 << ICF3;
	//
	//sei();
	//
	//PORTA = FND_DATA_TBL[0];
	//
	//while(1)
	//{
		//PORTC = 0x00;
		//if(FND_flag)
		//{
			//if(time_s > 9) time_s = 0;
//
			//PORTA = FND_DATA_TBL[time_s]	;
			//FND_flag = 0;
		//}
	//}
	//return 0;
//}
//
//SIGNAL(TIMER3_CAPT_vect)
//{
	//cli();
	//
	//PORTC = 0x01;
	//
	//unsigned int count_check;
	//
	//if(edge_flag == 0)
	//{
		//TCCR3B = (1 << CS30) | (1 << CS32);		//상승엣지
		//TCNT3 = 0;
		//ICR3 = 0;			//ICR3을 0으로 초기화(하강까지 흐른)
		//edge_flag = 1;
	//}
	//else
	//{
		//TCCR3B = (1 << ICES3) | (1 << CS30) | (1 << CS32);		//하강엣지
		//count_check = ICR3;
		//time_s = count_check/7200;			//1s에 한 번 바뀜(7372800/1024)
		//edge_flag = 0;
		//FND_flag = 1;
	//}
		//
	//sei();
//}
//
////SIGNAL(TIMER3_OVF_vect)
////{
	//////TCNT3 = 58336;
	////time_s++;
	////if(time_s > 9) time_s = 0;
////}