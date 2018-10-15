#include<stdio.h>
long long int ans(long long int n1)
{
    long long int a[]={1,2,4,8,16,32,64,128,256,512,1024,2048};
    int i;
    for(i=0;i<12;i++)
    {
        if(n1==a[i] || n1<a[i])
        return i;
    }
}
int main()
{
    int t,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        long long int n,m,k,ans1,ans2;
        scanf("%lld %lld %lld",&n,&m,&k);
        ans1=n*m*k-1;
        ans2=ans(n)+ans(m)+ans(k);
        printf("Case #%d: %lld %lld\n",x,ans1,ans2);
    }
    return 0;
}
