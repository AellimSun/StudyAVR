///*
 //* UART_multiple.c
 //*
 //* Created: 22-06-21 오후 12:30:49
 //*  Author: PKNU
 //*/ 
//
//#include <avr/io.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//void putch(unsigned char data)
//{
	//while((UCSR0A & 0x20)==0);
	//UDR0 = data;
	//UCSR0A |= 0x20;
//}
//unsigned char getch()
//{
	//unsigned char data;
	//while((UCSR0A & 0x80)==0);
	//data = UDR0;
	//UCSR0A |= 0x80;
	//return data;
//}
//
//
//void putStr(char *str)
//{
	//while(*str != 0)
	//{
		//putch(*str);
		//str++;
	//}
//}
//
//int main(void)
//{
	//unsigned char text[] = "\r\nEnter a number : ";
	//unsigned char *inNumTmp;
	//unsigned int inNum;
		//
	//DDRE = 0xFE;
	//
	//UCSR0A = 0x00;
	//UCSR0B = 0x18;
	//UCSR0C = 0x06;
	//
	//UBRR0H = 0x00;
	//UBRR0L = 0x03;
	//
	//while(1)
	//{
		//putStr(text);
		//unsigned char input = getch();
		//unsigned int idx = 0;
		//unsigned char tmpInput[3]={};	//2자리 수까지
		//unsigned char tmpStr[20];
	//
		//while(input != 13)
		//{
			//if(idx == 3) return;
			//if(('1'<=input)&&(input<='9'))
			//{
				//tmpInput[idx++] = input;
				//putch(input);
			//}
			//else
			//{
				//putch(input);
				//putStr("\r\nPlease enter a number.\n");
				//putStr(text);
			//}
			//input = getch();
		//}
		//
		//tmpInput[idx] = '\0';
		//
		//inNum = atoi(tmpInput);
		//putch('\n');
//
		//putStr("\r\n Start~ \r\n");
		//
		//if(inNum < 10)	
		//{
			//for(int i = 1; i <10; i++)
			//{
				//sprintf(tmpStr, "\r%d x %d = %d\n", inNum, i, inNum * i);
				//putStr(tmpStr);
			//}
		//}
		//else
		//{
			//for(int i = 1; i <20; i++)
			//{
				//sprintf(tmpStr, "\r%d x %d = %d\n", inNum, i, inNum * i);
				//putStr(tmpStr);
			//}
		//}
		//
		//inNum = 0;
	//}
	//
	//return 0;
//}