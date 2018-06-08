
#include<stdio.h>
void main()
{
 unsigned int i,z=0,c=0xab;
 unsigned int s[8] = {2,4,6,0,7,1,3,5};
 for(i=0;i<=7;i++)
 {
 	z|= ((c>>i)&0x01)<<s[i];
 }

 
 
printf("\nS -Box output %lx",z);
 }
