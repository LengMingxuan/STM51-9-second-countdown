#include<reg51.h>
int k;
sbit datacs=P2^6;
sbit chipcs=P2^7;
sbit chipcs=P2^7;
????
unsigned char code discode1[] = {0x00,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
//?????0~9??��????
unsigned char second = 10;
//???????
//
unsigned char  i=20;
void main ()
{
	TMOD=0x01;			//?????T0????1
	TH0=0x4c;			//???????????
	TL0=0x00;
	P1=0x00;				//P1??8??LED????
	EA=1;					//???��??
	ET0=1;					//??T0?��?
	TR0=1;					//????T0
	datacs=1;
	datacs=0;
	P0=0x7f;                          // ????8��???
	chipcs=1;
	chipcs=0;
        datacs=0;
        P0=0x00;                          // ????8��???
        chipcs=1;
        chipcs=0;
	while(1)				//??????
	{

	}
}
void timer0() interrupt 1			//T0?��????
{
	TH0=0x4c;				//????????
	TL0=0x00;
	i--;					//?????????1
	if(i<=0)
	{
	i=20;
	if(k==0){
  	P1=0x00; 
  	}
    second --;
    P0 = discode1[second];	
	}
}