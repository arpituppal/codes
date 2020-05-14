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

char s[100010];
int main()
{
	int t,lp;
	scanf("%d",&t);
	for(lp=1;lp<=t;lp++)
	{
		int hash[100010],i,j,idx,m,n,c=0;
		char x;
		
		scanf("%d",&n);
		scanf("%s",s);
		printf("Case %d:\n",lp);
		scanf("%d",&m);
		
		n--;
		for(i=0,j=n;i<=j;i++,j--)
		{
			if(s[i]!=s[j])
			{ c++; hash[i]=1;}
			else
			   hash[i]=0;
			  
			hash[n-i]=0;
		}
		
		while(m--)
		{
			scanf("%d",&idx);
			getchar();
			scanf("%c",&x);
			
			idx--;
			s[idx]=x;
			
			if(s[idx]==s[n-idx])
			{
				if(hash[idx]==1 || hash[n-idx]==1)
				{
					c--;
					hash[idx]=0;
					hash[n-idx]=0;
				}
			}
			if(s[idx]!=s[n-idx])
			{
				if(hash[idx]==0 && hash[n-idx]==0)
				{
					c++;
					hash[idx]=1;
					hash[n-idx]=1;
				}
			}
			if(c==0)
			printf("YES\n");
			else
			printf("NO\n");
		}
	}
	return 0;
}