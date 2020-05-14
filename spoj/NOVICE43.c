#include<stdio.h>
int main()
{
    long long int t,x;
    scanf("%lld",&t);
    int a[]={1, 2, 5, 15, 52, 203, 877, 4140, 21147, 115975, 678570};
    for(x=1;x<=t;x++)
    {
       int n;
       scanf("%d",&n);
       printf("%d\n",a[n-1]);
     }
     return 0;
}
