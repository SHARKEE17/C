#include<stdio.h>
 unsigned long long int s[16] = {0x06,0x03,0x0a,0x05,0x0c,0x08,0x01,0x0b,0x00,0x0d,0x09,0x0e,0x0f,0x02,0x07,0x04};
 unsigned long long int t[64] = {0,16,32,48,1,17,33,49,2,18,34,50,3,19,35,51,4,20,36,52,5,21,37,53,6,22,38,54,7,23,39,55,8,24,40,56,9,25,41,57,10,26,42,58,11,27,43,59,12,28,44,60,13,29,45,61,14,30,46,62,15,31,47,63};
 
// S_BOX 
unsigned long long  s_box(unsigned long long int c)
{

 unsigned long long int z=0,i;	
 for(i=0;i<64;i=i+4)
 {
 z|= s[((c>>(60-i))&0x0f)]<<(60-i);  // 
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

int main()

	{
	unsigned long long int c=0x1234567890abcdef,e=0,g=0,i;
	
	printf("\nS -Input code %llx",c);
	int n=31;
	while(n--)
	{
		c=p_box(s_box(c));
		printf("\nS -Input code %llx\n",c);
		
	}
	
	
}
