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

LL bit[1025][1025];
char s[100];
int n;

void update(int x, int y, LL val)
{
	int y1;
	while(x<=n)
	{
		y1=y;
		//printf("xin %d\n",n);
		
		while(y1<=n)
		{
			//printf("yin %d\n",y1);
			bit[x][y1]+=val;
			y1+=(y1 & -y1);
		}
		x+=(x & -x);
	}
}

LL query(int x, int y)
{
	int y1;
	LL sum=0;
	while(x>0)
	{
		y1=y;
		while(y1>0)
		{
			sum+=bit[x][y1];
			y1-=(y1 & -y1);
		}
		
		x-=(x & -x);
	}
	return sum;
}
int main()
{
	int t;
	inp(t);
	while(t--)
	{
		memset(bit,0,sizeof(bit));
		int x1,y1,x2,y2,x,y;
		LL num;
		inp(n);
		while(1)
		{
			scanf("%s",s);
			//printf("%s\n",s);
			if(s[0]=='E')
			break;
			if(s[0]=='S' && s[2]=='T')
			{
				inp(x);
				inp(y);
				inp1(num);
				x++;
				y++;
				LL val=query(x,y)-query(x,y-1)-query(x-1,y)+query(x-1,y-1);
				
				update(x,y,num-val);
			}
			if(s[0]=='S' && s[2]=='M')
			{
				//printf("yes\n");
				inp(x1);
				inp(y1);
				inp(x2);
				inp(y2);
				x1++;
				x2++;
				y1++;
				y2++;
				LL ans=0;
				ans=query(x2,y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1);
				printf("%lld\n",ans);
			}
		}
		printf("\n");
	}
	return 0;
}
