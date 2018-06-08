#include<stdio.h>
void main()
{
 unsigned long long int i,z=0,c=0x12345678abcdef09;
 z = ( ((c&(0x00000000ffffffff))<<32) | ((c&(0xffffffff00000000))>>32)  );

 
 
printf("\nS -Box output %llx",z);
 }
