#include<stdio.h>
 unsigned int s[16] = {0x06,0x03,0x0a,0x05,0x0c,0x08,0x01,0x0b,0x00,0x0d,0x09,0x0e,0x0f,0x02,0x07,0x04};
 
 unsigned long long  s_box(unsigned long long int w)
{

 unsigned long long int z=0,i;	
 for(i=0;i<8;i=i+4)
 {
 z|= s[((w>>(4-i))&0x0f)]<<(4-i);  
}
 return(z);
}

void main()
{
		unsigned long long int key[2] = { 0x1234567890abcdef,0x1234567890abcdef};
	unsigned long long int p=0,m=0,y=0,w=0,v=0,temp;

    temp=key[1];
   key[1]= (temp<<13)|key[0]>>(64-13);// lsb
key[0]= (key[0]<<13)|temp>>(64-13); // msb 
 p= s_box(key[1]&0x00000000000000ff);
 	printf("\nS p %llx\n",p);
 w=((key[1]&0xffffffffffffff00)|p);
printf("\nS first 64 %llx\n",key[0]);
			printf("\nS last 64 %llx\n",w);
 

}
