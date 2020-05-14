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

int parent[100010],sz[100010];

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
	sz[ans2]=sz[ans2]+sz[ans1];
}

int main()
{
	int n,m,q,x,y,i;
	char ch;
	inp(n);
	inp(m);
	
	for(i=1;i<=n;i++)
	{
		parent[i]=i;
		sz[i]=1;
	}
	
	inp(q);
	while(q--)
	{
		scanf("%c",&ch);
		if(ch=='A')
		{
			inp(x);
			inp(y);
			
			int u=find(x);
			int v=find(y);
			if(sz[u]+sz[v]<=m)
				uni(u,v);
		}
		if(ch=='E')
		{
			inp(x);
			inp(y);
			int u=find(x);
			int v=find(y);
			if(u==v)
			printf("Yes\n");
			else 
			printf("No\n");
		}
		if(ch=='S')
		{
			inp(x);
			int u=find(x);
			printf("%d\n",sz[u]);
		}
	}
	return 0;
}
		