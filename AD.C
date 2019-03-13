			#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit start=P2^1;
sbit OE=P2^7;
sbit EOC=P2^3;
sbit CLOCK=P2^0;
sbit add_a=P2^4;
sbit add_b=P2^5;
sbit add_c=P2^6;
void main()
{
 uchar temp;
add_a=0;
add_b=0;
add_c=0;
while(1)
{
start=0;
start=1;
start=0;
while(1)
{
CLOCK=!CLOCK;
if(EOC==1)break;
OE=1;
temp=P1;
OE=0;
P0=temp;



}



}




}