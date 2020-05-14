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

int arr[110][110],distc1[110][110],distc2[110][110],distm[110][110],visitedc1[110][110],visitedc2[110][110],visitedm[110][110],n,m;
queue<pair<int,int> >q;

int valid(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<m)
	return 1;
	return 0;
}

void bfs(int sx,int sy,int visited[][110],int dist[][110])
{
	visited[sx][sy]=1;
	dist[sx][sy]=0;
	q.push(MP(sx,sy));
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();

		if(valid(x,y-1) && !visited[x][y-1])
		{
			q.push(MP(x,y-1));
			visited[x][y-1]=1;
			dist[x][y-1]=dist[x][y]+1;
		}
		if(valid(x,y+1) && !visited[x][y+1])
		{
			q.push(MP(x,y+1));
			visited[x][y+1]=1;
			dist[x][y+1]=dist[x][y]+1;
		}
		if(valid(x-1,y) && !visited[x-1][y])
		{
			q.push(MP(x-1,y));
			visited[x-1][y]=1;
			dist[x-1][y]=dist[x][y]+1;
		}
		if(valid(x+1,y) && !visited[x+1][y])
		{
			q.push(MP(x+1,y));
			visited[x+1][y]=1;
			dist[x+1][y]=dist[x][y]+1;
		}
	}

		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			printf("%d ",dist[i][j]);
			printf("\n");

		}*/
}

int main()
{
	int i,j,k,flag=0,mx,my,c1x,c1y,c2x,c2y;
	inp(n);
	inp(m);
	inp(k);

	while(k--)
	{
		flag=0;
		inp(mx);
		inp(my);
		inp(c1x);
		inp(c1y);
		inp(c2x);
		inp(c2y);
		mx--;
		my--;
		c1x--;
		c1y--;
		c2x--;
		c2y--;

		bfs(mx,my,visitedm,distm);
		bfs(c1x,c1y,visitedc1,distc1);
		bfs(c2x,c2y,visitedc2,distc2);

		for(i=0;i<m;i++)	//1st check 1st and last row values
		{
			if((distm[0][i]<distc1[0][i] && distm[0][i]<distc2[0][i]) ||(distm[n-1][i]<distc1[n-1][i] && distm[n-1][i]<distc2[n-1][i]))
			{
				flag=1;
				break;
			}
		}

		if(flag==0)	//check for 1st and last column
		{
		for(i=0;i<n;i++)
		{
			if((distm[i][0]<distc1[i][0] && distm[i][0]<distc2[i][0]) || (distm[i][m-1]<distc1[i][m-1] && distm[i][m-1]<distc2[i][m-1]))
			{
				flag=1;
				break;
			}
		}
		}

		if(flag==1)
		printf("YES\n");
		else
		printf("NO\n");

		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				visitedm[i][j]=0;
				distm[i][j]=0;
				visitedc1[i][j]=0;
				distc1[i][j]=0;
				visitedc2[i][j]=0;
				distc2[i][j]=0;
			}
		}
	}
	return 0;
}
