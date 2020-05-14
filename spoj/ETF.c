#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i;
        long long int res;
        scanf("%d",&n);
        res=n;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            res-=res/i;
            while(n%i==0)
            n=n/i;
        }
        if(n!=1)
        res-=res/n;
        printf("%lld\n",res);
    }
    return 0;
}
