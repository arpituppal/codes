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

char s[25][25];
int visited[25][25],n,m;


int safe(int x,int y)
{
	if(x>=0 && x<m && y>=0 && y<n && s[x][y]=='.')
	return 1;
	return 0;
}

void bfs(int sx,int sy)
{
	queue<pair<int,int> >q;
	int i;
	q.push(MP(sx,sy));
	visited[sx][sy]=1;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		if(safe(x,y+1) && !visited[x][y+1])
		{q.push(MP(x,y+1)); visited[x][y+1]=1;}
		
		if(safe(x,y-1) && !visited[x][y-1])
		{q.push(MP(x,y-1)); visited[x][y-1]=1;}
		
		if(safe(x+1,y) && !visited[x+1][y])
		{q.push(MP(x+1,y)); visited[x+1][y]=1;}
		
		if(safe(x-1,y) && !visited[x-1][y])
		{q.push(MP(x-1,y)); visited[x-1][y]=1;}
	}
}

int main()
{
	int t;
	inp(t);
	while(t--)
	{
		memset(visited,0,sizeof(visited));
		int i,j,cnt=0,sx,sy,dx,dy;
		inp(m);
		inp(n);
		for(i=0;i<m;i++)
		scanf("%s",s[i]);
		
		//1st and last row
		for(i=0;i<n;i++)
		{	
			if(s[0][i]=='.')
			{ 
			   cnt++;
			   if(cnt==1)
			   {sx=0;sy=i;dx=0;dy=i;}
			   else
			   {dx=0;dy=i;}
			}
			if(m!=1 && s[m-1][i]=='.')
			{
				cnt++;
				if(cnt==1)
				{sx=m-1;sy=i;dx=m-1;dy=i;}
				else
				{dx=m-1;dy=i;}
			}
		}	
		//1st and last column
		for(i=1;i<m-1;i++)
		{
			if(s[i][0]=='.')
			{
				cnt++;
				if(cnt==1)
				{sx=i;sy=0;dx=sx;dy=sy;}
				else
				{dx=i;dy=0;}
			}
			if(n!=1 && s[i][n-1]=='.')
			{
				cnt++;
				if(cnt==1)
				{sx=i;sy=n-1;dx=sx;dy=sy;}
				else
				{dx=i;dy=n-1;}
			}
		}
		/*if(s[0][0]=='.')
		cnt--;
		if(s[0][n-1]=='.' && n!=1)
		cnt--;
		if(s[m-1][0]=='.')
		cnt--;
		if(s[m-1][n-1]=='.' && m!=1)
		cnt--;*/
		//printf("%d %d %d %d %d\n",sx,sy,dx,dy,cnt);
		if(cnt!=2)
		{printf("invalid\n"); continue;}
		
		
		bfs(sx,sy);
		if(visited[dx][dy]==1)
		printf("valid\n");
		else
		printf("invalid\n");
	}
	return 0;
}
			