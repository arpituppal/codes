/*
ARPIT UPPAL
MNNIT ALLAHABAD
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <sstream>
#include <utility>
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;
typedef long long LL;
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define PB push_back
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))
inline void inp( int &n )
{
n=0; int ch=getcx();int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
} 
inline void inp1( LL &n )
{
n=0; LL ch=getcx();LL sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
}

LL fib[101];

int main()
{
	int t,x;
	inp(t);
	fib[0]=0;
	fib[1]=1;
	for(x=2;x<101;x++)
	fib[x]=fib[x-1]+fib[x-2];
	
	for(x=1;x<=t;x++)
	{
		LL n,m,sum=0,cnt=0,flag=0;
		int i,j,low=0,high,mid;
		inp1(n);
		inp1(m);
		for(i=2;i*i<n;i++)
		{
			if(n%i==0){
			LL a=n/i;
			sum+=i+a;
			}
		}
		sum++;  //1 is a proper divisor
		if(i*i==n)
		sum+=i;   //perfect square
		
		sum=(sum%m);
		//printf("sum=%lld\n",sum);
		for(i=2;i*i<sum;i++)
			{
				if(sum%i==0)
				cnt+=2;
			}
		
		cnt++;
		if(i*i==sum)
		cnt++;
		
		low=0;
		high=100;
		//printf("cnt=%lld\n",cnt);
		while(low<=high)
		{
			mid=(low+high)/2;
			if(fib[mid]==cnt)
			{flag=1; break;}
			
			else if(cnt<fib[mid])
			high=mid-1;
			
			else
			low=mid+1;
		}
		
		if(flag==1)
		printf("Case #%d : YES.\n",x);
		else 
		printf("Case #%d : NO.\n",x);
	}
	return 0;
}
