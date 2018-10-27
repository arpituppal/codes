#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long unsigned int n,ans;
        scanf("%llu",&n);
        ans=192+(n-1)*250;
        printf("%llu\n",ans);
    }
    return 0;
}
