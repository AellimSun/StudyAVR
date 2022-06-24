/*
 * Mini_Project.c
 *
 * Created: 22-06-24 오전 10:01:20
 * Author : PKNU
 */ 

#define F_CPU 7372800
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Lcd.h"

volatile unsigned char password[5] = "****";
volatile unsigned char in_password[5] = "****";

volatile unsigned char int_flag = 0;

unsigned char Step[8] = {0x90,0x80,0xC0,0x40,0x60,0x20,0x30,0x10};
unsigned int DoReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046};
	

//LCD

unsigned char KeyPad_out()
{
	while(1)
	{
		if(int_flag != 0) return 0;				//int4 발생시 탈출
		PORTA =	0X10;	//~0xEF;					//	0b 0001 0000
		_delay_ms(1);
		if(	(PINA & 0x02) == 0x02) return '1';		//	0b 0001 0011
		else if((PINA & 0x04) == 0x04) return '2';	//	0b 0001 0101
		else if((PINA & 0x08) == 0x08) return '3';	//	0b 0001 1001
		_delay_ms(10);
		
		
		PORTA =	0X20;	//~0xDF;					//	0b 0010 0000
		_delay_ms(1);
		if((PINA & 0x02) == 0x02)	return '4';		//	0b 0010 0011
		else if((PINA & 0x04) == 0x04) return '5';	//	0b 0010 0101
		else if((PINA & 0x08) == 0x08) return '6';	//	0b 0010 1001
		_delay_ms(10);
		
		
		PORTA =	0X40;	//~0xBF;					//	0b 0100 0000
		_delay_ms(1);
		if((PINA & 0x02) == 0x02)	 return '7';	//	0b 0100 0011
		else if((PINA & 0x04) == 0x04)  return '8';	//	0b 0100 0101
		else if((PINA & 0x08) == 0x08)  return '9';	//	0b 0100 1001
		_delay_ms(10);
		
		
		PORTA = 0X80;	//~0x7F;					//	0b 1000 0000
		_delay_ms(1);
		if((PINA & 0x04) == 0x04)  return '0';		//	0b 1000 0101
		_delay_ms(10);
	}
	//return 0;
}

unsigned char compare_passowrd(unsigned char* cp)
{
	for(char i = 0; i < 4 ; i++)
	{
		if(cp[i] != password[i]) return 0;
	}
	return 1;
}

void Ring_Buzzer(unsigned char mode)
{
	if(mode == 1)
	{
		for(unsigned char i = 0; i < 3; i++)
		{
			ICR3 = 7372800/DoReMi[i]/16;	//도 파장
			TCCR3A = 0x40;		//PE3로 출력
			_delay_ms(700);
		}
		TCCR3A = 0x00;	//부저소리 끔
	}
	else
	{
		for(unsigned char i = 0; i < 3; i++)
		{
			ICR3 = 7372800/DoReMi[0]/16;	//도 파장
			TCCR3A = 0x40;		//PE3로 출력
			_delay_ms(500);
			TCCR3A = 0x00;
			_delay_ms(200);
		}
	}
}

void Check_Password(unsigned char* pw)
{
	unsigned char result = compare_passowrd(pw);
	if(result)//맞으면/
	{
		for(unsigned char i = 0; i < 3; i++)
		{
			Lcd_Clear();
			_delay_ms(200);//LCD - Open 출력
			Lcd_Pos(0,0);
			Lcd_STR("OPEN");;
			_delay_ms(500);
		}
		
		Ring_Buzzer(1);//부저 울리기
		
		unsigned char t = 0;	// Stepmotor - 한바퀴 돌기
		for(char i = 0; i <96; i++)
		{
			PORTD = Step[t];
			t++;
			if(t>7) t = 0;
			_delay_ms(50);
		}
	}
	else  //틀리면 LCD - Error 출력
	{for(unsigned char i = 0; i < 3; i++)
		{
			Lcd_Clear();
			_delay_ms(200);
			Lcd_Pos(0,0);
			Lcd_STR("Error");;
			Ring_Buzzer(0);
			_delay_ms(500);
		}
	}
}

void keyscan(unsigned char* pw)
{
	for(char i = 0; i < 4; i++)
	{
		unsigned char tmp = KeyPad_out();
		if(tmp==0) return;
		pw[i] = tmp;
		//스위치 입력값 출력
		Lcd_Pos(1,0);
		Lcd_STR(pw);
		_delay_ms(150);
	}
}

void Init_Password(unsigned char* pw)
{
	for(char i = 0; i<4 ; i++)
	{
		pw[i]='*';
	}
}

void LCD_Press_Password()
{
	Init_Password(in_password);
	unsigned char result = compare_passowrd("****");
	
	if(result)	//패스워드 없으면 패스워드 설정창
	{
		New_Password();
	}
	if(int_flag != 0) return;
	Lcd_Clear();
	Lcd_Pos(0,0);	//패스워드 입력창
	Lcd_STR("Press Password");
	keyscan(in_password);
	if(int_flag != 0) return;
	Check_Password(in_password);
}

//UART

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

