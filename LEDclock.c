	 #include <reg51.h>
	 unsigned char code discode1[]={0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0x87,0xff,0xef};
	 unsigned char code discode2[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	 unsigned char timer=0;
	 unsigned char second;
	 unsigned char key=0;
	 void main()
	 {
	 TMOD=0x01;
	 ET0=1;
	 EA=1;
	 second=0;
	 P0=discode1[second/10];
	 P2=discode2[second%10];
	 
	 while(1){


	 if((P3&0x80)==0x00){
	 key++;
	 if(key==1){
	 TH0=0xee;
	 TL0=0x00;
	 TR0=1;
	 }
	 if(key==2){
	 TR0=0;
	 }
	 if(key==3){
	 key=0;
	 second=0;
	 P0=discode1[second/10];
	 P2=discode2[second%10];
	 }
	 while((P3&0x80)==0x00);
	 }
	                                              }       
												  
												  
												   }


 void int_T0() interrupt 1 using 3
 {
 TR0=0;
 TH0=0xee;
 TL0=0x00;
 timer++;
 if(timer==20)
 {
 timer=0;
 second++;
 P0=discode1[second/10];
P2=discode2[second%10];
}
if(second==99){
TR0=0;
second=0;
key=2;

}
else
{TR0=1;} 
 
 
 }
 
 
 
 
 
 
 