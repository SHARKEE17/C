#include<stdio.h>
#define ll unsigned long long int

ll sbox[16]={0x00,0x05,0x03,0x02,0x05,0x08,0x04,0x08,0x09,0x08,0x02,0x08,0x01,0x01,0x01,0x01}; 

unsigned long long  s_box(unsigned long long int  x)
{
    unsigned long long int k=0;
    int n;
    
    for(n=0;n<32;n+=4)
    {
        k=k|(sbox[(x>>(28-n))&0x0f]<<(28-n));
    }
    return(k);
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
    ll A=0,b=0,c=0,d=0,j,l;    
     ll k=0;
    int n,count,rc;
        
    ll a[2]={0x0000000000000000,0x0000000000000000};
    ll k0,k1;
    
    
    
    for(l=0;l<64;l+=4)
    {
     for(j=0;j<15;j++)	
      {
      	x=(0x0000000000000001 + j)<<(l);
      	printf("%llx\n",x);
	 rc=0;	 
    count=0;	
    while(rc<5)
    {
    	 A=s_box((x>>32)&0x00000000ffffffff);
    	 
    	 
    	for(n=0;n<32;n+=4)
    {
     k=(sbox[(A>>(28-n))&0xF]);
     if(k!=0)
    {
    count=count+1;
    }
	}
	b=(x&0x00000000ffffffff) ^ (A) ^ (a[1]&0x00000000ffffffff) ;
    d=csleft(b, 3);
    c= csright((A ^ d ^ ((a[1]>>32)&0x00000000ffffffff)), 7);
    x=(d<<32) | c;
    rc++;
    
    }
    
     printf("%d\n",count);
 }
}
}
  
    
    
    
    //shifting
    //k0=(a[0]>>(64-13))& 0x1fff;
    //k1=(a[1]>>(64-13))& 0x1fff;
    //a[0]=(a[0]<<13)  | k1;
    //a[1]=(a[1]<<13)| k0;
    
    //sbox
   // a[1]=(a[1]&0xfffffffffffffff0)|sbox[a[1]&0xf];
    //printf("%llx\n",a[1]);
   // a[1]=(a[1]&0xffffffffffffff0f)|(sbox[(a[1]&0xf0)>>4]<<4);
    
    //rc
    
    //    a[1]=((a[1]&0xf800000000000000) ^ ((rc<<(64-5))&0xf800000000000000)) | (a[1]&0x07ffffffffffffff);
        //printf("%lld  %llx %llx\n\n",rc,a[0],a[1]);
     //   rc++;
        
    //answer        
       
    
    
    

    
    




