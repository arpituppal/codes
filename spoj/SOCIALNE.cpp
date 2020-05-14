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

int main()
{
	int t;
	inp(t);
	while(t--)
	{
		char s[100];
		int m,i,j,k,graph[60][60],n,best,idx,cnt;
		scanf("%s",s);
		//printf("%s\n",s);
		for(i=0;s[i]!='\0';i++)
			graph[0][i]=(s[i]=='Y')?1:INF;
		n=i;
		//printf("%d\n",n);
		for(i=1;i<n;i++)
		{
			scanf("%s",s);
			for(j=0;s[j]!='\0';j++)
			graph[i][j]=(s[j]=='Y')?1:INF;
		}
		best=0;
		idx=0;
		for(k=0;k<n;k++)
		{
			cnt=0;
			for(i=0;i<n;i++)
			{
				if(k!=i && graph[k][i]==INF)
				{
					for(j=0;j<n;j++)
					{
						if(i!=j)
						{
							if(graph[k][j]!=INF && graph[i][j]!=INF)
							break;
						}
					}
					if(j<n)
					cnt++;
				}
			}
			if(cnt>best)
			{
				best=cnt;
				idx=k;
			}
		}
		printf("%d %d\n",idx,best);
	}
		return 0;
}