void putStr(char *str)
{
	while(*str != 0)
	{
		putch(*str);
		str++;
	}
}

void Uart_set_Passwors(unsigned char* pw)
{
	int i = 0;
	char tmp = 0;
	putch('\n');
	putch('\r');
	while(i < 4)
	{
		tmp = getch();
		putch(tmp);
		if(('0'<=tmp) && (tmp<='9'))	pw[i++] = tmp;
		else
		{
			putStr("\n\rInsert 0 ~ 9\n\r");
		}
	}
}

void UART_Press_Password()
{
	Init_Password(in_password);
	
	unsigned char result = compare_passowrd("****");
	if(result)
	{
		putStr("\n\rSet Password: ");

		Lcd_Clear();
		Lcd_Pos(0,0);
		Lcd_STR("\n\rSet Password!\n");
		
		Uart_set_Passwors(password);
		
		putStr("\n\rPassword set!\n");
	}
	
	putStr("\n\rPress Password!\n");
	Uart_set_Passwors(in_password);
	putStr("\n\rPassword pressed!\n");
	Check_Password(in_password);
}

void New_Password()
{
	if(!compare_passowrd("****")) Init_Password(password);
	Lcd_Clear();
	Lcd_Pos(0,0);
	Lcd_STR("Press New Password");
	keyscan(password);
	
	for(unsigned char i = 0; i < 3; i++)
	{
		Lcd_Clear();
		_delay_ms(200);
		Lcd_Pos(0,0);
		Lcd_STR("Password Changed!");
		_delay_ms(500);
	}
}

void Reset_Password()
{
	Lcd_Clear();
	Lcd_Pos(0,0);	//패스워드 입력창
	Lcd_STR("<<Reset Password>>");
	_delay_ms(1500);
	
	Lcd_Clear();
	Lcd_Pos(0,0);	//패스워드 입력창
	Lcd_STR("Press Password");
	Init_Password(in_password);
	keyscan(in_password);
	if(compare_passowrd(in_password)==1) New_Password();	//비밀번호 재설정
	else
	{
		for(unsigned char i = 0; i < 3; i++)
		{
			Lcd_Clear();
			_delay_ms(200);
			Lcd_Pos(0,0);
			Lcd_STR("Wrong Password!");
			_delay_ms(500);
		}
	}
}
SIGNAL(INT4_vect)
{
	//UART 통신 시작
	
	cli();
	
	if(int_flag == '4') int_flag = 0;
	else int_flag = '4';

	sei();
}

SIGNAL(INT5_vect)
{
	//UART 통신 시작
	
	cli();
	
	int_flag = '5';

	sei();
}

int main(void)
{
	//UART 통신핀 제외(pe)?
	
	DDRA = 0xF1;	//keypad 입출력
	
	DDRE = 0x08;	//부저 출력	- PWM핀 B 0x80 / CTC핀 E 0x08

	DDRC = 0xFF;	//LCD 출력제어
	DDRG = 0xFF;	//LCD 출력제어
	
	DDRD = 0xF0;	//step motor 출력제어
	DDRB = 0x20;	//step motor 출력제어
	PORTB &= ~0x20;	//DC motor 정지
	
	//CTC(모드12), 분주비 1
	TCCR3A = 0x00;
	TCCR3B = (1<<CS30) | (1 << WGM32) | (1 << WGM33);
	TCCR3C = 0x00;	//
	TCNT3 = 0x0000;	//타이머3 카운터 초기화
	
	//인터럽트 핀;
	EICRB = 0xFF;	//상승엣지에서 활성화
	EIMSK = 0x30;	//int4,5 활성화
	EIFR = 0x30;	//int4,5 플래그 클리어12
	
	//UART통신 설정
	DDRE |= 0x02;
	UCSR0A = 0x00;
	//UCSR0B = (1 << RXEN0) | (1 << TXEN0) ;			// Rx, Tx Enable / 0x18
	UCSR0B = 0x18;			// Rx, Tx Enable / 0x18
	//UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);			// 비동기방식(UMSEL0 = 0), NoParityBit(UPM01 = 0, UPM00 = 0), 1 Stop Bit / 0x06
	UCSR0C = 0x06;			// 비동기방식(UMSEL0 = 0), NoParityBit(UPM01 = 0, UPM00 = 0), 1 Stop Bit / 0x06
	
	UBRR0H = 0x00;
	UBRR0L = 0x03;
	
	Lcd_Init();
	Lcd_Clear();
	_delay_ms(100);
	sei();

	Lcd_Clear();
	Lcd_Pos(0,0);
	Lcd_STR("Program Start!");;
	Lcd_Pos(1,0);
	Lcd_STR(password);
	_delay_ms(2000);
	
	while (1)
	{
		if(int_flag == '4')
		{
			Lcd_Clear();
			Lcd_Pos(0,0);
			Lcd_STR("UART!");;
			UART_Press_Password();	//UART로 비밀번호 입력/설정
		}
		else if(int_flag == '5')
		{
			int_flag = 0;
			Reset_Password();
		}
		else
		{
			LCD_Press_Password();	//LCD로 비밀번호 입력/설정
		}
	}
}