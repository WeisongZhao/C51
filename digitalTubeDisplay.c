				   #include<reg51.h>
				   #include<intrins.h>
				   #define uchar unsigned char
#define uint unsigned int
#define out P0
uchar code seg[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x01};	  			
void  delay(uint i)				 
{	uchar t;
 	while (i--)
  	{	for(t=0; t<120; t++);	
  	}
}
void  main(void)
 {
 		 
 	   uchar i;
	   while(1)
	   {
	   out=seg[i];
	   delay(900);
	   i++;
	   if(seg[i]==0x01)
	   
	  
	   i=0;
	   	
	   
	   
	   }
 
 
 
 }