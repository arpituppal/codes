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
#define mod 1000000007

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

int sieve[100000],prime[100000];

int main()
{
	int i,j,t,k=0;
	for(i=2;i*i<100000;i++)
	{
		if(!sieve[i])
		{
			prime[k++]=i;
			for(j=i*i;j<100000;j+=i)
			sieve[j]=1;
		}
	}
	for(;i<100000;i++)
	{
		if(sieve[i]==0)
		prime[k++]=i;
	}
	inp(t);
	while(t--)
	{
		int n;
		inp(n);
		LL ans=1,div=0;
		for(i=0;prime[i]<=n;i++)
		{
			int power=prime[i];
			div=0;
			while(power<=n)
			{
				div+=(n/power);
				power=power*prime[i];
			}
			div++;
			ans=(ans%mod *div%mod)%mod;
		}
	printf("%lld\n",ans);
	}
	return 0;
}
