#include<stdio.h>
#define mod 10000007
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
    while(1)
    {
        long long int n,k,a,b,c,d,ans;
        scanf("%lld %lld",&n,&k);
        if(n==0 && k==0)
        break;
        a=(2*modulus(n-1,k))%mod;
        b=modulus(n,k);
        c=(2*modulus(n-1,n-1))%mod;
        d=modulus(n,n);
        ans=(a+b)%mod;
        ans=(ans+c)%mod;
        ans=(ans+d)%mod;
        printf("%lld\n",ans);
    }
    return 0;
 }
