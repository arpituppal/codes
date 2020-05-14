#include<stdio.h>
#define mod 98777
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
        long long int n,ans;
        scanf("%lld",&n);
        ans=modulus(2,((n-1)*(n-1)));
        printf("%lld\n",ans);
    }
    return 0;
}
