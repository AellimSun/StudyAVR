/*
 * UART_echo.c
 *
 * Created: 22-06-21 오전 11:21:04
 *  Author: PKNU
 */ 
#include <avr/io.h>

void putch(unsigned char data)
{
	while((UCSR0A & 0x20) == 0);	//UDRE0 : 전송 준비가 되면 1인 비트(0x20), 전송준비 되기 전까지 대기
	//while(UDRE0 == 0);	//UDRE0 : 전송 준비가 되면 1인 비트(0x20), 전송준비 되기 전까지 대기	//안됨 ㅜ
	UDR0 = data;					//UDR0 : H - 수신된 데이터 저장, L - 전송될 데이터 저장
	UCSR0A |= 0x20;					//UDRE0 비트
}

unsigned char getch()
{
	unsigned char data;
	while((UCSR0A & 0x80) == 0);	//RXC0 : 데이터 받으면 1인 비트(0x80), 데이터 받을 때까지 대기
	//while(RXC0 == 0);	//RXC0 : 데이터 받으면 1인 비트(0x80), 데이터 받을 때까지 대기
	data = UDR0;					//UDR0 : H - 수신된 데이터 저장, L - 전송될 데이터 저장
	UCSR0A |= 0x80;					//RXC0 비트
	
	return data;
}

int main(void)
{
	unsigned char text[] = 
	"\r\nWelcome! edgeiLab\r\n USART 0 Test Program.\r\n";
	
	unsigned char echo[] = "ECHO >> ";
	unsigned char i = 0;
	
	DDRE = 0xFE;			// Rx(입력 0), Tx(출력 1)
	
	UCSR0A = 0x00;
	//UCSR0B = (1 << RXEN0) | (1 << TXEN0) ;			// Rx, Tx Enable / 0x18
	UCSR0B = 0x18;			// Rx, Tx Enable / 0x18
	//UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);			// 비동기방식(UMSEL0 = 0), NoParityBit(UPM01 = 0, UPM00 = 0), 1 Stop Bit / 0x06
	UCSR0C = 0x06;			// 비동기방식(UMSEL0 = 0), NoParityBit(UPM01 = 0, UPM00 = 0), 1 Stop Bit / 0x06
	
	UBRR0H = 0x00;
	UBRR0L = 0x03;
	
	while(text[i] != '\0')
	{
		putch(text[i++]);
	}
	i = 0;
	while(echo[i] != '\0')
	{
		putch(echo[i++]);
	}
	while(1)
	{
		putch(getch());
	}
	
}