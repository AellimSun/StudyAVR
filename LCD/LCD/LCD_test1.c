/*
 * LCD.c
 *
 * Created: 22-06-20 오후 2:54:13
 *  Author: PKNU
 */ 
#define F_CPU 7372800
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Lcd.h"
#include <stdio.h>

volatile unsigned char stop_flag = 0;
SIGNAL(INT0_vect)
{
	stop_flag = 1;
}
SIGNAL(INT1_vect)
{
	stop_flag = 0;
}

int main()
{
	Byte *str1;
	char buffer[16];
	Byte *intrrupt_MST = "Interrupt Occurred!";
	DDRA = 0xFF;
	DDRG = 0xFF;
	DDRD = 0x00;
	
	EIMSK = (1 << INT0) | (1 <<INT1);
	EICRA = (1 << ISC00) | (1 << ISC01)| (1 << ISC10) | (1 << ISC11);
	
	sei();
	
	Lcd_Init();
	Lcd_Clear();
	
	_delay_ms(100);
	
	while(1)
	{
		Lcd_Pos(0,0);
		Lcd_STR("Test");
		Lcd_Pos(1,0);
		Lcd_STR("9 x 9");
	
		_delay_ms(3000);
		
		int i = 2;
		int j = 0;
		while(i < 10)
		{
			while(j < 9)
			{
				if(stop_flag == 1)
				{
					//Lcd_Clear();
					Lcd_Pos(0,0);
					Lcd_STR(intrrupt_MST);
				}
				else if(stop_flag == 0)
				{
					j++;
				
					sprintf(buffer,"%d x %d = %d",i,j,i*j);
					str1 = buffer;
					Lcd_Clear();
					Lcd_Pos(0,0);
					Lcd_STR(str1);

					_delay_ms(1000);
				}
			}
			//if(stop_flag == 1)
			//{
				//Lcd_Clear();
				//Lcd_Pos(0,0);
				//Lcd_STR(intrrupt_MST);
				//_delay_ms(1000);
			//}
			//else if(stop_flag == 0)
			//{
				i++;
				j = 0;
			//}
		}
	}
	return 0;
}