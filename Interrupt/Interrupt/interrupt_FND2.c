///*
 //* interrupt_FND2.c
 //*
 //* Created: 22-06-20 오후 2:10:08
 //*  Author: PKNU
 //*/ 
//#define F_CPU 4342800
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//
//volatile unsigned char Time_Stop = 0;
//
//SIGNAL(INT5_vect)
//{
	//Time_Stop = ~Time_Stop;
//}
//
//int main(void)
//{
	//DDRA = 0xff;
	//DDRE = 0x00;
	//
	//EIMSK = 1 << INT5;
	//EICRB = (1 << ISC50) | (1 << ISC51);
	//
	//unsigned char FND_Data_TBL[]= {0x3F,0X06,0X5B,0X4F,0X66,0X6D,
								  //0X7C,0X07,0X7F,0X67,0X77,0X7C,
								  //0X39,0X5E,0X79,0X71,0X08,0X80};
	//int idx = 0;
	//
	//sei();
	//while(1)
	//{
		//if(Time_Stop == 0)
		//{
			//idx++;
			//if(idx==1) idx = 0;
		//}
		//PORTA = FND_Data_TBL[idx];
		//_delay_ms(500);
	//}
	//
	//return 0;
//}