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

vector<int>vec[350];
 
int check[350][350],n,s,visit=0,deg[350];

void dfs(int curr,int par)
{
	int i;
	if(curr>par)
	check[par][curr]--;
	else
	check[curr][par]--;
	//lastnode=curr;
	for(i=0;i<vec[curr].size();i++)
	{
		int next=vec[curr][i];
		if(curr<next)
		visit=check[curr][next];
		else
		visit=check[next][curr];
		
		if(visit!=0)
		dfs(next,curr);
	}	
}
	
int main()
{
	int t;
	inp(t);
	while(t--)
	{
		int i,j,x,y,mx=-1,flag=0;
		inp(n);
		while(1)
		{
			inp(i);
			inp(j);
			deg[i]++;
			deg[j]++;
			mx=MAX(mx,i);
			mx=MAX(mx,j);
			if(i==-1 && j==-1)
			break;
			if(i>j)
			{
				x=i;
				i=j;
				j=x;
			}
			if(check[i][j]==0)
			{
				vec[i].PB(j);
				vec[j].PB(i);
				check[i][j]++;
			}
			else
			{
				vec[j].PB(i);
				check[i][j]++;
			}
		}
		for(x=1;x<mx;x++)
		{
			if(deg[x]%2==1)
			{
				flag=1;
				break;
			}
		}
		//dfs(n,-1);
		if(flag==0)
		printf("YES\n");
		else
		printf("NO\n");
		for(x=0;x<350;x++)
		{
			deg[x]=0;
			vec[x].clear();
			for(y=0;y<350;y++)
			check[x][y]=0;
		}
	}
	return 0;
}
		