///*
 //* interrupt2.c
 //*
 //* Created: 22-06-20 오전 10:39:33
 //*  Author: PKNU
 //*/ 
//#define F_CPU 7372800
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//
//volatile unsigned char flag = 0;
//
//SIGNAL(INT4_vect)
//{
	////cli();				//전체 인터럽트 금지
	////PORTA = ~PORTA;		//interrupt는 간단한 작업 후 main에 복귀하도록!
	//flag = ~flag;
	////sei();				//전체 인터럽트 허용
//}
//
//int main()
//{
	//DDRA = 0xFF;
	//DDRE = 0x00;
//
	//EIMSK = 1 << INT4;						//int4활성화
	//EICRB = 1 << ISC41;						//하강엣지 설정
	//
	//int portData = 0x01;
	//PORTA = portData;
//
	//sei();
	//
	//while(1)
	//{
		//if(flag){}
		//else
		//{
			//if(portData == 0xFF)
			//{
				//portData = 0x00;
			//}
			//else
			//{
				//portData = portData << 1 | 0x01;
			//}
			//PORTA = portData;
		//}
		//_delay_ms(500);
	//}
	//return 0;
//}