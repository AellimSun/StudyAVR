///*
 //* LED2.c
 //*
 //* Created: 22-06-22 오후 5:03:00
 //*  Author: PKNU
 //*/ 
//
//// switch 입력에 따른 LED 밝기 제어
//
//#define F_CPU 7372800
//#include <avr/io.h>
//#include <avr/interrupt.h>
//
//volatile int Light = 0;
//volatile unsigned char Light_flag = 1;
//
//int main(void)
//{
	//DDRB = 0x80;	//포트B의 PIN7을 출력으로 설정(OC2)
	//DDRE = 0x00;	//포트E 입력으로 설정
	//
	//TCCR2 = (1 << WGM20) | (1 << COM21) | (1 << CS21);
	//TCNT2 = 0x00;	//timer 초기화
	//
	//EICRB = 0xFF;	//인터럽트 4,5,6,7 상승엣지 동작
	//EIMSK = 0xF0;	//인터럽트 4,5,6,7 enable
	//EIFR = 0xF0;	//인터럽트 4,5,6,7 플래그 클리어
	//
	//sei();
	//
	//while(1)
	//{
		//if(Light_flag)
		//{
			//OCR2 = Light;
			//Light_flag = 0;
		//}
	//}
	//return 0;
//}
//
//SIGNAL(INT4_vect)
//{
	//cli();
	//Light = 0;		//LED off
	//Light_flag = 1;
	//sei();
//}
//
//SIGNAL(INT5_vect)
//{
	//cli();
	//Light -= 51;	//LED 밝기 감소
	//if(Light < 0)	Light = 0;
	//Light_flag = 1;
	//sei();
//}
//
//SIGNAL(INT6_vect)
//{
	//cli();
	//Light += 51;	//LED 밝기 증가
	//if(Light > 255)	Light = 255;
	//Light_flag = 1;
	//sei();
//}
//
//SIGNAL(INT7_vect)
//{
	//cli();
	//Light = 255;	//LED ON
	//Light_flag = 1;
	//sei();
//}