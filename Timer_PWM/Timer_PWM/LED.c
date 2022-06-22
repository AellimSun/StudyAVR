///*
 //* LED.c
 //*
 //* Created: 22-06-22 오후 4:26:45
 //*  Author: PKNU
 //*/ 
//
//#define F_CPU 7372800UL
//#include <avr/io.h>
//#include <util/delay.h>
//
//int main(void)
//{
	//
	//unsigned char Light = 0;
	//
	//DDRB = 0x10;		//포트B 5번 핀 출력설정
	//
	//TCCR0 = (1 << WGM00) | (1 << COM01) | (1 << COM00) |(1 << CS02) | (1 << CS01);	// PC PWM모드, 256 분주. OC0을 비교매치로 설정, botton(invert)
	//TCNT0 = 0;			//타이머0 카운터 초기화
	//
	//while(1)
	//{
		//for(Light = 0; Light < 255; Light++)		//밝기 점차 감소(업카운팅시 셋, 다운카운팅시 클리어)
		//{
			//OCR0 = Light;
			//_delay_ms(10);
		//}
		//for(Light = 255; 0 < Light; Light--)		//밝기 점차 증가
		//{
			//OCR0 = Light;
			//_delay_ms(10);
		//}
	//}
//}