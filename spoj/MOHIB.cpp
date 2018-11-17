#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
      int t;
      scanf("%d",&t);
      while(t--)
      {
            long long int x,n,avg,sum=0,s=0;
            scanf("%lld %lld",&x,&avg);

            n=avg-x;
            s=n*(avg+1);
            sum=(n*(n+1))/2;
            long long int ans=(n+(s-sum));
            printf("%lld\n",ans);
      }
      return 0;
}
