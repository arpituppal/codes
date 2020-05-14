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

int sieve[1000005],dp[1000005][10];

int main()
{
	int t,i,j;
	sieve[1]=0;
	for(i=2;i*i<1000005;i++)
	{
		if(!sieve[i])
		{
			for(j=2*i;j<1000005;j+=i)
			sieve[j]++;

			sieve[i]=1;
		}
	}

	for(;i<1000005;i++)
	{
		if(!sieve[i])
		{
			for(j=2*i;j<1000005;j+=i)
			sieve[j]++;

			sieve[i]=1;
		}
	}

	dp[1][0]=1;
	for(i=2;i<=1000000;i++)
	{
		dp[i][sieve[i]]=1;
		for(j=0;j<10;j++)
		dp[i][j]+=dp[i-1][j];
	}
	//printf("%d\n",sieve[6]);
	inp(t);
	while(t--)
	{
		int a,b,n;
		inp(a);
		inp(b);
		inp(n);
		printf("%d\n",dp[b][n]-dp[a-1][n]);
	}
	return 0;
}
