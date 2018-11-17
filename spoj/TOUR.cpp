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

vector<int>vec[1005],vrev[1005];
stack<int>stk;
int visited[1005],comp[1005],compvalid[1005];  //compvalid=0 means component no. is VALID

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
	int t;
	inp(t);
	while(t--)
	{
		int n,m,u,v,i,j,num=0,k=0,ans=0,cnt=0;
		inp(n);
		for(i=1;i<=n;i++)
		{
			inp(m);
			while(m--)
			{
			
				inp(u);
				vec[i].PB(u);
				vrev[u].PB(i);
			}
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
	
		for(i=0;i<num;i++)
		{
			if(compvalid[i]==0)
			cnt++;
		}
		
		if(cnt>1)
		printf("0\n");
		
		else{
		
		for(i=1;i<=n;i++)
		{
			if(compvalid[comp[i]]==0)
			ans++;
		}
		printf("%d\n",ans);
	}
		for(i=1;i<=n;i++)
		{
			visited[i]=0;
			comp[i]=0;
			vec[i].clear();
			vrev[i].clear();
		}
		
		for(i=0;i<num;i++)
		compvalid[i]=0;
		
		while(!stk.empty())
		stk.pop();
		
	}
	
	return 0;
}
	