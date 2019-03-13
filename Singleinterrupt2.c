			   #include<reg51.h>
unsigned int i=10000;                        
void main()                                       
{
  TMOD=0x02;                            //定时器T0为方式2
  TH0=0xa4;                              //定时器赋值：100=（28-X）*12/11.0592   
  TL0=0xa4;
  P1=0x00;
  EA=1;
  ET0=1;
  TR0=1; 
  while(1);
}
void timer0() interrupt 1
{
 i--;
 if(i<=0&&P0^0==0)
 {
   P1=~P1;
   i=10000;
 }
}

