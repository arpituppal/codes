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

char s[55][55];
int h,w,dist[55][55];
int dx[]={0,0,-1,1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,-1,1};
int solve(int x,int y)
{
	int i;
	if(dist[x][y]!=-1)
	return dist[x][y];
	dist[x][y]=0;
	for(i=0;i<8;i++)
	{
		int x1=x+dx[i];
		int y1=y+dy[i];
		if(x1>=0 && x1<h && y1>=0 && y1<w)
		{
			if(s[x1][y1]==(s[x][y]+1))
			  dist[x][y]=MAX(dist[x][y],1+solve(x1,y1));
			
		}
	}
	return dist[x][y];
}
int main()
{
	int z=0;
	while(1)
	{
		z++;
		int i,j,ans=-1;
		inp(h);
		inp(w);
		if(h==0 && w==0)
		break;
		for(i=0;i<h;i++)
		 scanf("%s",s[i]);
		 for(i=0;i<h;i++)
		 {
		 	for(j=0;j<w;j++)
		 	dist[i][j]=-1;
		 }
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				if(s[i][j]=='A' && dist[i][j]==-1)
					ans=MAX(ans,solve(i,j));
			}
		}
		printf("Case %d: %d\n",z,ans+1);
		
	}
	return 0;
}