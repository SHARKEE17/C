#include<stdio.h>

void main()
{
	unsigned int c = 0xab, z=0; 
	z = ( ( c<<4) | (c>>(8-4))) &0xff;
	printf("\nS -Box output %lx",z);
}


// function of circ shift  

// 	z = ( ( a<<shift) | (a>>(8-shift))) &0xff;

