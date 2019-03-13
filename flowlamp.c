#include<reg51.h>
#include <intrins.h>					
#define uchar unsigned char
#define uint unsigned int		  			
void  delay(uint j)				 
{	uchar t;
 	while (j--)
  	{	for(t=0; t<120; t++);	
  	}
}
void  main(  )	
{  
uchar i,temp;
EA=1;
EX1=1;
IT1=0;	  	
while(1)
	{	
		
	   temp=0x80;
	  for(i=0;i<7;i++)
	  {
	  P2=temp;
	  delay(700);
	  temp=_cror_(temp,1);
	  
	  }
	   for(i=0;i<7;i++)
	  {
	  P2=temp;
	  delay(700);
	  temp=_crol_(temp,1);
	  
	  }
	  }
	  }
	
void int1() interrupt 2 
{
	   EX1=0;
  	   P2=0xaa;
	   	delay( 500 ); 				

	    P2=0x55;	
		delay( 500 );				  
   	
			 EX1=1;
			

}	