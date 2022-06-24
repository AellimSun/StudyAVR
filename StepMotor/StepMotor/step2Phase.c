///*
 //* step2Phase.c
 //*
 //* Created: 22-06-23 오후 3:06:19
 //*  Author: PKNU
 //*/ 
//#define F_CPU 7372800
//#include <avr/io.h>
//#include <util/delay.h>
//
//int main()
//{
	//unsigned char i;
	//
	//DDRB = 0x20;	//motor1_en 출력포트 설정
	//DDRD = 0xF0;	// Step0~step3 출력포트 설정
	//PORTB &= ~0x20;	// M1 disable, DC motor 정지
	//
	//while(1)
	//{
		//for(i = 0; i <12 ; i++)
		//{
			//PORTD = 0x30;		//1step
			//_delay_ms(500);
			//PORTD = 0x90;		//2step
			//_delay_ms(500);
			//PORTD = 0xC0;		//3step
			//_delay_ms(500);
			//PORTD = 0x60;		//4step
			//_delay_ms(500);
		//}
		//_delay_ms(1000);
	//}
//}