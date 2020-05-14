#include<stdio.h>
long long int gcd(long long int a, long long int b)
{
    if(b>a)
    gcd(b,a);
    if(b==0)
    return a;
    else
    gcd(b,a%b);
}
int main()
{
    long long int n,x1,x,a[1000000],i,g,ans=0;
    scanf("%lld",&n);
    scanf("%lld",&x1);
    for(i=0;i<n-1;i++)
    {
        scanf("%lld",&x);
        a[i]=x-x1;
        x1=x;
    }
    g=gcd(a[0],a[1]);
    for(i=2;i<n-1;i++)
    g=gcd(g,a[i]);
 //   printf("gcd=%lld\n",g);
    for(i=0;i<n-1;i++)
    ans+=(a[i]/g)-1;
    printf("%lld\n",ans);
    return 0;
}
