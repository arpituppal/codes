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
char s[50][50];
int dist[50][50],h,w,sx,sy,ex,ey;

int valid(int x, int y)
{
	if(x>=0 && x<h && y>=0 && y<w)
	return 1;
	return 0;
}

void bfs(int sx,int sy)
{
	dist[sx][sy]=0;
	if(valid(sx,sy+1) && s[sx][sy+1]!='X')
	{q.push(MP(sx,sy+1)); dist[sx][sy+1]=0;}
	
	if(valid(sx,sy-1) && s[sx][sy-1]!='X')
	{q.push(MP(sx,sy-1)); dist[sx][sy-1]=0;}
	
	if(valid(sx+1,sy) && s[sx+1][sy]!='X')
	{q.push(MP(sx+1,sy)); dist[sx+1][sy]=0;}
	
	if(valid(sx-1,sy) && s[sx-1][sy]!='X')
	{q.push(MP(sx-1,sy)); dist[sx-1][sy]=0;}
	
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		//printf("x=%d y=%d s=%d dist=%d\n",x,y,s[x][y]-48,dist[x][y]);
		if(valid(x,y+1) && s[x][y+1]!='X' && (dist[x][y]+(s[x][y]-48)<dist[x][y+1]))
		{
			q.push(MP(x,y+1));
			dist[x][y+1]=dist[x][y]+(s[x][y]-48);
		}
		if(valid(x,y-1) && s[x][y-1]!='X' && (dist[x][y]+(s[x][y]-48)<dist[x][y-1]))
		{
			q.push(MP(x,y-1));
			dist[x][y-1]=dist[x][y]+(s[x][y]-48);
		}
		if(valid(x+1,y) && s[x+1][y]!='X' && (dist[x][y]+(s[x][y]-48)<dist[x+1][y]))
		{
			q.push(MP(x+1,y));
			dist[x+1][y]=dist[x][y]+(s[x][y]-48);
		}
		if(valid(x-1,y) && s[x-1][y]!='X' && (dist[x][y]+(s[x][y]-48)<dist[x-1][y]))
		{
			q.push(MP(x-1,y));
			dist[x-1][y]=dist[x][y]+(s[x][y]-48);
		}
	}
}
	
int main()
{
	while(1)
	{
		int i,j;
		inp(w);
		inp(h);
		if(h==0 && w==0)
		break;
		for(i=0;i<h;i++)
		{
			scanf("%s",s[i]);
			for(j=0;j<w;j++)
			{
				if(s[i][j]=='S')
				{sx=i;sy=j;}
				if(s[i][j]=='D')
				{ex=i;ey=j; s[i][j]='0';}
			}
		}
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			dist[i][j]=INF;
		}
		
		bfs(sx,sy);
		/*for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			printf("%d ",dist[i][j]);
			printf("\n");
		}*/
		printf("%d\n",dist[ex][ey]);
		
		while(!q.empty())
		q.pop();
		char ch=getchar();
	}
	return 0;
}
