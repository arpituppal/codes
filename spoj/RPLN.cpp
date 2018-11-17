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

int seg[400040],arr[100010];

void build(int node,int st,int end)
{
	if(st==end)
	{
		seg[node]=arr[st];
		return ;
	}
	int mid=(st+end)>>1;
	build(2*node,st,mid);
	build(2*node+1,mid+1,end);
	seg[node]=MIN(seg[2*node],seg[2*node+1]);
}

int query(int node,int st,int end,int x, int y)
{
	if(x>end || y<st || st>end) return -1;
	
	if(x<=st && y>=end) return seg[node];
	
	int mid=(st+end)>>1;
	int ans1=query(2*node,st,mid,x,y);
	int ans2=query(2*node+1,mid+1,end,x,y);
	
	if(ans1==-1)
	return ans2;
	if(ans2==-1)
	return ans1;
	
	return (MIN(ans1,ans2));
	
}
int main()
{	
	int t,tst;
	inp(t);
	for(tst=1;tst<=t;tst++)
	{
		int n,q,x,y,i;
		//memset(seg,0,sizeof(seg));
		inp(n);
		inp(q);
		for(i=0;i<n;i++)
		inp(arr[i]);
		
		build(1,0,n-1);
		printf("Scenario #%d:\n",tst);
		while(q--)
		{
			inp(x);
			inp(y);
			x--;
			y--;
			printf("%d\n",query(1,0,n-1,x,y));
		}
	}
	return 0;
}