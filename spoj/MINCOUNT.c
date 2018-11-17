#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,k,ans;
        scanf("%lld",&n);
        if(n<1)
        n=1;
        n--;
        k=n/3;
        ans=k*(k+1)/2*3+(n%3)*(k+1);
        printf("%lld\n",ans);
    }
    return 0;
}
