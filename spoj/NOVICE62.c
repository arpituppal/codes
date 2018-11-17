#include<stdio.h>
#define mod 1000000007
long long int a[1000001];
int main()
{
    int t,i;
    scanf("%d",&t);
    a[0]=0;
    a[1]=0;
    a[2]=1;
    for(i=3;i<1000001;i++)
        a[i]=((i-1)*((a[i-1]+a[i-2])%mod))%mod;
    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
