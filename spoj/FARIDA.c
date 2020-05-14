#include<stdio.h>
long long int a[1000000],ans[1000000];
long long int max(long long int c,long long int d)
{
    if(c>d)
    return c;
    else
    return d;
}
 int main()
 {
    long long int t,x;
    scanf("%lld",&t);
    for(x=1;x<=t;x++)
     {
        long long int n,i,sum;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
        if(n==0)
        {
            printf("Case %lld: 0\n",x);
            continue;
        }
          ans[0]=0;
          ans[1]=0;
          for(i=0;i<n;i++)
          {
               sum=ans[i]+a[i];
               ans[i+2]=max(sum,ans[i+1]);
          }
         printf("Case %lld: %lld\n",x,ans[n+1]);
     }
     return 0;
}
