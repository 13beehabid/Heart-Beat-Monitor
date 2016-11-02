#include <reg51.h>
#include <stdio.h>
#include <string.h>
#define register ren
sbit S20=P2^0;
sbit S21=P2^1;
sbit S22=P2^2;
sbit S23=P2^3;
sbit S24=P2^4;
sbit S25=P2^5;
sbit S26=P2^6;
sbit S27=P2^7;
sbit S10=P1^0;
sbit S11=P1^1;


void serial_init(){
TMOD = 0x20;
SCON = 0x50;
TH1 = 0xFD;
TR1 = 1;
}
void DelayMs(unsigned int k) 
{ 
	unsigned int i; 
	for(i=0;i<=k;i++); 
}
void main()
{
char ren;
	int zen;
serial_init();
P1= 0x00;
P2= 0x00;
S20=1;
S25=1;
while(1)
{
	DelayMs(3000);
while(RI==0);
zen=SBUF;
RI=0;
if(zen==0X46)
{
S21=1;
S22=0;
S23=0;
S24=0;
}
	if(zen==0X42)
{
S21=0;
S22=1;
S23=0;
S24=0;
}
	if(zen==0X4C)
{
S21=0;
S22=0;
S23=1;
S24=0;
}
	if(zen==0X52)
{
S21=0;
S22=0;
S23=0;
S24=1;
}
	if(zen==0X47)
{
S21=1;
S22=0;
S23=1;
S24=0;
}
	if(zen==0X49)
{
S21=1;
S22=0;
S23=0;
S24=1;
}
	if(zen==0x48)
{
S21=0;
S22=1;
S23=1;
S24=0;
}
	if(zen==0X4A)
	{
S21=0;
S22=1;
S23=0;
S24=1;
}
	if(zen==0X53)
	{
S21=0;
S22=0;
S23=0;
S24=0;
}
	 if(zen==0x57)
	{
	S10=1;
	}
		if(zen==0x77)
	{
	S10=0;
	}
		if(zen==0x56)
	{
	S27=1;
	}
		if(zen==0x76)
	{
	S27=0;
	}
		if(zen==0x30)
	{
	S20=1;
	S26=0;
	}
		if(zen==0x71)
	{
	S20=0;
	S26=1;
	}
		if(zen==0x44)
	{
	P1=0x00;
	P2=0x00;
	}
}
}
