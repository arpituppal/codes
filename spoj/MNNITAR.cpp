#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define getcx getchar_unlocked
#define mod 1000000007
using namespace std;
inline void inp(long long int &n) // Fast Input
{
	n=0;
	long long int ch=getcx();
	long long int sign=1;
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
	putchar('\n');
}

void multiply(long long int F[2][2],long long int M[2][2]);
void power(long long int F[2][2],long long int n);
long long int fib(long long int n);
long long int modulus(long long int,long long int exp);


long long int fib(long long int n)
{
    long long int F[2][2]={{1,1},{1,0}};
    if(n==0)
    return 0;
    power(F,n-1);
    return F[0][0];
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
   long long int a=((F[0][0]*M[0][0])%(mod-1)+(F[0][1]*M[1][0])%(mod-1))%(mod-1);
    long long int b=((F[0][0]*M[0][1])%(mod-1)+(F[0][1]*M[1][1])%(mod-1))%(mod-1);
    long long int c=((F[1][0]*M[0][0])%(mod-1)+(F[1][1]*M[1][0])%(mod-1))%(mod-1);
    long long  int d=((F[1][0]*M[0][1])%(mod-1)+(F[1][1]*M[1][1])%(mod-1))%(mod-1);
    F[0][0]=a;
    F[0][1]=b;
    F[1][0]=c;
    F[1][1]=d;
 }
 long long int modumlus(long long int base,long long int exp)
{
     long long int res=1;
     while(exp>0)
      {
          if(exp%2==1)
           res=(res*base)%mod;
            exp=exp>>1;
            base=(base*base)%mod;
      }
      return res;
 }
 int main()
 {  
   int t;
   scanf("%d",&t);
   while(t--)
   {
   		
  	    long long int n,ans,ans1,base=2;
   		inp(n);
   		if(n==0)
   		printf("1\n");
   		else
   		{
   			ans=fib(n);
   			ans1=modumlus(base,ans)%mod;
   			output(ans1);
   		}
   	}
   	return 0;
   }
   