#include<stdio.h>
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        printf("%lld\n",((a*a)-(2*b)));
     }
    return 0;
}
