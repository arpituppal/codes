#include<stdio.h>
int main()
{
    int n,i;
    long long int a[25];
    a[0]=1;
    a[1]=3;
    for(i=2;i<25;i++)
    a[i]=2*a[i-1]+a[i-2];
    scanf("%d",&n);
    printf("%lld\n",a[n]);
    return 0;
}
