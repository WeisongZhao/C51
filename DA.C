  #include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit DAC_cs=P2^0;
sbit DAC_wr=P2^1;
void main()
{
uchar temp,i=255;
while(1)
{
P1=temp;
DAC_cs=0;
DAC_wr=0;
DAC_cs=1;
DAC_wr=1;
temp++;
while(--i);
while(--i);
while(--i);



}




}