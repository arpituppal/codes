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

vector<int>vec[1010];
vector<pair<int,int> >vrank;
int visited[1010],rank[1010],out[1010];

int dfs(int curr)
{

	visited[curr]=1;
	int i;
	for(i=0;i<vec[curr].size();i++)
	{
		if(visited[vec[curr][i]])
		rank[curr]=MAX(rank[curr],rank[vec[curr][i]]+1);
		else
		rank[curr]=MAX(rank[curr],dfs(vec[curr][i])+1);
	}
	return rank[curr];
}
int main()
{
	int t,x;
	inp(t);
	for(x=1;x<=t;x++)
	{
		int n,r,a,b,i;
		inp(n);
		inp(r);
		while(r--)
		{
			inp(a);
			inp(b);
			vec[a].PB(b);
			out[a]++;
		}
		for(i=0;i<n;i++)
		{
			if(out[i]==0)
			{rank[i]=1;
			visited[i]=1;}
		}
		for(i=0;i<n;i++)
		{
			if(!visited[i])
			int ans=dfs(i);
		}
		for(i=0;i<n;i++)
		vrank.PB(MP(rank[i],i));

		sort(vrank.begin(),vrank.end());

		printf("Scenario #%d:\n",x);
		for(i=0;i<n;i++)
		printf("%d %d \n",vrank[i].first,vrank[i].second);

		for(i=0;i<n;i++)
		{
			vec[i].clear();
			visited[i]=0;
			rank[i]=0;
			out[i]=0;
		}
		vrank.clear();
	}
	return 0;
}
