#include<stdio.h>
#include<math.h>
void multiply(long long int F[2][2],long long int M[2][2],long long int mod);
void power(long long int F[2][2],long long int n,long long int mod);
long long int fib(long long int n,long long int mod);

long long int fib(long long int n,long long int mod)
{
    long long int F[2][2]={{1,1},{1,0}};
    if(n==0)
    return 0;
    power(F,n-1,mod);
    return ((F[0][0])%mod);
}
 void power(long long int F[2][2], long long int n,long long int mod)
 {

     if(n==0 || n==1)
     return;
    long long int M[2][2]={{1,1},{1,0}};
     power(F,n/2,mod);
     multiply(F,F,mod);
     if(n%2==1)
     multiply(F,M,mod);
 }
 void multiply(long long int F[2][2],long long int M[2][2],long long int mod)
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
        long long int c,m,mod;
        scanf("%lld %lld",&c,&m);
        mod=pow(2,m);
        printf("%lld\n",fib(c+1,mod));
    }
    return 0;
}
