#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define getcx getchar_unlocked
#define N 1000010
using namespace std;
inline void inp(long long int &n) // Fast Input
{
	n=0;
	long long int ch=getcx();long long int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}
long long int a[N],ans[N];
int main()
{
    long long int t,i,j,f=2,x;
    ans[0]=0;
    ans[1]=1;
    for(i=2;i<=N/2;i++)
    {
        if(a[i]==0)
        ans[i]=f++;
        for(j=(i*i*i);j<N;j+=(i*i*i))
        a[j]=1;
    }
    for(;i<N;i++)
    {
        if(a[i]==0)
        ans[i]=f++;
    }        
    inp(t);
    for(x=1;x<=t;x++)
    {
        long long int n;
        inp(n);
        if(ans[n]==0)
        printf("Case %lld: Not Cube Free\n",x);
        else
        printf("Case %lld: %lld\n",x,ans[n]);
    }
    return 0;
 }