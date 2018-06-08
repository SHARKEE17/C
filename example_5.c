#include<stdio.h>
void main()
{
	unsigned long long int key[2] = { 0x1111111111111111,0x1111111111111111};
	unsigned long long int z=0,m=0,temp;

    temp=key[1];
   key[1]= (temp<<13)|key[0]>>(64-13);// lsb
key[0]= (key[0]<<13)|temp>>(64-13); // msb  
	
		printf("\nS first 64 %llx\n",key[0]);
			printf("\nS last 64 %llx\n",key[1]);
	
	
	

}

