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

LL modulo(LL base, LL exp)
{
	LL res=1;
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
	inp(t);
	while(t--)
	{
		LL n,n1;
		inp1(n);
		
		if(n%3==0)
		n1=n/3;
		else if(n%3==1)
		n1=(n-4)/3;
		else if(n%3==2)
		n1=(n-2)/3;
		
		LL ans=modulo(3,n1);
	
		if(n%3==1)
		ans=(ans*4)%mod;
		else if(n%3==2)
		ans=(ans*2)%mod;
		
		if(n==1)
		ans=1;
		printf("%lld\n",ans);
	}
	return 0;
}
		
