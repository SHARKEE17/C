#include<stdio.h>
void main()
{
 unsigned int i,z=0,c=0x0e;
 unsigned int s[4] = {2,3,0,1};
 for(i=0;i<=3;i++)
 {
 	z|= ((c>>i)&0x01)<<s[i];
 }

 
 
printf("\nS -Box output %lx",z);
 }
