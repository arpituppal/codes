#include<stdio.h>
int main()
{
   int t,x;
   scanf("%d",&t);
   for(x=1;x<=t;x++)
   {
      long long int n,res=1,base=2,mod=1000000007;
      scanf("%lld",&n);
      n=n-1;
      while(n>0)
      {
          if(n%2==1)
           res=(res*base)%mod;
            n=n>>1;
            base=(base*base)%mod;
      }
    printf("%lld\n",res);
  }
  return 0;
  }
