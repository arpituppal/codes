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
#define MOD 1000000007
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

vector<int>vec[10010];
LL dist[10010];
int dest;

LL dfs(int curr)
{
	int i;
	//cout<<curr<<endl;
	if(curr==dest)
	return 1;
	
	if(dist[curr]!=-1)
	return dist[curr];
	
	LL ans=0;
	for(i=0;i<vec[curr].size();i++)
	 ans=( ans%MOD + dfs(vec[curr][i])%MOD )%MOD;
	
	
	dist[curr]=ans;
	return dist[curr];
}
int main()
{
	int t;
	inp(t);
	while(t--)
	{
		int c,b,s,x,y,i;
		inp(c);
		inp(b);
		inp(s);
		inp(dest);
		for(i=0;i<=c;i++)
		{
			dist[i]=-1;
			vec[i].clear();
		}
		
		while(b--)
		{
			inp(x);
			inp(y);
			vec[x].PB(y);
		}
		
		
		printf("%lld\n",dfs(s));
		
	}
	return 0;
}	