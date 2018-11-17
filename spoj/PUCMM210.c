#include<stdio.h>
#define N 1000000
#define mod 1000000003
int main()
{
    int t;
    long int a[N],b[N],i;
    a[0]=1;
    b[0]=1;
    for(i=2;i<=N;i++)
    {
        long long int res=1,base=i,exp=3;
        while(exp>0)
         {
             if(exp%2==1)
             res=(res*base)%mod;
             exp=exp>>1;
             base=(base*base)%mod;
         }
         a[i-1]=(a[i-2]+res)%mod;
         b[i-1]=(b[i-2]+a[i-1])%mod;
     }
     scanf("%d",&t);
     while(t--)
     {
         long int n;
        scanf("%ld",&n);
        printf("%ld\n",b[n-1]);
     }
     return 0;
    }
