#include<stdio.h>
int main()
{
    while(1)
    {
        long long int n,ans;
        scanf("%lld",&n);
        if(n==0)
        break;
        ans=((n+1)*((3*n)+2))/2;
        printf("%lld\n",ans);
    }
    return 0;
}
