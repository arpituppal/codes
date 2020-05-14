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

vector<int>vec[100010];
int visited[100010];
void dfs(int curr)
{
	int i;
	visited[curr]=1;
	for(i=0;i<vec[curr].size();i++)
	{
		if(!visited[vec[curr][i]])
		dfs(vec[curr][i]);
	}
	
}
int main()
{
	int t;
	inp(t);
	while(t--)
	{
		int n,e,a,b,ans=0,i;
		inp(n);
		inp(e);	
		while(e--)
		{
			inp(a);
			inp(b);
			vec[a].PB(b);
			vec[b].PB(a);
		}
		for(i=0;i<n;i++)
		{
			if(!visited[i])
			{
				ans++;
				dfs(i);
			}
		}
		printf("%d\n",ans);
		for(i=0;i<n;i++)
		{
			vec[i].clear();
			visited[i]=0;
		}
	}
	return 0;
}
		