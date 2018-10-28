#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define getcx getchar_unlocked
#define N 1000000
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
void output(long long int x)  // Fast Output
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
    long long int len=0,data[10];
	while(x)
	{
		data[len++]=x%10;
		x/=10;
	}
	if(!len)
		data[len++]=0;
	while(len--)
		putchar(data[len]+48);
	putchar(' ');
}
long long int sieve[1000000],prime[1000000],pp[1000000],prod[1000000];
int main()
{
    long long int i,j,m,p=1,k=1,x=1,rev=0,t,n;
    for(i=2;i*i<N;i++)
    {
        if(sieve[i]==0)
        {
            prime[x++]=i;
            m=i;
            p=1;
            rev=0;
            for(j=i*i;j<=N;j+=i)
            sieve[j]=1;
            while(m>0)
            {
                rev=(rev*10)+(m%10);
                if((m%10)!=0)
                p=p*(m%10);
                m/=10;
            }
            if(rev==i)
            {
                pp[k]=i;
                prod[k]=p;
                k++;
            }
        }
    }
    for(;i<=N;i++)
    {
        if(sieve[i]==0)
        {
            prime[x++]=i;
            m=i;
            p=1;
            rev=0;
            while(m>0)
            {
                rev=(rev*10)+(m%10);
                if((m%10)!=0)
                p=p*(m%10);
                m/=10;
            }
            if(rev==i)
            {
                pp[k]=i;
                prod[k]=p;
                k++;
            }
        }
    }
  //  output(prime[1]);
    
    inp(t);
    while(t--)
    {
        inp(n);
        output(pp[n]);
        output(prime[prod[n]]);
        printf("\n");
    } 
    return 0;
  }