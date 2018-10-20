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

char s[10000];
int main()
{
	int hash[100010],active[100010];
	int t;
	inp(t);
	while(t--)
	{
		int n,i,m,ans=0;
		inp(n);
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			if(s[0]=='c')
			{
				inp(m);
				hash[i]=m;
			}
			else
			hash[i]=0;
			active[i]=1;
		}
		for(i=n;i>=1;i--)
		{
			if(hash[i]>0 && active[i]>0)
			active[hash[i]]=0;
		}
		for(i=1;i<=n;i++)
		{
			if(active[i]==1)
			ans++;
		}
		printf("%d\n",ans);
		for(i=1;i<=n;i++)
		{
			if(active[i]==1)
			{
				if(i!=n)
				printf("%d ",i);
				else
				printf("%d\n",i);
			}
		}
	}
	return 0;
}
		