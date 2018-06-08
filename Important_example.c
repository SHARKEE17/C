#include<stdio.h>
unsigned long long int s[16] = {0x06,0x03,0x0a,0x05,0x0c,0x08,0x01,0x0b,0x00,0x0d,0x09,0x0e,0x0f,0x02,0x07,0x04};
unsigned long long int t[64] = {0,16,32,48,1,17,33,49,2,18,34,50,3,19,35,51,4,20,36,52,5,21,37,53,6,22,38,54,7,23,39,55,8,24,40,56,9,25,41,57,10,26,42,58,11,27,43,59,12,28,44,60,13,29,45,61,14,30,46,62,15,31,47,63};
// S_BOX 
unsigned long long  s_box(unsigned long long int c)
{

 unsigned long long int z=0,i;	
 for(i=0;i<64;i=i+4)
 {
 z|= s[((c>>(60-i))&0x0f)]<<(60-i);  
}
 return(z);
}

// P_BOX
unsigned long long  p_box(unsigned long long int n)
{
	  unsigned long long int z=0,i;	
	  
	 for(i=0;i<=63;i++)
 {
 	z|= ((n>>i)&0x01)<<t[i];
 }
 return(z);
}

// Circular shift 
unsigned long long circshift(unsigned long long int p)
{
	unsigned long long int z=0,a1=0,a2=0;
	//a1= (p>>32)&0xffffffff;
	//a2 = (p & 0xffffffff);
	//a1 = (( ( a1>>16) | (a1<<(32-16))) &0xffffffff);
	//a2 = (( ( a2<<8) | (a2>>(32-8))) &0xffffffff);
	z = ((((( ((p>>32)&0xffffffff >>16) | ((p>>32)&0xffffffff<<(32-16))) &0xffffffff)<<32)&0xffffffff00000000)|(( ((p & 0xffffffff) <<8) | ((p & 0xffffffff)>>(32-8))) &0xffffffff));
	z = ((((( ( a1>>16) | (a1<<(32-16))) &0xffffffff)<<32)&0xffffffff00000000)|(( ( a2<<8) | (a2>>(32-8))) &0xffffffff))
	return(z);
	
	
}

int main()
{
	unsigned long long int c=0x1234567890abcdef,e=0,f=0,g=0;
	printf("\nS -Input code %llx",c);
	e=s_box(c);
	printf("\nS -S_block output %llx",e);
	f =p_box(e);
	printf("\nS -P_block output %llx",f);
	g=circshift(f);
	printf("\nS -bit circshift output %llx",g);
}

	
	
	
	

