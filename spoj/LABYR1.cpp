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

queue<pair<int,int> >q;
int visited[1010][1010],dist[1010][1010],currx,curry,r,c;
char arr[1010][1010];

int valid(int x,int y)
{
	if(x>=0 && x<r && y>=0 && y<c)
	return 1;
	return 0;
}

void bfs(int sx,int sy)
{
	visited[sx][sy]=1;
	dist[sx][sy]=0;
	q.push(MP(sx,sy));
	while(!q.empty())
	{
		 currx=q.front().first;
		 curry=q.front().second;
		 q.pop();

		 if(valid(currx,curry+1) && !visited[currx][curry+1] && arr[currx][curry+1]=='.')
		 {
		 	q.push(MP(currx,curry+1));
		 	visited[currx][curry+1]=1;
		 	dist[currx][curry+1]=dist[currx][curry]+1;
		 }
		 if(valid(currx,curry-1) && !visited[currx][curry-1] && arr[currx][curry-1]=='.')
		 {
		 	q.push(MP(currx,curry-1));
		 	visited[currx][curry-1]=1;
		 	dist[currx][curry-1]=dist[currx][curry]+1;
		 }
		 if(valid(currx+1,curry) && !visited[currx+1][curry] && arr[currx+1][curry]=='.')
		 {
		 	q.push(MP(currx+1,curry));
		 	visited[currx+1][curry]=1;
		 	dist[currx+1][curry]=dist[currx][curry]+1;
		 }
		 if(valid(currx-1,curry) && !visited[currx-1][curry] && arr[currx-1][curry]=='.')
		 {
		 	q.push(MP(currx-1,curry));
		 	visited[currx-1][curry]=1;
		 	dist[currx-1][curry]=dist[currx][curry]+1;
		 }
	}
}

int main()
{
	int t;
	inp(t);
	while(t--)
	{
		int i,j,ans=-1,sx=-1,sy=-1;
		inp(c);
		inp(r);
		for(i=0;i<r;i++)
		{
			scanf("%s",arr[i]);
			if(sx==-1 && sy==-1)
			{
				for(j=0;j<c;j++)
				{
					if(arr[i][j]=='.')
					{sx=i; sy=j; break;}
				}
			}
		}
		bfs(sx,sy);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			visited[i][j]=0;
		}
		bfs(currx,curry);
		printf("Maximum rope length is %d.\n",dist[currx][curry]);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				visited[i][j]=0;
				dist[i][j]=0;
			}
		}
	}
	return 0;
}
