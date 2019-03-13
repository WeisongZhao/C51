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
void  main(  )					
{	P1=0xfe;	
   	while (1)
   	{
	   	delay( 500 ); 				

		P1=_crol_(P1,1) ;		
   	}
}