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

vector<pair<int,int> >vec[100010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >PQ; 
int mincost[100010];

void dijsktra(int s)
{
	int i,cc,cn,nn,nc;
	mincost[s]=0; //source cost=0
	PQ.push(MP(0,s)); //1st value=cost 2nd value=node
	while(!PQ.empty())
	{
		cc=PQ.top().first;	//current cost
		cn=PQ.top().second;	//current node
		PQ.pop();
		//visited[cn]=1;
		for(i=0;i<vec[cn].size();i++)
		{
			nn=vec[cn][i].second; //next node
			nc=cc+vec[cn][i].first;  //new cost
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
	int t;
	inp(t);
	while(t--)
	{
		int n,m,s,e,i;
		inp(n);
		inp(m);
		inp(s);
		inp(e);
		for(i=0;i<=n;i++)
		{
			mincost[i]=INF;
			vec[i].clear();
		}
		for(i=1;i<=m;i++)
		{
			int u,v,wt;
			inp(u);
			inp(v);
			inp(wt);
			vec[u].PB(MP(wt,v));
			vec[v].PB(MP(wt,u));
		}
		dijsktra(s);
		if(mincost[e]==INF)
		printf("NONE\n");
		else
		printf("%d\n",mincost[e]);
	}
	return 0;
}
