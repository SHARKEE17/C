 #include<stdio.h>
void main()
{
 unsigned long int i,z=0,c=0x5a5a5a5a;
 unsigned int s[16] = {0x03 , 0x0f, 0x0e, 0x01 , 0x00,0x0a,0x05,0x08,0x0c,0x04,0x0b,0x02,0x09,0x07,0x06,0x0d};
 for(i=0;i<32;i=i+4)
 {
 z|= s[((c>>(28-i))&0x0f)]<<(28-i);
 } 
 
 
printf("\nS -Box output %lx",z);
 }
 
