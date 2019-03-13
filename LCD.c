						   					 #include <reg51.h>
#include <intrins.h>				
#define uchar unsigned char		  			
#define uint unsigned int
#define out P0
sbit RS=P2^0;
sbit RW=P2^1;
sbit E=P2^2;
void  delay(uint i)				 	
{	uchar t;
 	while (i--)
  	{	for(t=0; t<125; t++);	
  	}
}

void check_busy()
{
uchar dt;
do
{
dt=0xff;
E=0;
RS=0;
RW=1;
E=1;
dt=out;

}while(dt&0x80);
E=0;
}
void write_command(uchar com)
{
check_busy();
E=0;
RS=0;
RW=0;
out=com;
E=1;
_nop_();
E=0;
delay(2);
}
void write_data(uchar dat)
{
check_busy();
E=0;
RS=1;
RW=0;
out=dat;
E=1;
_nop_();
E=0;
delay(2);
}
void string(uchar ad,uchar *s)
{
write_command(ad);
while(*s>0)
{
write_data(*s++);
 delay(20);
}
}

void  main()
{ write_command(0x38);
write_command(0x0c);
write_command(0x06);
write_command(0x01);
delay(20);
while(1){
string(0x85,"Hellow");
string(0xc0,"Welcome To China");
delay(400);
write_command(0x01);
delay(400);}
		}






			