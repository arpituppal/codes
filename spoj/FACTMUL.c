#include<stdio.h>
#define mod 109546051211
long long int fact[588000],ans[588000];
long long int multiply(long long int a,long long int b)
    {
    long long int q=(long long int)(((long double)a*(long double)b)/(long double)mod);
    long long int r=a*b-q*mod;
    r%=mod;
    if(r<0)r+=mod;
    return r;
    }
int main()
{
    fact[0]=1;
    ans[0]=1;
    long long int n;
    int i;
    scanf("%lld",&n);
    for(i=1;i<=587117;i++)
    {
        fact[i]=(i*fact[i-1])%mod;
        ans[i]=multiply(fact[i],ans[i-1]);
    }
    if(n>587117)
        printf("0\n");
    else
    printf("%lld\n",ans[n]);
    return 0;
}
