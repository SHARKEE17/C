 #include<stdio.h>
void main()
{
 unsigned long long int z=0,y=0,c=0x5a5a5a5a6b6b6b6b;
 unsigned int i;

 unsigned long long int s[16] = {0x03 , 0x0f, 0x0e, 0x01 , 0x00,0x0a,0x05,0x08,0x0c,0x04,0x0b,0x02,0x09,0x07,0x06,0x0d};
 for(i=0;i<64;i=i+4)
 {
 z|= s[((c>>(60-i))&0x0f)]<<(60-i);

 } 
 printf("\nS -Box output %llx",z);
 }
 