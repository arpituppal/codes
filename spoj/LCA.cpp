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

int parent[1010],dist[1010];

int lca(int x,int y)
{
	if(dist[x]<dist[y])
	{
		while(dist[x]!=dist[y])
		y=parent[y];
	}
	else if(dist[y]<dist[x])
	{
		while(dist[y]<dist[x])
		x=parent[x];
	}
	while(x!=y)
	{
		x=parent[x];
		y=parent[y];
	}
	return x;
}

int main()
{
	int t,x;
	inp(t);
	for(x=1;x<=t;x++)
	{
		int n,i,j,m,u,v,q;
		inp(n);
		for(i=1;i<=n;i++)
		{dist[i]=0; parent[i]=i;}

		for(i=1;i<=n;i++)
		{
			inp(m);
			while(m--)
			{
				inp(u);
				parent[u]=i;
				dist[u]=dist[i]+1;
			}
		}
		inp(q);
		printf("Case %d:\n",x);
		while(q--)
		{
			inp(u);
			inp(v);
			if(u==v)
			printf("%d\n",u);
			else
			printf("%d\n",lca(u,v));
		}
	}
	return 0;
}

