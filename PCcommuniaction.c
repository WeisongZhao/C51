 #include<reg51.h>		 
sbit S=P3^5; 
void  delay(unsigned int i)				 	
{	unsigned char t;
 	while (i--)
  	{	for(t=0; t<126; t++);	
  	} 
}
void init()
{
TMOD=0x20;
TH1=0xfd;
TL1=0xfd;
PCON=0x00;
SCON=0x40;
TR1=1;
}

 void main()
{ 	
	
unsigned char temp=0x01;
  
   
   while(1){
	
    if(S==0)
     {delay(500);	
	 init();
	 SBUF=temp;
	while(TI==0);
	;
	TI=0;
	}
	
}

}
