///*
 //* UART_switch.c
 //*
 //* Created: 22-06-21 오전 10:44:49
 //*  Author: PKNU
 //*/ 
//
//#include <avr/io.h>
//#include <avr/interrupt.h>
//
//volatile unsigned char TX_flag = 0;
//volatile char TX_data = 0;
//
//SIGNAL(INT4_vect)
//{
	//cli();
	//TX_data = '0';
	//TX_flag = 1;
	//sei();
//}
//SIGNAL(INT5_vect)
//{
	//cli();
	//TX_data = '1';
	//TX_flag = 1;
	//sei();
//}
//SIGNAL(INT6_vect)
//{
	//cli();
	//TX_data = '2';
	//TX_flag = 1;
	//sei();
//}
//
//SIGNAL(INT7_vect)
//{
	//cli();
	//TX_data = '3';
	//TX_flag = 1;
	//sei();
//}
//
//
//void putch(unsigned char data)
//{
	//while((UCSR0A & 0x20) == 0);	//	전송 준비되ㅣ기 전까지 대기
	//UDR0 = data;
	//UCSR0A |= 0x20;
//}
//
//void putch_Str(char *str)
//{
	//unsigned char i = 0;
	//while(str[i]!='\0')
	//putch(str[i++]);
//}
//
//int main(void)
//{
	//DDRE = 0x02;	//Rx(입력 0), Tx(출력 1), SW 0~3 입력
	//
	//UCSR0A = 0x00;
	//UCSR0B = 0x18;	//Rx, Tx Enable
	//UCSR0C = 0x06;	//비동기 방식, No parity bit, 1 stop bit
	//UBRR0H = 0x00;
	//UBRR0L = 0x03;	// 115200 bps / 2
	//
	//EIMSK = 0xF0;	//인터럽트 4,5,6,7 허용
	//EICRB = 0xFF;	//인터럽트 4,5,6,7 상승엣지에서 동작
	//EIFR = 0xF0;	//인터럽트 4,5,6,7 플래그 클리어
	//
	//sei();
	//while(1)
	//{
		//if(TX_flag == 1)
		//{
			//putch_Str("\n\r Input Switch : ");
			//putch(TX_data);
			//TX_flag = 0;
		//}
	//}
//}