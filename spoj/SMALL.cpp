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
#define N 1000001
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

int prime[N];

int main()
{
	int t,i,j,n;
	long long int ans=1,power=1;
	inp(t);
	for(i=2;i*i<N;i++)
	{
		if(!prime[i])
		{
			for(j=i*i;j<N;j+=i)
			prime[j]=1;
		}
	}
	while(t--)
	{
		ans=1;
		inp(n);
		for(i=2;i<=n;i++)
		{
			if(!prime[i])
			{
				//printf("yes %d\n",i);
				power=1;
				while((power*i)<=n)
				power=(power*i);
				ans=(ans%mod *power%mod)%mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}