#include<stdio.h>
long long int a[1000000];
long long int value(long long int n)
{
    if(n<1000000)
    {
        if(a[n]!=0)
        return a[n];
    }
    if(n<n/2+n/3+n/4)
    return (value(n/2)+value(n/3)+value(n/4));
    else
    {
        if(n<1000000)
        a[n]=n;
        return n;
    }
}
int main()
{
    long long int i,n;
    for(i=0;i<1000000;i++)
    a[i]=value(i);
    while(scanf("%lld",&n)==1)
    printf("%lld\n",value(n));
    return 0;
}

