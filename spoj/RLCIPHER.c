#include<stdio.h>
long long int a[100001];
int ans(long long int m)
{
    if(m<0)
    return m;
    else if(m==1 || m==5)
    return -3;
    else if(m==2)
    return -2;
    else
    return -4;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,i,m;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
        for(i=0;i<n-1;i++)
        printf("%d ",ans(a[i]));
        printf("%d\n",ans(a[n-1]));

    }
    return 0;
}
