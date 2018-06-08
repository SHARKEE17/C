#include<stdio.h>
 unsigned int s[16] ={0x06,0x03,0x0a,0x05,0x0c,0x08,0x01,0x0b,0x00,0x0d,0x09,0x0e,0x0f,0x02,0x07,0x04};

unsigned long long int t[64] = {0,16,32,48,1,17,33,49,2,18,34,50,3,19,35,51,4,20,36,52,5,21,37,53,6,22,38,54,7,23,39,55,8,24,40,56,9,25,41,57,10,26,42,58,11,27,43,59,12,28,44,60,13,29,45,61,14,30,46,62,15,31,47,63};
// S_BOX
 //S box
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

void main()
{
	   unsigned long long int x = 0x1234567890abcdef;
		unsigned long long int key[2] = { 0x1111222233334444,0x1111111155555555};
	unsigned long long int p=0,m=0,y=0,w=0,temp;
	unsigned int v=0,u=0,t=0;
   unsigned int n=0;
 while(n<31)
 {
 	x=key[1]^x;
 	x=p_box(s_box(x));
   temp=key[1];
   key[1]= (temp<<13)|key[0]>>(64-13);// lsb
key[0]= (key[0]<<13)|temp>>(64-13); // msb 
 //p= s_box(key[1]&0x00000000000000ff);
 //	printf("\nS p %llx\n",p);
 v=s_box(key[1]&0x00000000ffffffff);
 u=s_box((key[1]>>4)&0x000000000000000f);
 t =((u<<4|v)&0xff);
 
 key[1]=((key[1]&0xffffffffffffff00)|t );
 p=((( key[1]>>(64-5))&0x1f)^(0x1f&n));
 w= ((key[1]&0x07ffffffffffffff)|(p<<(64-5)));
 
 
			printf("\nS %d %llx %llx\n",n,key[0],w);
			n++;
			printf("\nS  %llx\n",x);
 }
}
 
