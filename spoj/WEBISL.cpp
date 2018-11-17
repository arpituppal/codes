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

vector<int>vec[1000000],vrev[1000000];
stack<int>stk;

int visited[1000000],comp[1000000],ans[1000000],mini=INF;	//comp stores component no of each node, ans stores min node value for each comp

void dfs(int curr)
{
	int i;
	visited[curr]=1;
	for(i=0;i<vec[curr].size();i++)
	{
		if(!visited[vec[curr][i]])
		dfs(vec[curr][i]);
	}
	stk.push(curr);
}

void dfsr(int curr,int c)
{
	int i;
	
	visited[curr]=1;
	comp[curr]=c;
	
	mini=MIN(mini,curr);
	for(i=0;i<vrev[curr].size();i++)
	{
		//printf("%d\n",vrev[curr][i]);
		if(!visited[vrev[curr][i]])
		dfsr(vrev[curr][i],c);
	}
}

int main()
{
	int n,m,u,v,i,j,c=0;
	inp(n);
	inp(m);
	for(i=0;i<m;i++)
	{
		inp(u);
		inp(v);
		vec[u].PB(v);
		vrev[v].PB(u);
	}
	
	for(i=0;i<n;i++)
	{
		if(!visited[i])
		dfs(i);
	}
	for(i=0;i<n;i++)
	visited[i]=0;
	
	while(!stk.empty())
	{
		int curr=stk.top();
		stk.pop();
		//printf("ll %d\n",curr);
		if(!visited[curr])
		{
			//printf("FORR %d\n",curr);
			mini=INF;
			dfsr(curr,c);
			ans[c++]=mini;
		}
	}
	for(i=0;i<n;i++)
	printf("%d\n",ans[comp[i]]);
	return 0;
}
	
