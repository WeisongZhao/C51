#include<reg51.h>
sbit sound=P2^3;
sbit A=P2^6;
sbit BB=P2^7;
sbit I=P2^0;
unsigned char TH0_temp,TL0_temp,i=0,counter=0;
 void main()
 {
  sound=1;
  TMOD=0x01;
  ET0=1;
  EA=1;
   TH0=0x00;
  TL0=0x00;
  TCON=0x01;
 while(1)
 {
 if((i==0)&&(I==0))
 { 	A=0;BB=1;
   counter=0;
   TH0_temp=0xfa;
   TL0_temp=0xfa;
    TR0=1;
 }

  if(i==1) 
 {	 
   
   
   TH0_temp=0xf8;
   TL0_temp=0xf8;
   TR0=1;
   }
 
 if(i==2)
 {	 
 TR0=0;
 counter=0;
  
 sound=1;
 i=0;
 
       }       }
                     }
 
 void T0_func() interrupt 3
 {

 counter++;
 TH0=TH0_temp;
 TL0=TL0_temp;
 sound=~sound;
 if(counter<100)
 {A=~A;}
 if(counter>=100)
 {
 BB=~BB;i=1;
 } 
 if(counter>=240)
 {
 i=2;
 }  

 }
   