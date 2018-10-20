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
int visited[10][10],dist[10][10],a,b,c,d;
int dx[]={-2,-2,1,1,2,2,-1,-1};
int dy[]={1,-1,-2,2,-1,1,-2,2};
void bfs(int a, int b)
{
	int i;
	q.push(MP(a,b));
	dist[a][b]=0;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		visited[x][y]=1;
		//if(x==c && y==d)
		//break;
		//cout<<x<<" "<<y<<endl;
		for(i=0;i<8;i++)
		{
			int newx=x+dx[i];
			int newy=y+dy[i];
			if(newx>=0 && newx<8 && newy>=0 && newy<8 && (dist[x][y]+(x*newx+y*newy)<dist[newx][newy]))
			{
			
				q.push(MP(newx,newy));
				dist[newx][newy]=dist[x][y]+(x*newx+y*newy);
			}
		}
	}
}

int main()
{
	while(scanf("%d",&a)!=EOF)
	{
		int i,j;
		scanf("%d %d %d",&b,&c,&d);
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=8;j++)
			{
				visited[i][j]=0;
				dist[i][j]=INF;
			}
		}
		bfs(a,b);
		
		if(visited[c][d]==0)
		printf("-1\n");
		else
		printf("%d\n",dist[c][d]);
		
		while(!q.empty())
		q.pop();
	}
	return 0;
}
