#include<reg51.h>
int k;
sbit datacs=P2^6;
sbit chipcs=P2^7;
unsigned char code discode1[] = {0x00,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
//�����0~9��С����
unsigned char second = 10;
//��¼����
unsigned char  i=20;
void main ()
{	

	
	TMOD=0x01;			//��ʱ��T0Ϊ��ʽ1
	TH0=0x4c;			//���ö�ʱ����ֵ
	TL0=0x00;	
	EA=1;					//���жϿ�
	ET0=1;					//��T0�ж�
	TR0=1;					//����T0        datacs=0;        P0=0x00;                          // ����8λȫ��        chipcs=1;        chipcs=0;
	while(1)				//ѭ���ȴ�
	{

	}
}
void timer0() interrupt 1			//T0�жϳ���
{	
	TH0=0x4c;				//���¸���ֵ
	TL0=0x00;
	i--;					//ѭ��������1
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
	EA=0;					//���жϿ�
	ET0=0;					//��T0�ж�
	TR0=0; 
	P1=0x00;  }
}