///*
 //* FND2.c
 //*
 //* Created: 22-06-17 오후 4:46:58
 //*  Author: PKNU
 //*/ 
//#define F_CPU 7372800
//#define COUNT 9999
//#include <avr/io.h>
//#include <util/delay.h>
//
//int main(void)
//{
	//unsigned char FND_DATA_TBL [] = {0x3F,0X06,0X5B,0X4F,0X66,0X6D, 0X7D,0X27,
									 //0X7F, 0X6F };
	//
	//unsigned char SEG_TBL[] = {0x08,0x04,0x02,0x01};	//오른쪽에서부터 , 반전 필요
	//DDRA = 0XFF;
	//DDRC = 0XFF;
	//
	//unsigned int cnt = COUNT;
		//
	//while(1)
	//{
		//int p0;
		//int p1;
		//int p2;
		//int p3;
		//
		//for(int i = 0; i<cnt; i++)
		//{
			//if(cnt == 0) return;
			//int num = 0;
			//p3 = cnt/1000;
			//p2 = (cnt%1000)/100;
			//p1 = (cnt%100)/10;
			//p0 = cnt%10;
			//
			//while(num!=10)
			//{
				//PORTC = ~SEG_TBL[3];
				//PORTA = FND_DATA_TBL[p3];
				//_delay_ms(2);
				//
				//PORTC = ~SEG_TBL[2];
				//PORTA = FND_DATA_TBL[p2];
				//_delay_ms(3);
				//
				//PORTC = ~SEG_TBL[1];
				//PORTA = FND_DATA_TBL[p1] | 0x80;
				//_delay_ms(2);
				//
				//PORTC = ~SEG_TBL[0];
				//PORTA = FND_DATA_TBL[p0];
				//_delay_ms(3);
				//num++;
			//}
			//cnt--;
		//}
		//PORTC = 0x00;
		//_delay_ms(100000);
	//}
		//
	//return 0;
//}