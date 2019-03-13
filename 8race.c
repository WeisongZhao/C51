  #include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit DIN=P3^0;
sbit LOAD=P3^1;
sbit CLK=P3^2;
sbit key0=P1^0;
sbit key1=P1^1;
sbit key2=P1^2;
sbit key3=P1^3;
sbit key4=P1^4;
sbit key5=P1^5;
sbit key6=P1^6;
sbit key7=P1^7;
sbit key_clear=P2^0;
sbit begin=P2^1;
sbit sounder=P3^7;
uchar second=30,counter=0,people=0;
uchar num_add[8]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
uchar num_dat[10]={0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89};

uchar key_scan()
{
 uchar key1,temp;
 key1=0;
 P1=0xff;
 temp=P1;
 if(~(P1&temp))
 {	  
 switch(temp)
 {

 case 0xfe:
 key1=1;
 break;
  case 0xfd:
 key1=2;
 break;
  case 0xfb:
 key1=3;
 break;
  case 0xf7:
 key1=4;
 break;
  case 0xef:
 key1=5;
 break;
  case 0xdf:
 key1=6;
 break;
 case 0xbf:
 key1=7;
 break;
 case 0x7f:
 key1=8;
 break;
 default:
 key1=0;
 break;

 }
 
 }

 return key1;

}
void max7219_send(uchar add,uchar dat)
{
uchar i,j,temp1;
LOAD=0;
i=0;
while(i<16)
{
  if(i<8)temp1=add;
  else temp1=dat;
 for(j=8;j>=1;j--)	  
 	   {
		DIN=temp1&0x80;
		temp1=temp1<<1;
		CLK=1;
		CLK=0;

 		}
 
 	i=i+8;
 }

		LOAD=1;
 }

void max7219init()
{
max7219_send(0x0c,0x01);
max7219_send(0x0b,0x07);
max7219_send(0x0a,0xf5);
max7219_send(0x09,0xff);
}

void time_show(uchar x)
{
uchar i,j;
i=x/10;
j=x%10;
max7219_send(num_add[1],num_dat[j]);
max7219_send(num_add[0],num_dat[i]);

}
void result_show(uchar x)
{
uchar i,j;
i=x/10;
j=x%10;
max7219_send(num_add[3],num_dat[j]);
max7219_send(num_add[2],num_dat[i]);
}
void retime()
{
 time_show(second);
 result_show(people);
 
 if(~key_clear)
 {
while(~key_clear);
      if(people)
    {
     second=30;
      people=0;
            }
if(second<60)second++;
else second=0;

   }
 }
void time_init()
{
EA=1;
ET0=1;
TMOD=0x01;
TH0=0xd8;
TL0=0xef;
}
void main()
{
while(1)
{

       do
	   {  retime();
	   	  }while(begin);
		
		while(~begin);
	    max7219init();
		time_init();
	   	 TR0=1;
	   	 do
		 {
	   	   time_show(second);
				
	   	   result_show(people);
	  	   	people=key_scan();
		  }while((!people)&&(second));
		  TR0=0;

}
}
void timer0() interrupt 1
{	 
  time_show(1);
if(counter<100)
{
counter++;
if(counter==50)sounder=0;
}
else
{
second=second-1;
sounder=1;
counter=0;

}
TH0=0xd8;
TL0=0xef;

}