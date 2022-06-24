///*
 //* keypad_test.c
 //*
 //* Created: 22-06-23 오후 4:06:56
 //*  Author: PKNU
 //*/ 
//
//#define F_CPU 7372800
//#include <avr/io.h>
//#include <util/delay.h>
//
//int main()
//{
	//DDRA = 0xF8;	//상위 4비트 출력, 하위 4비트 입력
	//DDRE = 0xFF;
	//
	//unsigned char FND_DATA_TBL []={0x3F,0X06,0X5B,0X4F,0X66,0X6D,
									//0X7C,0X07,0X7F,0X67,0X77,0X7C,
									//0X39,0X5E,0X79,0X71,0X08,0X80};
	//
	//while(1)
	//{
		//PORTA = 0xF8;	//	0b 1111 1111
		//if(PINA = 0xFE)	PORTE = FND_DATA_TBL[1];
		//else if(PINA = 0xFD) PORTE = FND_DATA_TBL[2];
		//else if(PINA = 0xFB) PORTE = FND_DATA_TBL[3];
		//_delay_ms(10);
		//
		//
		//PORTA = 0xEF;	//  0b 1110 1111
		//if(PINA = 0xEE)	PORTE = FND_DATA_TBL[4];
		//else if(PINA = 0xED) PORTE = FND_DATA_TBL[5];
		//else if(PINA = 0xEB) PORTE = FND_DATA_TBL[6];
		//_delay_ms(10);
		//
		//
		//PORTA = 0xDF;	//	0b 1101 1111
		//if(PINA = 0xDE)	 PORTE = FND_DATA_TBL[7];
		//else if(PINA = 0xDD)  PORTE = FND_DATA_TBL[8];
		//else if(PINA = 0xDB)  PORTE = FND_DATA_TBL[9];
		//_delay_ms(10);
		//
		//
		//PORTA = 0xBF;	//	0b 1011 1111
		//if(PINA = 0xBE);	//*
		//else if(PINA = 0xBD)  PORTE = FND_DATA_TBL[0];
		//else if(PINA = 0xBB);	//#
		//_delay_ms(10);
		//
	//}
//}