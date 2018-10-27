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
int max(int a,int b,int c,int d)
{
	if(a>=b && a>=c && a>=d)
	return a;
	if(b>=a && b>=c && b>=d)
	return b;
	if(c>=a && c>=b && c>=d)
	return c;
	if(d>=a && d>=b && d>=c)
	return d;
}
int main()
{
	int t;
	inp(t);
	while(t--)
	{
		int n,m,x,y,ul,ur,bl,br,ans;
		inp(n);
		inp(m);
		inp(x);
		inp(y);
		ul=(x-1)+(y-1);
		ur=(x-1)+(m-y);
		bl=(n-x)+(y-1);
		br=(n-x)+(m-y);
		ans=max(ul,ur,bl,br);
		printf("%d\n",ans);
	}
	return 0;
}