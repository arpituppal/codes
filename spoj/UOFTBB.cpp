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

//int c[1010],r[1010],d[1010];
LL dp[1010];

int bisearch(LL ele, int n)
{
	int low=1,high=n,mid;
	while(low<=high)
	{
		mid=(low+high)/2;

		//check whether mid is the index of bloon going down
		if(dp[mid]==ele)
		return mid;
		if(dp[mid]>ele && dp[mid-1]<ele)
		return mid;

		if(dp[mid]>ele)
		high=mid-1;
		else
		low=mid+1;
	}
}


int main()
{
	int t;
	inp(t);
	while(t--)
	{
		int l,n,i,c,r,j,ans=0,cnt=0,m;
		LL d,h;
		inp(l);	//array size is of lenght L indexing from 1
		inp(n);
		for(i=0;i<n;i++)
		{
			inp(c);
			inp(r);
			inp1(d);
			cnt=0;
			for(j=c;j>=1 && j>=c-r ;j--) //left side c-r
			dp[j]+=d;
			for(j=c+1;j<=l && j<=c+r;j++)	//right side c+r
			dp[j]+=d;
		}
		for(i=2;i<=l;i++)
		dp[i]+=dp[i-1];	//dp[i] stores total damage on reaching cell i

		inp(m);
		while(m--)
		{
			inp1(h);
			if(h>dp[l])
			printf("Bloon leakage\n");
			else if(h<=dp[1])
			printf("1\n");
			else
			{
				ans=bisearch(h,l);
				printf("%d\n",ans);
			}
		}
		for(i=0;i<=l;i++)
		dp[i]=0;
	}
	return 0;
}
