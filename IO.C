#include<reg51.h>
#include<absacc.h>
#define PA8255 XBYTE[0x7f7c]
#define PB8255 XBYTE[0x7f7d]
#define COM8255 XBYTE[0x7f7f]
#define uchar unsigned char
sbit PP=P3^5;
void main ()
{   
    unsigned char temp;
    
	 COM8255=0x83;
    while(1)
  {  
   	PP=0;
    temp=PB8255;
    PA8255=temp;
  } 
}








