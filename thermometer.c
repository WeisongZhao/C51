#include<reg51.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define OUT P2
uchar seg[11]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xbf};
uchar seg1[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
uint temp;
uchar X=0; 
sbit DQ=P1^6;                    
sbit A1=P1^3;
sbit B2=P1^2;
sbit C3=P1^1;
sbit D4=P1^0;
void delay(uchar n)
{
  do
   {
_nop_();
_nop_();
_nop_();
n--;

}
while(n);
}
void ID() 
{
DQ=0;                  
delay(120);                
DQ=1;                    
delay(16);
delay(80);               
}

uchar ROB()       
{
uchar i=0;
uchar dat=0;

for(i=8;i>0;i--)
{
DQ=0;
delay(1);
DQ=1;
dat>>= 1;                
if(DQ)                   
{
dat|=0x80;            
}
delay(11);              
}
return (dat);
}

void WOB(uchar dat)
{
uchar j=0;
for(j=8;j>0;j--)
{		
DQ = 0;                        
_nop_();                      
DQ=dat&0x01;               
delay(12);                  
DQ=1;                        
dat>>=1;
delay(5);
}
}
uint GT()                   
{

float tt;
uchar a,b;
X=0;
ID();               
WOB(0xcc);          
WOB(0x44);         
ID();                 
WOB(0xcc);          
WOB(0xbe);         
a=ROB();           
b=ROB();           
temp=b;                     
temp<<=8;                   
temp=temp|a;  
if(temp&0x8000)      
 { 
 X=1;     
temp=~temp;  
temp +=1;   
 }             
tt=temp*0.0625;             
temp=tt*10;          
return temp;
}



void main()
{ 

uint temp1=0,m=0;
uchar X1=0,X2=0,X3=0,X4=0;
delay(1000);
 

while(1)
{

temp1=GT();

 
X1=temp1/1000;
X2=(temp1%1000)/100;
X3=(temp1%100)/10;
X4=temp1%10;
     

 for(m=0;m<=5;m++)	
 {
  

if(X==0)
{
 P1=0xf8;
 //A1=1;B2=0;C3=0;D4=0;
 P2=seg[X1];
delay(1000); 
  
  }
  else 
{
   P1=0xf8;
 // A1=1;B2=0;C3=0;D4=0;
 P2=0xbf;
delay(1000);
} 
	  
P1=0xf4; 			  
//A1=0;B2=1;C3=0;D4=0;
P2=seg[X2];
delay(1000);   
 P1=0xf2; 
//A1=0;B2=0;C3=1;D4=0;
P2=seg1[X3];
delay(1000);   
P1=0xf1;	 	 
//A1=0;B2=0;C3=0;D4=1;
P2=seg[X4];
delay(1000); 


			 } 
 			   
  						 
 	






}



}