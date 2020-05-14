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

char str[]="ALLIZZWELL";
char s[110][110];
int visited[110][110],r,c;
int dx[]={0,0,-1,1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,-1,1};
int solve(int x,int y,int l)
{
	int i;
	//printf("%d %c\n",l,s[x][y]);
	if(l==9)
	   return 1;
	visited[x][y]=1;
	int sol;
	for(i=0;i<8;i++)
	{
		int x1=x+dx[i];
		int y1=y+dy[i];
		if((x1>=0) && (x1<r) && (y1>=0) && (y1<c) && !visited[x1][y1])
		{
			if(s[x1][y1]==str[l+1])
			{
				sol=solve(x1,y1,l+1);
				if(sol)
				return 1;
			}
		}
	}
	visited[x][y]=0;
	return 0;
}

int main()
{
	int t;

	inp(t);
	while(t--)
	{
		int i,j;
		bool flag=false;
		inp(r);
		inp(c);
		for(i=0;i<r;i++)
		scanf("%s",s[i]);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(s[i][j]=='A')
				{
					if(solve(i,j,0)==1)
					{
						//printf("%d\n",solve(i,j,1));
						flag=true;
						break;
					}
				}
			}
		}
		if(flag)
		printf("YES\n");
		else
		printf("NO\n");
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			visited[i][j]=0;
		}
	}
	return 0;
}