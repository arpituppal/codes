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

LL arr[1000000],dp[1000000];

LL maxi(LL a,LL b,LL c)
{
	if(a>=b && a>=c)
	return a;
	if(b>=a && b>=c)
	return b;
	else
	return c;
}
int main()
{
	int t;
	inp(t);
	while(t--)
	{
		int n,i;

		inp(n);
		memset(arr,0,sizeof(arr));

		for(i=0;i<n;i++)
		inp1(arr[i]);

		memset(dp,0,sizeof(dp));

		for(i=n-1;i>=0;i--)
		dp[i]=maxi(arr[i]+dp[i+2],arr[i]+arr[i+1]+dp[i+4],arr[i]+arr[i+1]+arr[i+2]+dp[i+6]);


		printf("%lld\n",dp[0]);


	}

	return 0;
}
