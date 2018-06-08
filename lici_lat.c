#include<stdio.h>
#define ll unsigned long long int

ll sbox[16]={0x00,0x05,0x03,0x02,0x05,0x08,0x04,0x08,0x09,0x08,0x02,0x08,0x01,0x01,0x01,0x01};	

ll sb( ll x)
{
	ll k=0;
	int n;
	//k=a[x&0x0f]+(a[(x>>4)&0x0f]<<4);
	for(n=0;n<32;n+=4)
	{
		//l=l+(a[(x>>(60-n))&0x0f]<<(60-n));
		k=k|(sbox[(x>>(28-n))&0x0f]<<(28-n));
	}
//	printf("%llx\n",k);
	return k;
	
}

ll csright(ll x, int s)
{
	return (((x)>>s)|(((x)<<(32-s))))&0xffffffff;	
}

ll csleft(ll x, int s)
{
	return (((x)<<s)|(((x)>>(32-s))))&0xffffffff;	
}

int main()
{
	ll x = 0x0000000000000001;
	ll A=0,b=0,c=0,d=0,ch=0,actsb=0,j=0;	
	int i=0,k=0;	
	ll a[2]={0x0000000000000000,0x0000000000000000};
	ll k0,k1;
	ll rc=0;
	int min=100;
	for(k=0;k<64;k+=4)
	{
	for(j=0;j<15;j++)
	{
	x=(0x0000000000000001+j)<<(k);
	printf("%llx : ",x);
	rc=0;
	actsb=0;
	while(rc<5)
	{
		
	ch=(x>>32)&0x00000000ffffffff;
	for(i=0;i<32;i+=4)
	{
		if((ch>>i)&0x0f)
		{
			actsb++;
		}
	}
	
		
	// logic
	A=sb((x>>32)&0x00000000ffffffff);
	b=(x&0x00000000ffffffff) ^ (A);// ^ (a[1]&0x00000000ffffffff) ;
	d=csleft(b, 3);
	c= csright((A ^ d /*^ ((a[1]>>32)&0x00000000ffffffff))*/), 7);
	x=(d<<32) | c; 
	
	
	
/*	
	//shifting
	k0=(a[0]>>(64-13))& 0x1fff;
	k1=(a[1]>>(64-13))& 0x1fff;
	a[0]=(a[0]<<13)  | k1;
	a[1]=(a[1]<<13)| k0;
	
	//sbox
	a[1]=(a[1]&0xfffffffffffffff0)|sbox[a[1]&0xf];
	//printf("%llx\n",a[1]);
	a[1]=(a[1]&0xffffffffffffff0f)|(sbox[(a[1]&0xf0)>>4]<<4);
	
	//rc
	
		a[1]=((a[1]&0xf800000000000000) ^ ((rc<<(64-5))&0xf800000000000000)) | (a[1]&0x07ffffffffffffff);
		//printf("%lld  %llx %llx\n\n",rc,a[0],a[1]);

*/
		rc++;		
	//answer		
	//	printf("%llx\n",x);
	}
	if(min>actsb)min=actsb;
printf("%d\n",actsb);
	}
	printf("min act sbox are:  %d\n",min);
	}

}

