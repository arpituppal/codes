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

int dist[110][110],n,m,arr[110][110];
queue<pair<int,int> >q;

int valid(int x, int y)
{
	if(x>0 && x<=m && y>0 && y<=n)
	return 1;
	return 0;
}

void bfs(int sx,int sy)
{
	dist[sx][sy]=arr[sx][sy];
	q.push(MP(sx,sy));
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();

		if(valid(x,y-1) && dist[x][y]+arr[x][y-1] < dist[x][y-1])
		{
			q.push(MP(x,y-1));
			dist[x][y-1]=dist[x][y]+arr[x][y-1];
		}
		if(valid(x,y+1) && dist[x][y]+arr[x][y+1] < dist[x][y+1])
		{
			q.push(MP(x,y+1));
			dist[x][y+1]=dist[x][y]+arr[x][y+1];
		}
		if(valid(x-1,y) && dist[x][y]+arr[x-1][y] < dist[x-1][y])
		{
			q.push(MP(x-1,y));
			dist[x-1][y]=dist[x][y]+arr[x-1][y];
		}
		if(valid(x+1,y) && dist[x][y]+arr[x+1][y] < dist[x+1][y])
		{
			q.push(MP(x+1,y));
			dist[x+1][y]=dist[x][y]+arr[x+1][y];
		}
	}
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j,v,a,b,ti;
		scanf("%d",&m);
		scanf("%d",&n);
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&arr[i][j]);
				dist[i][j]=INF;
			}
		}
		scanf("%d %d %d",&a,&b,&ti);

		bfs(1,1);
		if(dist[a][b]>ti)
		printf("NO\n");
		else
		printf("YES\n%d\n",(ti-dist[a][b]));
	}
	return 0;
}
