#include<stdio.h>
long long int a[100];
int main()
{
    a[0]=1;
    a[1]=2;
    int i;
    for(i=2;i<45;i++)
    a[i]=a[i-1]+a[i-2];
    long long int t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",a[n]);
    }
return 0;
}
