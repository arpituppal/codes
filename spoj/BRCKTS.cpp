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

struct tree
{
	int opn,cls;
};
struct tree seg[120005];
char s[30005];

void build(int node,int st,int end)
{	
	if(st==end)
	{
		if(s[st]=='(')
		{seg[node].opn=1; seg[node].cls=0;}
		else
		{seg[node].opn=0; seg[node].cls=1;}
	
		return ;
	}
	
	int mid=(st+end)>>1;
	build(2*node,st,mid);
	build(2*node+1,mid+1,end);
	
	int m=MIN(seg[2*node].opn, seg[2*node+1].cls);
	seg[node].opn= seg[2*node].opn + seg[2*node+1].opn-m;
	seg[node].cls=seg[2*node].cls + seg[2*node+1].cls-m;
}
void update(int node,int st,int end,int idx)
{
	if(st==end)
	{
		if(st==idx)
		{
			if(s[st]=='(')
			{
				s[st]=')';
				seg[node].opn=0;
				seg[node].cls=1;
			}
			else
			{
				s[st]='(';
				seg[node].opn=1;
				seg[node].cls=0;
			}
		}
		return ;
	}
	int mid=(st+end)>>1;
	if(idx<=mid)
	update(2*node,st,mid,idx);
	else
	update(2*node+1,mid+1,end,idx);
	
	int m=MIN(seg[2*node].opn, seg[2*node+1].cls);
	seg[node].opn= seg[2*node].opn + seg[2*node+1].opn-m;
	seg[node].cls=seg[2*node].cls + seg[2*node+1].cls-m;
}

int main()
{
	int n,tst=0;
	while(scanf("%d",&n)!=EOF)
	{
		tst++;
		int k,m,i;
		scanf("%s",s);
		
		build(1,0,n-1);
		
		inp(m);
		printf("Test %d:\n",tst);
		while(m--)
		{
			inp(k);
			if(k==0)
			{
				if(seg[1].opn==0 && seg[1].cls==0) printf("YES\n");
				else printf("NO\n");
			}
			else
			update(1,0,n-1,k-1);
		}
	}
	return 0;
}