#include<stdio.h>
unsigned long long int s[16] = {0x03,0x0f,0x0e,0x01,0x00,0x0a,0x05,0x08,0x0c,0x04,0x0b,0x02,0x09,0x07,0x06,0x0d}; // CHECK ELEMENTS TWICE
unsigned long long int t[64] = {16,17,18,19,20,21,22,23,8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7,24,25,26,27,28,29,30,31}; // CHECK ELEMENTS TWICE
// S_BOX 
unsigned long long  s_box(unsigned long long int w)
{

 unsigned long long int z=0,i; // initialise z =0; vvimp	
 for(i=0;i<32;i=i+4)
 {
 z|= s[((w>>(28-i))&0x0f)]<<(28-i);  
}
 return(z);
}

// P_box 
unsigned long long  p_box(unsigned long long int n)
{
	  unsigned long long int z=0,i;	
	  
	 for(i=0;i<32;i++)
 {
 	z|= ((n>>i)&0x01)<<t[i];
 }
 return(z);
}



int main()
{
	unsigned long long int c=0x1234567890abcdef,e=0,e1=0,e2=0,e3=0,e4=0,e5=0,f=0,g=0,h=0,k=0,f1=0,c1=0,j=0;
	c1=((c>>32)&0xffffffff);
	printf("\nS -Input code %llx",c);
	e=s_box(c1);// s_box msb
	printf("\nS -S_(MSB)block output %llx",e);
	e1=s_box(c&0xffffffff); // s_box lsb
		printf("\nS -S(LSB)_block output %llx",e1);
	e2=p_box(e1);
	f1= e2^e;// LSB Of output
	e4=p_box(f1);
	f=e4^e1; // MSB of output
	printf("\nS -P_block (MSB) output %llx",f);
	printf("\nS -P_block output(LSB) %llx",f1);
	j=(((f<<32)&0xffffffff00000000)|f1);
	k=( ((j&(0xff00ff00ff00ff00))>>8) | ((j&(0x00ff00ff00ff00ff))<<8)  );
	printf("\nS - output IS %llx",k);
}

	
