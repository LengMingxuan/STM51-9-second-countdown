#include<reg51.h>
int k;
sbit datacs=P2^6;
sbit chipcs=P2^7;
unsigned char code discode1[] = {0x00,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
//数码管0~9带小数点
unsigned char second = 10;
//记录真秒
unsigned char  i=20;
void main ()
{	

	
	TMOD=0x01;			//定时器T0为方式1
	TH0=0x4c;			//设置定时器初值
	TL0=0x00;	
	EA=1;					//总中断开
	ET0=1;					//开T0中断
	TR0=1;					//启动T0        datacs=0;        P0=0x00;                          // 代表8位全亮        chipcs=1;        chipcs=0;
	while(1)				//循环等待
	{

	}
}
void timer0() interrupt 1			//T0中断程序
{	
	TH0=0x4c;				//重新赋初值
	TL0=0x00;
	i--;					//循环次数减1
	if(i<=0)
	{
	i=20;
    second --;
    
	
	P0=0x7f; 
	chipcs=1;
	chipcs=0;
	P0 = discode1[second];
	datacs=1;
	datacs=0;                         
	}
	if(second == 0){
	EA=0;					//总中断开
	ET0=0;					//开T0中断
	TR0=0; 
	P1=0x00;  }
}