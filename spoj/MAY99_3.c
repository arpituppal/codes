#include<stdio.h>
long long int gcd(long long int a,long long int b)
{
    if(a<b)
    return gcd(b,a);
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int x,y,z,g;
        scanf("%lld %lld %lld",&x,&y,&z);
        if(x<z && y<z)
        printf("NO\n");
        else
        {
            g=gcd(x,y);
            if(z%g==0)
            printf("YES\n");
            else
            printf("NO\n");
        }
    }
    return 0;
}
