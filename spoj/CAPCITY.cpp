		/*To find nodes in a graph which are reachable from every other node in graph
			Strongly Connected Component modified */
			
		/*Basic idea- Find the Strongly connected components and give each node a component no(to which it belongs)
		Now if a node has an edge to another node which is in another component, then the component to which current node belongs
		is NOT VALID i.e. all nodes of current component cannot be the nodes reachable from every other node.
		In the end, nodes whose components are left valid are the answer */	

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

vector<int>vec[100005],vrev[100005];
stack<int>stk;
int visited[100005],comp[100005],compvalid[100005],ans[100005];  //compvalid=0 means component no. is VALID

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
void dfsr(int curr,int num)
{
	int i;
	visited[curr]=1;
	comp[curr]=num;
	for(i=0;i<vrev[curr].size();i++)
	{
		if(!visited[vrev[curr][i]])
		dfsr(vrev[curr][i],num);
	}
}

int main()
{
	int n,m,u,v,i,j,num=0,k=0;
	inp(n);
	inp(m);
	for(i=0;i<m;i++)
	{
		inp(u);
		inp(v);
		vec[u].PB(v);
		vrev[v].PB(u);
	}
	
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		dfs(i);
	}
	for(i=1;i<=n;i++)
	visited[i]=0;
	
	while(!stk.empty())
	{
		int curr=stk.top();
		stk.pop();
		if(!visited[curr])
		dfsr(curr,num++);
	}
	
	//checking whether edge from a node is going to a node of another component or not
	for(i=1;i<=n;i++)
	{
		for(j=0;j<vec[i].size();j++)
		{
			if(comp[i]!= comp[vec[i][j]])
			{
				compvalid[comp[i]]=1;
				break;
			}
		}
	}
	
	for(i=1;i<=n;i++)
	{
		if(compvalid[comp[i]]==0)
		ans[k++]=i;
	}
	printf("%d\n",k);
	for(i=0;i<k;i++)
	printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
	