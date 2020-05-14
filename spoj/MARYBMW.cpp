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

vector<pair<int,long long int> >vec[50010];
queue<pair<int,long long int> >q;		//q stores max speed to reach node i

LL dist[50010];

void bfs(int s)
{
	int i;
	dist[s]=0;
	q.push(MP(s,INFL));
	while(!q.empty())
	{
		int v=q.front().first;
		LL val=q.front().second;
		q.pop();
		
		for(i=0;i<vec[v].size();i++)
		{
			LL sp=MIN(val,vec[v][i].second);
			
			if(sp>dist[vec[v][i].first])
			{
				q.push(MP(vec[v][i].first,sp));
				dist[vec[v][i].first]=sp;
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
		int n,m,i,u,v;
		LL val;
		inp(n);
		inp(m);
		for(i=0;i<m;i++)
		{
			inp(u);
			inp(v);
			inp1(val);
			vec[u].PB(MP(v,val));
			vec[v].PB(MP(u,val));
		}
		
		bfs(1);
		if(dist[n]==0)
		printf("-1\n");
		else
		printf("%lld\n",dist[n]);
		
		for(i=1;i<=n;i++)
		{
			dist[i]=0;
			vec[i].clear();
		}
	}
	return 0;
}