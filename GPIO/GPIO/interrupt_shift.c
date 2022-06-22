///*
 //* interrupt_shift.c
 //*
 //* Created: 22-06-20 오전 11:52:33
 //*  Author: PKNU
 //*/ 
//#define F_CPU 7372800
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//
//volatile unsigned char shitf_flag = 1;
//
//SIGNAL(INT4_vect)
//{
	//cli();
	//shitf_flag = 1;	//오른쪽
	//sei();
//}
//SIGNAL(INT5_vect)
//{
	//cli();
	//shitf_flag = 2; //왼쪽
	//sei();
//}
//int main(void)
//{
	//DDRA = 0xFF;
	//DDRE = 0x00;
	//
	//EIMSK = (1 << INT4) | (1 << INT5);
	//EICRB = (1 << ISC41) | (1 << ISC40) | (1 << ISC50) | (1 <<ISC51);
	//
	//int portData = 0x01;
	//sei();
	//while(1)
	//{
		//if(shitf_flag == 1)`
		//{
			//if(portData == 0x80)	portData = 0x01;
			//else					portData = portData << 1;
				//
		//}
		//else if(shitf_flag == 2)
		//{
			//if(portData == 0x01)	portData = 0x80;
			//else					portData = portData >> 1;
		//}
		//PORTA = portData;
		//_delay_ms(500);
	//}
	//return 0;
//}