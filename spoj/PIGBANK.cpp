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

int dp[10010],val[10010],wt[10010];


int main()
{
	int t;
	inp(t);
	while(t--)
	{
		int n,i,j,e,f,a,b;
		inp(e);
		inp(f);
		inp(n);
		for(i=0;i<n;i++)
		{
			inp(val[i]);
			inp(wt[i]);
		}

		f=f-e;
		for(i=0;i<=f;i++)
		dp[i]=INF;

		dp[0]=0;
		for(i=1;i<=f;i++)
		{
			//computing for weight=i
			for(j=0;j<n;j++)	//access all coins
			{
				if(i>=wt[j] && dp[i-wt[j]]!=INF && dp[i-wt[j]]+val[j]<dp[i])
				dp[i]=dp[i-wt[j]] + val[j];
			}
		}
		if(dp[f]==INF)
		printf("This is impossible.\n");
		else
		printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f]);
	}
	return 0;
}
