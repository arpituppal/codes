#include<stdio.h>
unsigned long long int etf(unsigned long long int n)
{
     unsigned long long int res=n,i;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            res-=res/i;
            while(n%i==0)
            n=n/i;
        }
        if(n!=1)
        res-=res/n;
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned long long int n,i,h=0,ans;
        scanf("%llu",&n);
        for(i=1;i<=n;i++)
        h+=etf(i);
        ans=h*h;
        printf("%llu\n",ans);
    }
    return 0;
}
