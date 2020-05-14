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

stack<int>stk;
vector<int>vec[5010],vrev[5010];
int visited[5010],scc[5010],sccvalid[5010];

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

void dfsr(int curr, int num)
{
	int i;
	visited[curr]=1;
	scc[curr]=num;
	
	for(i=0;i<vrev[curr].size();i++)
	{
		if(!visited[vrev[curr][i]])
		dfsr(vrev[curr][i],num);
	}
}

	
int main()
{
	int n,m,i,j,u,v,curr,num=0;
	while(1)
	{
		num=0;
		scanf("%d",&n);
		if(n==0)
		break;
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&u,&v);
			vec[u].PB(v);
			vrev[v].PB(u);
		}
		
		for(i=1;i<=n;i++)
		{
			if(!visited[i])
				dfs(i);
		}
		
		for(i=0;i<=n;i++)
		visited[i]=0;
		
		while(!stk.empty())
		{
			
			curr=stk.top();
			stk.pop();
			//printf("%d\n",curr);
			if(!visited[curr])
			  dfsr(curr,num++);
		}
		
		for(i=1;i<=n;i++)
		{
			//check whether edge from this goes to other SCC
			for(j=0;j<vec[i].size();j++)
			{
				if(scc[i] != scc[vec[i][j]])
				{
					//printf("OOO  %d\n",i);
					sccvalid[scc[i]]=1;
					break;
				}
			}
		}
		//printf("%d\n",sccvalid[4]);
		//for(i=1;i<=n;i++)
		//printf("%d ",scc[i]);
		
		for(i=1;i<=n;i++)
		{
			if(sccvalid[scc[i]]==0)
			printf("%d ",i);
		}
		printf("\n");
		
		for(i=1;i<=n;i++)
		{
			vec[i].clear();
			vrev[i].clear();
			visited[i]=0;
			scc[i]=0;
		}
		for(i=0;i<num;i++)
		sccvalid[i]=0;
		
		while(!stk.empty())
		stk.pop();
	}
	return 0;
}
		