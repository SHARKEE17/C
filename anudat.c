#include<stdio.h>
unsigned long long int s[16]={0x00,0x09,0x0c,0x01,0x05,0x08,0x08,0x02,0x0a,0x01,0x04,0x0a,0x02,0x08,0x08,0x01}; 
unsigned int t[32] = {20,16,28,24,17,21,25,29,22,18,30,26,19,23,27,31,11,15,3,7,14,10,6,2,9,13,1,5,12,8,4,0};

//S-box 
 unsigned long long  s_box(unsigned long long int  x)
{
    unsigned long long int k=0;
    int n;
    
    for(n=0;n<32;n+=4)
    {
        k=k|(s[(x>>(28-n))&0x0f]<<(28-n));
    }
    return(k);
}

// P-box 
unsigned long long  p_box(unsigned long long int n)
{
	  unsigned long long int z=0,i;	
	  
	 for(i=0;i<32;i++)
 {
 	z|= ((n>>i)&0x01)<<t[i];
 }
 return(z);
}

void main()
{
		unsigned long long int  x = 0x0000000000000001,z=0,z1=0,z2=0,z3=0,z4=0,y1=0,y=0,m=0,m1=0;
	unsigned long long int key[2]={0x0000000000000000,0x0000000000000000};
	unsigned long long int k0,k1,n,j,k,count,count1,rc,l;


	
		// LOgic 
			for(l=0;l<64;l+=4)
	{
	for(j=0;j<15;j++)
	{
	x=(0x0000000000000001+j)<<(l);
	printf("%llx\n",x);
		rc=0; 
		count=0;
		count1=0;
		while(rc<4)
		{
		z = ((x>>32)&0x00000000ffffffff);
		z1=( ( ( z<<3) | (z>>(32-3))) &0xffffffff);
		z3= ( ( z>>8 | (z<<(32-8))) &0xffffffff);
		// printf("op left shift %llx\n",z1);
		m = s_box(z1);
			 
    	 
         	for(n=0;n<32;n+=4)
            {
            k=(s[(m>>(28-n))&0xF]);
            if(k!=0)
           {
            count=count+1;
           }
         	}
			m1=s_box(z3);
				for(n=0;n<32;n+=4)
            {
            k=(s[(m1>>(28-n))&0xF]);
            if(k!=0)
           {
            count1=count1+1;
           }
         	}
		// printf("op s box %llx\n",m);
		z2=(m^(x&0x00000000ffffffff));
	//	 printf(" output xor %llx\n",z2);
	
		 //printf(" op right shift 8 %llx\n",z3);
		
		// printf("s box down %llx\n",m1);
		z4= (m1^z2^(key[1]&0x00000000ffffffff));
		// printf(" op xor 2nd %llx\n",z4);
		y1=p_box(z);//LSB
		y=p_box(z4);//MSB
		x = ((y<<32)|y1);
		rc++;
	}
		printf("%d\n",(count+count1));
	}
}
}



    
		
		
		
		
		
		
	



		// shifting
	//	 k0=(key[0]>>(64-13))& 0x1fff;
   // k1=(key[1]>>(64-13))& 0x1fff;
   // key[0]=(key[0]<<13)  | k1;
   // key[1]=(key[1]<<13)| k0;
    
    // S_box in key scheduling
    // key[1]=(key[1]&0xfffffffffffffff0)|s[key[1]&0xf];

    //key[1]=(key[1]&0xffffffffffffff0f)|(s[(key[1]&0xf0)>>4]<<4);
    
    //count in key scheduling
    
      //  key[1]=((key[1]&0xf800000000000000) ^ ((count<<(64-5))&0xf800000000000000)) | (key[1]&0x07ffffffffffffff);
        
      //  count++;
        
    //answer        
      //  printf("%llx
	  \n",x);
