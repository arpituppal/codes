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

vector<pair<int,int> >vec[100000];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >PQ;
int mincost[10000];

void dijkstra(int s)
{
	int i;
	mincost[s]=0;
	PQ.push(MP(0,s));

	while(!PQ.empty())
	{
		int cc=PQ.top().first;
		int cn=PQ.top().second;
		PQ.pop();
		for(i=0;i<vec[cn].size();i++)
		{
			int nn=vec[cn][i].first;
			int nc=cc+vec[cn][i].second;
			if(nc<mincost[nn])
			{
				mincost[nn]=nc;
				PQ.push(MP(nc,nn));
			}
		}
	}
}

int main()
{
	int n,i,a,b,w,maxi=-1,u,q,v;
	inp(n);
	for(i=0;i<n;i++)
	{
		inp(a);
		inp(b);
		inp(w);
		maxi=MAX(maxi,MAX(a,b));
		vec[a].PB(MP(b,w));
		vec[b].PB(MP(a,w));
	}

	for(i=0;i<=500;i++)
	mincost[i]=INF;

	inp(u);

	dijkstra(u);
	inp(q);
	while(q--)
	{
		inp(v);
		if(mincost[v]==INF)
		printf("NO PATH\n");
		else
		printf("%d\n",mincost[v]);
	}
	return 0;
}

