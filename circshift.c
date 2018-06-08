#include<stdio.h>

void main()
{
	unsigned int c = 0xab, z=0; 
	z = (((c&0x0f)<<4)| ((c&0xf0)>>4));
	printf("\nS -Box output %lx",z);
}
