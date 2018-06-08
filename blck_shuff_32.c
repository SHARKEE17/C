#include<stdio.h>
void main()
{
 unsigned int i,z=0,c=0x12345678;
 z = ( ((c&(0xff00ff00))>>8) | ((c&(0x00ff00ff))<<8)  );

 
 
printf("\nS -Box output %lx",z);
 }
