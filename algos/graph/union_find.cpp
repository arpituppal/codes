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

vector<pair<int,pair<int,int> > >vec,mst;
int parent[1010];
LL total=0;

int find(int u)
{
	if(u==parent[u])
	return u;
	int root=find(parent[u]);
	parent[u]=root;
	return root;
}

void uni(int u,int v)
{
	int ans1=find(u);
	int ans2=find(v);
	parent[ans1]=ans2;
}
void kruskal(int m)
{
	int i,pu,pv,u,v;
	sort(vec.begin(),vec.end());
	for(i=0;i<m;i++)
	{
		u=vec[i].second.first;
		v=vec[i].second.second;
		pu=find(u);
		pv=find(v);
		if(pu!=pv)	//no cycle
		{
			int wt=vec[i].first;
			mst.PB(MP(wt,MP(u,v)));
			total+=wt;
			uni(pu,pv);
		}
	}
}

int main()
{
	int t;
	inp(t);
	while(t--)
	{
		total=0;
		int n,i,u,v,wt,j,p,m;
		inp(p);
		inp(n);
		inp(m);
		for(i=1;i<=n;i++)
		parent[i]=i;
		for(i=1;i<=m;i++)
		{
			inp(u);
			inp(v);
			inp(wt);
			vec.PB(MP(wt,MP(u,v)));
		}
		kruskal(m);
		printf("%lld\n",(total*p));
		vec.clear();
		mst.clear(); 
	}
	return 0;
}
