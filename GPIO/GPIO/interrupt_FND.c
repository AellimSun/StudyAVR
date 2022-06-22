///*
 //* interrupt_FND.c
 //*
 //* Created: 22-06-20 오후 12:25:30
 //*  Author: PKNU
 //*/ 
//
//#define F_CPU 7372800
//
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>
//
//volatile unsigned char down_flag = 1;
//
//SIGNAL(INT4_vect)
//{
	//down_flag = 0; // 초기화
//}
//SIGNAL(INT5_vect)
//{
	//down_flag = 1; // 시작
//}
//
//int main(void)
//{
	//DDRA = 0xFF;
	//DDRE = 0x00;
	//
	//EIMSK = (1 << INT4) | (1 << INT5);	//INT4, INT5번 활성화
	//EICRB = (1 << ISC41) | (1 << ISC40) |(1 << ISC51) |(1 << ISC50);	// 상승엣지
	//
	//unsigned char fndData_TBL[] = {0x3F,0X06,0X5B,0X4F,0X66,0X6D, 0X7D,0X27, 0X7F, 0X6F};
	//
	//int idx = 0;	//fndData_TBL 인덱스에 사용할 변수
	//sei();
	//
	//while(1)
	//{
		//if(down_flag == 1)					//시작
		//{
			//if(idx == 9) idx = 0;
			//else idx++;
		//}
		//else if(down_flag == 0)				//초기화
		//{
			//idx = 0;
		//}
		//PORTA = fndData_TBL[idx];
		//_delay_ms(400);
	//}
	//return 0;
//}