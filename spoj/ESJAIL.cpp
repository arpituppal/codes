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


vector<int>vec[100010];
int lock[100010],key[100010],visited[100010],flag=0,n;

void bfs(int s)
{
	queue<int>q,p;
	int i;
	visited[s]=1;
	q.push(s);
	
	while(!q.empty())
	{
		while(!q.empty())
		{
			int curr=q.front();
			q.pop();
			for(i=0;i<vec[curr].size();i++)
			{
				int nxt=vec[curr][i];
				if(!visited[nxt]){
				
				
				if(lock[nxt]==1)
				{visited[nxt]=1; continue;}
				
				if(nxt==n)
				{flag=1; return ;}
				
				if(key[nxt]!=0 && lock[key[nxt]]==1)
				{
					lock[key[nxt]]=0;
					p.push(key[nxt]);
				
				}
				visited[nxt]=1;
				q.push(nxt);
			}}
		}
		while(!p.empty())
		{
			int curr=p.front();
			p.pop();
			if(visited[curr]==1 && lock[curr]==0)
			q.push(curr);
		}
	}
}			
int main()
{
	while(1)
	{
		flag=0;
		int m,k,u,v,i,j;
		inp(n);
		inp(k);
		inp(m);
		if(n==-1 && k==-1 && m==-1)
		break;
		
		for(i=0;i<k;i++)
		{
			inp(u);
			inp(v);
			key[u]=v;
			lock[v]=1;
		}
		for(i=0;i<m;i++)
		{
			inp(u);
			inp(v);
			vec[u].PB(v);
			vec[v].PB(u);
		}
		bfs(1);
		if(flag==1)
		printf("Y\n");
		else
		printf("N\n");
		
		for(i=1;i<=n;i++)
		{
			vec[i].clear();
			lock[i]=0;
			key[i]=0;
			visited[i]=0;
		}
		
		
	}
	return 0;
}