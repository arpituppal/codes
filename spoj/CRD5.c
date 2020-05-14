#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,ans,mod=1000007;
        scanf("%lld",&n);
        ans=((n*(3*n+1))/2)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
