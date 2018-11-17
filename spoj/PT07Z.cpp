/*
ARPIT UPPAL
MNNIT ALLAHABAD
*/
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

vector<int>vec[10010];
queue<int>q;
int dist[10010],visited[10010];
int bfs(int s)
{
	int i,curr;
	visited[s]=1;
	q.push(s);
	dist[s]=0;
	while(!q.empty())
	{
		curr=q.front();
		q.pop();
		for(i=0;i<vec[curr].size();i++)
		{
			if(!visited[vec[curr][i]])
			{
				q.push(vec[curr][i]);
				visited[vec[curr][i]]=1;
				dist[vec[curr][i]]=dist[curr]+1;
			}
		}
	}
	return curr;	
}
int main()
{
	int i,n,u,v;
	inp(n);
	for(i=1;i<n;i++)
	{
		inp(u);
		inp(v);
		vec[u].PB(v);
		vec[v].PB(u);
	}
	int node=bfs(1);
	for(i=0;i<=n;i++)
	visited[i]=0;
	int ans=bfs(node);
	printf("%d\n",dist[ans]);
	return 0;
}
	