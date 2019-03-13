			 #include <reg51.h>
#include <intrins.h>	
#define uchar unsigned char
#define uint unsigned int		  			
void  delay(uint i)				 	
{	uchar t;
 	while (i--)
  	{	for(t=0; t<120; t++);	
  	}
}
void main()
{
EA=1;
EX0=1;
IT0=1;
while(1){

P1=0x00;


}

}
void int0() interrupt 0 using 1
{	  
	   EX0=0;
  		
 
		  P1=0x0f;
		delay( 500 ); 				
		   P1=0xf0;
		   delay(500);
	
						  
 
			 EX0=1;

}