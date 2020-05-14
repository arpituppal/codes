#include<stdio.h>
long long int gcd(long long int x, long long int y)
{
    if(x<y)
    gcd(y,x);
    if(y==0)
    return x;
    else
    return gcd(y,x%y);
}
 int main()
 {
    int t,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        long long int a,b,h;
        scanf("%lld %lld",&a,&b);
        h=gcd(a,b);
        printf("%lld %lld\n",(b/h),(a/h));
        }
        return 0;
    }
