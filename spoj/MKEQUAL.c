#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,sum=0,m,i;
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&m);
            sum+=m;
        }
        if(sum%n==0)
        printf("%lld\n",n);
        else
        printf("%lld\n",(n-1));
     }
    return 0;
}
