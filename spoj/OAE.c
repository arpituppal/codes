#include<stdio.h>
#define mod 314159
long long int modulus(long long int base,long long int exp)
{
     long long int res=1;
     while(exp>0)
      {
          if(exp%2==1)
           res=(res*base)%mod;
            exp=exp>>1;
            base=(base*base)%mod;
      }
      return res;
 }
 int main()
 {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int base1=10,base2=8,n;
        scanf("%lld",&n);
        long long int res1=modulus(10,n-1);
        long long int res2=modulus(8,n-1);
        res1=(5*res1)%mod;
        res2=(4*res2)%mod;
        long long int ans=(res1+res2)%mod;

        //long long int ans=((modulus(base1,n)+(modulus(base2,n)))/2)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
