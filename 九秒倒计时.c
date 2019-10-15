#include<reg51.h>
int k;
sbit datacs=P2^6;
sbit chipcs=P2^7;sbit chipcs=P2^7;ÿÿÿÿ
unsigned char code discode1[] = {0x00,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
//ÊıÂë¹Ü0~9´øĞ¡Êıµã
unsigned char second = 10;
//¼ÇÂ¼ÕæÃë
unsigned char  i=20;
void main ()
{
	TMOD=0x01;			//¶¨Ê±Æ÷T0Îª·½Ê½1
	TH0=0x4c;			//ÉèÖÃ¶¨Ê±Æ÷³õÖµ
	TL0=0x00;
	P1=0x00;				//P1¿Ú8¸öLEDµãÁÁ
	EA=1;					//×ÜÖĞ¶Ï¿ª
	ET0=1;					//¿ªT0ÖĞ¶Ï
	TR0=1;					//Æô¶¯T0
	datacs=1;
	datacs=0;
	P0=0x7f;                          // ´ú±í8Î»È«ÁÁ
	chipcs=1;
	chipcs=0;        datacs=0;        P0=0x00;                          // ´ú±í8Î»È«ÁÁ        chipcs=1;        chipcs=0;
	while(1)				//Ñ­»·µÈ´ı
	{

	}
}
void timer0() interrupt 1			//T0ÖĞ¶Ï³ÌĞò
{
	TH0=0x4c;				//ÖØĞÂ¸³³õÖµ
	TL0=0x00;
	i--;					//Ñ­»·´ÎÊı¼õ1
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