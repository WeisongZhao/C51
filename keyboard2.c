					 #include <reg51.h>
#include <intrins.h>				
#define uchar unsigned char		  			
#define uint unsigned int
#define out P0
sbit RS=P2^0;
sbit RW=P2^1;
sbit E=P2^2;
sbit L1=P1^6;
sbit L2=P1^5;
sbit L3=P1^4;
sbit S=P2^3;
void  delay(uint i)				 	
{	uchar t;
 	while (i--)
  	{	for(t=0; t<126; t++);	
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

}
}

void  main()
{
uchar temp;
uchar k=12,i,m,flag=0,ad,q;
uchar *j;

uchar mm[8]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
uchar Num[16];
 S=0;
write_command(0x38);
write_command(0x0c);
write_command(0x06);
write_command(0x01);
delay(2);


  while(1)
{
k=12;
string(0x80," Designed by ZWS");
P1=0xfe;
for(i=0;i<=3;i++)
{
if(L1==0)k=i*3+0;
if(L2==0)k=i*3+1;	  
if(L3==0)k=i*3+2;
if(k>=0&&k<=11)S=1;
delay(50);
S=0;
delay(40);
temp=P1;
temp=temp|0xf0;
temp=temp<<1;
temp=temp|0xf1;
P1=temp;
}
if(k>=0&&k<=9)
{
flag++;
if(flag%2==1)
    m=(flag+1)/2;
if(flag%2==0)
    m=flag/2;
ad=0x48+0x80-mm[m-1];
Num[flag-1]=k;
for(q=1;q<=flag;q++){ 
	*j=Num[q-1]+48;
	string(ad,j);
	ad=ad+0x01;   
}
string(0x80," Designed by ZWS ");



}																								  

if(k==10)
{
write_command(0x01);
if(flag==0)flag=0;
else flag--;
if(flag%2==1)
    m=(flag+1)/2;
if(flag%2==0)
    m=flag/2;
ad=0x48+0x80-mm[m-1];
for(q=1;q<=flag;q++){ 
	*j=Num[q-1]+48;
	string(ad,j);
	ad=ad+0x01;   
}
string(0x80," Designed by ZWS ");	 

}

if(k==11)
{
write_command(0x01);
break;
}









}



		}






			