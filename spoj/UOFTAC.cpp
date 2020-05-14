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
char s[110][110];
int h,w;
int issafe(int x, int y)
{
	if(x<0 || x>h || y<0 || y>=w || s[x][y]=='S')
	   return 0;
	return 1;
}    
int main()
{
	int t;
	inp(t);
	while(t--)
	{
		int n,i,j,ans=0,x=0,y=0,dx,dy;
		char ch;
		inp(h);
		inp(w);
		inp(n);
		for(i=0;i<w;i++)
		s[0][i]='E';
		for(i=1;i<=h;i++)
		scanf("%s",s[i]);
		/*for(i=0;i<=h;i++)
		{
			for(j=0;j<w;j++)
			printf("%c ",s[i][j]);
			printf("\n");
		}*/
		for(i=1;i<=n;i++)
		{
			cin>>ch;
			if(ch=='L')
			{
				dx=0;
				dy=-1;
			}
			if(ch=='R')
			{
				dx=0;
				dy=1;
			}
			if(ch=='D')
			{
				dx=1;
				dy=0;
			}
			if(issafe(x+dx,y+dy))
			{
				x=x+dx;
				y=y+dy;
			}
			if(s[x][y]=='T')
			{
				ans++;
				s[x][y]='E';
			}
			while(s[x+1][y]=='E' && x<=h)
			x++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
			