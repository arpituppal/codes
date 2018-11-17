#include<stdio.h>
int main()
{
     long long int n,m;
     while(1)
      {
          scanf("%lld %lld",&n,&m);
          if(n==0 && m==0)
          break;
          long long int j,c,sum=0,mod=1000000007;
          c=n;
          for(j=1;j<=m;j++)
               {
                 sum=(sum+c)%mod;
                 c=(c*n)%mod;
               }
           printf("%lld\n",sum);
         }
          return 0;
         }
