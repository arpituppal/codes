#include<stdio.h>
#define mod 1000000007

void multiply(long long int F[2][2],long long int M[2][2]);
void power(long long int F[2][2],long long int n);
long long int fib(long long int n);

long long int fib(long long int n)
{
    long long int F[2][2]={{1,1},{1,0}};
    if(n==0)
    return 0;
    power(F,n-1);
    return (F[0][0]%mod);
 }
 void power(long long int F[2][2], long long int n)
 {

     if(n==0 || n==1)
     return;
    long long int M[2][2]={{1,1},{1,0}};
     power(F,n/2);
     multiply(F,F);
     if(n%2==1)
     multiply(F,M);
 }
 void multiply(long long int F[2][2],long long int M[2][2])
 {
   long long int a=((F[0][0]*M[0][0])%mod+(F[0][1]*M[1][0])%mod)%mod;
    long long int b=((F[0][0]*M[0][1])%mod+(F[0][1]*M[1][1])%mod)%mod;
    long long int c=((F[1][0]*M[0][0])%mod+(F[1][1]*M[1][0])%mod)%mod;
    long long int d=((F[1][0]*M[0][1])%mod+(F[1][1]*M[1][1])%mod)%mod;
    F[0][0]=a;
    F[0][1]=b;
    F[1][0]=c;
    F[1][1]=d;
 }
 int main()
 {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,m,ans1,ans2,ans;
        scanf("%lld %lld",&n,&m);
        ans1=fib(n+1);
        ans2=fib(m+2);
        ans=(ans2-ans1+mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
