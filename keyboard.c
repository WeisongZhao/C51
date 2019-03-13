				 #include <reg51.h>
				  #include <intrins.h>
				   #define uchar unsigned char
				   #define uint unsigned int
sbit L1=P1^0;	
sbit L2=P1^1;
sbit L3=P1^2;
sbit L4=P1^3;
uchar dis[16]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
void  delay(uint j)				 	
{	uchar t;
 	while (j--)
  	{	for(t=0; t<126; t++);	
  	}
}
void main()
{
 uchar temp;
 uchar i;
 
while(1)
 {

  P1=0xef;

           for(i=0;i<=3;i++)
          {  
if(L1==0)P0=dis[i*4+0];
if(L2==0)P0=dis[i*4+1];
if(L3==0)P0=dis[i*4+2];
if(L4==0)P0=dis[i*4+3];
delay(100);
temp=P1;
temp=temp|0x0f;
temp=temp<<1;
temp=temp|0x0f;
P1=temp;

          }
 
                 }
  
                        }