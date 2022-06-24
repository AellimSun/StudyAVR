/*
 * tp.c
 *
 * Created: 22-06-23 오후 4:35:30
 *  Author: PKNU
 */ 
/*
 * keypad_test.c
 *
 * Created: 22-06-23 오후 4:06:56
 *  Author: PKNU
 */ 


/*

	PA0		--		 --
	PA1		C0		입력
	PA2		C1		입력
	PA3		C2		입력
	PA4		R0		출력
	PA5		R1		출력
	PA6		R2		출력
	PA7		R3		출력

*/




#define F_CPU 7372800
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA = 0xF1;	//상위 4비트 출력, 하위 4비트 입력		
	DDRB = 0xFF;	//LED
	DDRE = 0xFF;	//FND
	
	unsigned char FND_DATA_TBL []={ 0x3F,0X06,0X5B,0X4F,0X66,0X6D,
									0X7C,0X07,0X7F,0X67,0X77,0X7C,
									0X39,0X5E,0X79,0X71,0X08,0X80};
	//PORTE = 0x00;
	while(1)
	{
		PORTA =	0X10;	//~0xEF;								//	0b 0001 0000
		_delay_ms(1);
		PORTB = PINA;
		if(	(PINA & 0x02) == 0x02) PORTE = FND_DATA_TBL[1];		//	0b 0001 0011
		else if((PINA & 0x04) == 0x04) PORTE = FND_DATA_TBL[2];	//	0b 0001 0101
		else if((PINA & 0x08) == 0x08) PORTE = FND_DATA_TBL[3];	//	0b 0001 1001
		_delay_ms(10);
		
		
		PORTA =	0X20;	//~0xDF;								//	0b 0010 0000
		_delay_ms(1);
		PORTB = PINA;
		if((PINA & 0x02) == 0x02)	PORTE = FND_DATA_TBL[4];	//	0b 0010 0011
		else if((PINA & 0x04) == 0x04) PORTE = FND_DATA_TBL[5];	//	0b 0010 0101
		else if((PINA & 0x08) == 0x08) PORTE = FND_DATA_TBL[6];	//	0b 0010 1001
		_delay_ms(10);
		
		
		PORTA =	0X40;	//~0xBF;								//	0b 0100 0000
		_delay_ms(1);
		PORTB = PINA;
		if((PINA & 0x02) == 0x02)	 PORTE = FND_DATA_TBL[7];	//	0b 0100 0011
		else if((PINA & 0x04) == 0x04)  PORTE = FND_DATA_TBL[8];//	0b 0100 0101
		else if((PINA & 0x08) == 0x08)  PORTE = FND_DATA_TBL[9];//	0b 0100 1001
		_delay_ms(10);
		
		
		PORTA = 0X80;	//~0x7F;								//	0b 1000 0000
		_delay_ms(1);
		PORTB = PINA;
		if((PINA & 0x02) == 0x02);	//*							//	0b 1000 0011
		else if((PINA & 0x04) == 0x04)  PORTE = FND_DATA_TBL[0];//	0b 1000 0101
		else if((PINA & 0x08) == 0x08);	//#						//	0b 1000 1001
		_delay_ms(10);

	}
}
