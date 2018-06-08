#include<stdio.h>
void main()
{
 unsigned int i,z=0,c=0xabcd;
 unsigned int s[16] = {0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15};
 for(i=0;i<=15;i++)
 {
 	z|= ((c>>i)&0x01)<<s[i];
 }

 
 
printf("\nS -Box output %lx",z);
 }
