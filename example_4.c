#include<stdio.h>
unsigned long long int s[16] = {0x03,0x0f,0x0e,0x01,0x00,0x0a,0x05,0x08,0x0c,0x04,0x0b,0x02,0x09,0x07,0x06,0x0d};

//Sbox
unsigned long long  s_box(unsigned long long int c)
{

 unsigned long long int z=0,i;	
 for(i=0;i<32;i=i+4)
 {
 z|= s[((c>>(28-i))&0x0f)]<<(28-i);  
}
 return(z);
}
void main()
{
		unsigned long long int key[2] = { 0x0000000000000000,0x0000000000000000};
		unsigned long long int x = 0x0000000000000000;
		unsigned long long int p=0,q=0,v=0,m=0,z=0,y=0,r=0,u=0,w=0,temp;
		z=x>>32;
		q= s_box(z);
		p = (q^(x&0xffffffff));
		y=(key[1]^p);
		printf("\nS  %llx \n",y);
		r = (( ( p<<3) | (p>>(32-3))) &0xffffffff);// msb
		u = (q^(key[0]));
		w= (u^r);
		v = (( ( w>>7) | (w>>(32-7))) &0xffffffff);//lsb
			printf("\nS  %llx %llx\n",r,v);
			
		
		
		
}

