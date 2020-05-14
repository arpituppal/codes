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
double graph[110][110];
int main()
{
	int n,m;
	while(1)
	{
		int i,j,k,a,b,p;
		inp(n);
		if(n==0)
		break;
		inp(m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			graph[i][j]=0;
			graph[i][i]=1;
		}
		for(i=1;i<=m;i++)
		{
			inp(a);
			inp(b);
			inp(p);
			if(p/100.0>graph[a][b])
			{
				graph[a][b]=p/100.0;
				graph[b][a]=p/100.0;
			}
		}
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(graph[i][k]*graph[k][j]>graph[i][j])
					graph[i][j]=graph[i][k]*graph[k][j];
				}
			}
		}
		printf("%.6lf percent\n",graph[1][n]*100);
	}
	return 0;
}