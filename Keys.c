
#include<reg51.h>
#include<LDELAY8052.h>
void LCMD(unsigned char);
void LDATA(unsigned char);
sbit EN = P0^2;

sbit R1 = P1^0;
sbit R2 = P1^1;
sbit R3 = P1^2;
sbit R4 = P1^3;
sbit C1 = P1^4;
sbit C2 = P1^5;
sbit C3 = P1^6;
sbit C4 = P1^7;

char Read_Keypad()
{
  C1=1;
  C2=1;
  C3=1;
  C4=1;
  R1=0;
  R2=1;
  R3=1;
  R4=1;
  if(C1==0)
  {
  	DELAY(100);
	  while(C1==0)
	     LDATA('A');
  }
  if(C2==0)
  {
	 DELAY(100);
	 while(C2==0)
	   LDATA('3');
	}
  if(C3==0)
  {
	 DELAY(100);
	 while(C3==0)
	   LDATA('2');
	}
  if(C4==0)
  {
	 DELAY(100);
	 while(C4==0)
	 LDATA('1');
	}
	
  R1=1;
  R2=0;
  R3=1;
  R4=1;
  if(C1==0)
  {
	 DELAY(100);
	 while(C1==0)
	   LDATA('B');
	}
  if(C2==0)
  {
	 DELAY(100);
	 while(C2==0)
	    LDATA('6');
	}
  if(C3==0)
  {
	 DELAY(100);
	 while(C3==0)
	    LDATA('5');
	}
  if(C4==0)
  {
	 DELAY(100);
	 while(C4==0)
	    LDATA('4');
	}
	
	
  R1=1;
  R2=1;
  R3=0;
  R4=1;
  if(C1==0)
  {
		DELAY(100);
	  while(C1==0)
	   LDATA('C');
	}
  if(C2==0)
  {
	 DELAY(100);
	 while(C2==0)
	    LDATA('9');
	}
  if(C3==0)
  {
	 DELAY(100);
	 while(C3==0)
	   LDATA('8');
	}
  if(C4==0)
  {
	 DELAY(100);
	 while(C4==0)
	   LDATA('7');
	}
	
	
  R1=1;
  R2=1;
  R3=1;
  R4=0;
  if(C1==0)
  {
	 DELAY(100);
	 while(C1==0)
	    LDATA('D');
	}
  if(C2==0)
  {
	 DELAY(100);
	 while(C2==0)
	    LDATA('F');
	}
  if(C3==0)
  {
	 DELAY(100);
	 while(C3==0)
	    LDATA('0');
	}
  if(C4==0)
  {
	 DELAY(100);
	 while(C4==0);
	   LDATA('E');
	}
  return 0;
}

void main()
{
	C1=1;
	C2=1;
	C3=1;
	C4=1;
	R1=1;
	R2=1;
	R3=1;
	R4=1;
	P0=0x00;						
	DELAY(30);						

	LCMD(0X28);
	LCMD(0X28);						
	LCMD(0X01);						
	LCMD(0X0E);						
	LCMD(0X06);

  
	LDATA('p');
	LDATA('r');
	LDATA('e');
	LDATA('s');
	LDATA('s');
	LDATA(' ');
	LDATA('k');
	LDATA('e');
	LDATA('y');
	LDATA(':');
	LDATA('.');

  while(1)
  {
		Read_Keypad();
  }
}
void LCMD(unsigned char CM)
{
	DELAY(2);						
	P0=(CM & 0XF0)|0X04;			
	EN=0;							
	P0=(CM<<4)|0X04;				 
	EN=0;							
}
void LDATA(unsigned char DT)
{
	DELAY(2);						
	P0=(DT & 0xF0)|0x05;			
	EN=0;							
	P0=(DT<<4)|0x05;				
	EN=0;							
}
