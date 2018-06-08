#include<stdio.h>
unsigned long long int sbox[16]={0x03,0x0f,0x0e,0x01,0x00,0x0a,0x05,0x08,0x0c,0x04,0x0b,0x02,0x09,0x07,0x06,0x0d}; 



void main()
{
	unsigned long long int  x = 0x0000000000000000,count=0,z=0,z1=0,z2=0;
	unsigned long long int key[2]={0x0000000000000000,0x0000000000000000};
	count=0; 
	while(count<31)
	{
		z_msb= s_box((x>>32)&0x00000000ffffffff);
		z1= (z_msb^(key[1]&0x00000000ffffffff)^(x&0x000000000ffffffff);
		z2 =  (((z1)<<3)|(((z1)>>(32-3))))&0xffffffff;
		
	}
	
}


