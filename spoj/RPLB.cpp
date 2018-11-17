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
int keep[1010][1010],k[1010][1010];
int main()
{
	int t,x,wt[1010];
	inp(t);
	for(x=1;x<=t;x++)
	{
		int n,k1,i;
		inp(n);
		inp(k1);
		for(i=0;i<n;i++)
			inp(wt[i]);
	for(i=1;i<=n;i++)
	{
		for(int j=1;j<=k1;j++)
		{
			if(wt[i-1]>j)
			k[i][j]=k[i-1][j];
			else
			{
				if(keep[i-1][j]==1)
				k[i][j]=k[i-1][j];
				else
				{
				//printf("i=%d j=%d\n",i,j);
					if(k[i-1][j]>(wt[i-1]+k[i-1][j-wt[i-1]]))
					k[i][j]=k[i-1][j];
					else
					{
						
						k[i][j]=wt[i-1]+k[i-1][j-wt[i-1]];
						keep[i][j]=1;
					}
				}
				
//					k[i][j]=(MAX((k[i-1][j]),(b[i-1]+k[i-1][j-wt[i-1]])));
			}

		}
	}
		int ans=k[n][k1];
		printf("Scenario #%d: %d\n",x,ans); 
		for(i=0;i<=n;i++)
		{
			for(int j=0;j<=k1;j++)
			{
				k[i][j]=0;
				keep[i][j]=0;
			}
		}
	}
	return 0;
}