#include<stdio.h>
void main()
{
 unsigned int i,z=0,c=0x01;
 unsigned int s[16] = {0x03 , 0x0f, 0x0e, 0x01 , 0x00,0x0a,0x05,0x08,0x0c,0x04,0x0b,0x02,0x09,0x07,0x06,0x0d};
 //for(i=0;i<=4;i=i+4)
 //{
 z|= s[((c&0x0f))];
 //} 
 
 
printf("\nS -Box output %lx",z);
 }
