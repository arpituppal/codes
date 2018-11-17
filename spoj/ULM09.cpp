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

vector<pair<LL,pair<int,int> > >vec;
int parent[200010],m,n;
LL ans=0;

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
	int pu=find(u);
	int pv=find(v);
	parent[pu]=pv;
}

void kruskal()
{
	int i,u,v,pu,pv,wt;
	sort(vec.begin(),vec.end());
	for(i=0;i<n;i++)
	{
	 	u=vec[i].second.first;
	 	v=vec[i].second.second;
	 	pu=find(u);
	 	pv=find(v);
	 	if(pu!=pv)
	 	{
	 		ans+=vec[i].first;
	 		uni(u,v);
	 	}
	 }
}

int main()
{
	while(1)
	{
		int u,v,i;
		LL total=0,wt;
		ans=0;
		inp(m);
		inp(n);
		if(m==0 && n==0)
		break;
		for(i=0;i<n;i++)
		{
			inp(u);
			inp(v);
			inp1(wt);
			vec.PB(MP(wt,MP(u,v)));
			total+=wt;
		}
		for(i=0;i<m;i++)
		parent[i]=i;
		kruskal();
		printf("%lld\n",(total-ans));
		vec.clear();
	}
	return 0;
}
