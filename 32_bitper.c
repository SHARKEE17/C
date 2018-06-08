#include<stdio.h>
void main()
{
 unsigned int i,z=0,c=0xabcd;
 unsigned int s[32] = {20,16,28,24,17,21,25,29,22,18,30,26,19,23,27,31,11,15,3,7,14,10,6,2,9,13,1,5,12,8,4,0};
 for(i=0;i<=31;i++)
 {
 	z|= ((c>>i)&0x01)<<s[i];
 }

 
 
printf("\nS -Box output %lx",z);
 }
