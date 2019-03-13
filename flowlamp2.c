		 #include<reg51.h>
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
{  uchar i,temp;
	  	
	while(1)
	{		
	   temp=0x7f;
	  for(i=0;i<7;i++)
	  {
	  P0=temp;
	  delay(700);
	  temp=_cror_(temp,1);
	  
	  }

	   for(i=0;i<7;i++)
	  {
	  P0=temp;
	  delay(700);
	  temp=_crol_(temp,1);
	  
	  }
	  }
	  }
	
	