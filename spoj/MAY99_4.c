#include<stdio.h>
#define mod 10000007
long long int a[101][101];
int main()
{
    int i,j,n,r;
    for(i=0;i<101;i++)
    a[i][0]=1;
    for(i=1;i<101;i++)
    {
        for(j=1;j<101;j++)
        a[i][j]=((a[i-1][j]%mod)+ (a[i-1][j-1]%mod))%mod;
    }
     scanf("%d %d",&n,&r);
     if(n<r)
     printf("-1\n");
     else
     printf("%lld\n",a[n-1][r-1]);
     return 0;
}
