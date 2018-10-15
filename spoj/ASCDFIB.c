#include<stdio.h>
#define mod 100000
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
long long int a[1000000];
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
    int t,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {

        long long int n,m,res,i,c,res1,mini,maxi,freq=0;
        for(i=0;i<1000000;i++)
        a[i]=0;
        scanf("%lld %lld",&n,&m);
        res=fib(n-1);
        res1=fib(n);
        mini=min(res,res1);
        maxi=max(res,res1);
        a[res]++;
        a[res1]++;
        for(i=0;i<m-1;i++)
        {
            c=(res%mod+res1%mod)%mod;
            res=res1%mod;
            res1=c;
            a[c]++;
            mini=min(c,mini);
            maxi=max(c,maxi);
        }
        printf("Case %d:",x);
        for(i=mini;i<=maxi;i++)
        {
            if(freq==100)
            break;
            while(a[i]--)
            {
                if(freq==100)
                    break;
                freq++;
                printf(" %lld",i);
            }
        }
        printf("\n");
    }
    return 0;
}
