///*
 //* interrupt.c
 //*
 //* Created: 22-06-20 오전 9:58:29
 //*  Author: PKNU
 //*/ 
//
//#define F_CPU 7372800
//#include <avr/io.h>
//#include <util/delay.h>
//#include <avr/interrupt.h>
//
//volatile unsigned char count = 0;
//
//SIGNAL(INT0_vect)
//{
	//count++;
	//PORTA = count;
//}
//int main(void)
//{
	//DDRD = 0X00;
	//DDRA = 0XFF;
	//EIMSK = 1 << INT0;							//(EIMSK = 0X01;	//INT0 활성화)
	//EICRA = (1 << ISC01 | 1 << ISC00);	//	EICRA = 0X03;	//0b 0000 00(**)
	//sei();
	//
	//while(1){}
		//
	//return 0;
//}