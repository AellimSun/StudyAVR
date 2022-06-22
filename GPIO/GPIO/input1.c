///*
 //* input1.c
 //*
 //* Created: 22-06-17 오후 3:20:14
 //*  Author: PKNU
 //*/ 
//#define F_CPU 7372800UL
//#include <avr/io.h>
//#include <util/delay.h>
//
//int main(void)
//{
	//DDRD = 0X00;	//PORTD 입력
	//DDRA = 0XFF;	//PORTA 출력
	//int input;
	//while(1)
	//{
		//input = PIND;	//PORTD 입력값이 0X01이면 PORTA의 0번비트 출력
		//if(PIND!=0x00)
		//{
			////_delay_ms(200);	//delay로 채터링 처리
			//PORTA = input;
			//_delay_ms(500);
			//PORTA = 0x00;
		//}
	//}
	//return 0;
//}