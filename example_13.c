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

// block shift 
//unsigned long long  blk_shift(unsigned long long int m)
//{
//	unsigned long long int z=0;
//	z = ( ((m&(0x00000000ffffffff))<<32) | ((m&(0xffffffff00000000))>>32)  );
//	return(z);
//}

unsigned long long circshift(unsigned long long int p)
{
	unsigned long long int z=0,a1=0,a2=0;
		a1 = (p & 0xffffffff);
	//a2 = (p & 0xffffffff);
	a1 = (( ( a1>>7) | (a1<<(32-7))) &0xffffffff);
	//a2 = (( ( a2<<8) | (a2>>(32-8))) &0xffffffff);
	//z = (((a1<<32)&0xffffffff00000000)|a2);
	return(a1);
	
	
}
unsigned long long circshift1(unsigned long long int q)
{
	unsigned long long int z=0,a1=0,a2=0;
	//a1= (p>>32)&0xffffffff;
	a2 = (q & 0xffffffff);
	//a1 = (( ( a1>>7) | (a1<<(32-7))) &0xffffffff);
	a2 = (( ( a2<<9) | (a2>>(32-9))) &0xffffffff);
	//z = (((a1<<32)&0xffffffff00000000)|a2);
	return(a2);
	
	
}

int main()
{
	unsigned long long int c=0x1234567890abcdef,e=0,e1=0,e2=0,e3=0,e4=0,e5=0,f=0,g=0,h=0,f1=0,c1=0,j=0;
	c1=((c>>32)&0xffffffff);
	printf("\nS -Input code %llx",c);
	e=s_box(c1);
	printf("\nS -S_(MSB)block output %llx",e);
	e1=s_box(c&0xffffffff);
		printf("\nS -S(LSB)_block output %llx",e1);
	e2= circshift(e);
	e3=e2^e1;// P block msb 
	e4=circshift1(e3); 
	e5=e4^e; // P block lsb
	
	f =p_box(e3);
	f1=p_box(e5);
	printf("\nS -P_block (MSB) output %llx",f);
	printf("\nS -P_block output(LSB) %llx",f1);
	j=(((f<<32)&0xffffffff00000000)|f1);
	//g=blk_shift(j);
	printf("\nS - output IS %llx",j);
}

	
