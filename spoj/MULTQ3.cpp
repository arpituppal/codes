			
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
	int zero,one,two;
};
struct tree seg[400005];

int flag[400005];

void build(int node,int st,int end)
{
	if(st==end)
	{
		seg[node].zero=1;
		seg[node].one=0;
		seg[node].two=0;
		flag[node]=0;	// 0 means no pending update, 1 means 1 time increment update, 2 means 2 times incremetn update]
		return ;
	}
	int mid=(st+end)>>1;
	build(2*node,st,mid);
	build(2*node+1,mid+1,end);
	
	seg[node].zero=seg[2*node].zero+seg[2*node+1].zero;
	seg[node].one=0;
	seg[node].two=0;
	flag[node]=0;
}

void flag_resolve(int node,int st,int end)
{
	int zcnt=seg[node].zero;
	int ocnt=seg[node].one;
	int tcnt=seg[node].two;
	if(flag[node]%3==1)	//net pending update is +1
	{
		flag[node]=0;
		
		seg[node].zero=tcnt;
		seg[node].one=zcnt;
		seg[node].two=ocnt;
		
		if(st!=end)
		{
			flag[2*node]=(flag[2*node]+1)%3;
			flag[2*node+1]=(flag[2*node+1]+1)%3;
		}
	}
	else if(flag[node]%3==2)	//net pending update +2
	{
		flag[node]=0;
		seg[node].zero=ocnt;
		seg[node].one=tcnt;
		seg[node].two=zcnt;
		if(st!=end)
		{
			flag[2*node]=(flag[2*node]+2)%3;
			flag[2*node+1]=(flag[2*node+1]+2)%3;
		}
	}
}

void update(int node,int st,int end,int i,int j)
{
	if(st>end || i>end || j<st)
	{
		flag_resolve(node,st,end);
		return ;
	}
	if(i<=st && j>=end)
	{
		flag[node]=(flag[node]+1)%3;
		flag_resolve(node,st,end);
		return ;
	}
	flag_resolve(node,st,end);
	
	int mid=(st+end)>>1;
	update(2*node,st,mid,i,j);
	update(2*node+1,mid+1,end,i,j);
	
	if(st!=end)
	{	
		seg[node].zero=seg[2*node].zero+seg[2*node+1].zero;
		seg[node].one=seg[2*node].one+seg[2*node+1].one;
		seg[node].two=seg[2*node].two + seg[2*node+1].two;
	}
}

tree query(int node,int st,int end,int i,int j)
{
	if(st>end || i>end || j<st) return (tree){0,0,0};
	
	flag_resolve(node,st,end);
	
	if(i<=st && j>=end) return seg[node];
	
	int mid=(st+end)>>1;
	tree left=query(2*node,st,mid,i,j);
	tree right=query(2*node+1,mid+1,end,i,j);
	
	int zc=left.zero+right.zero;
	int oc=left.one+right.one;
	int tc=left.two+right.two;
	return (tree){zc,oc,tc}; 
}
		
int main()
{
	int n,q,l,r,i,k;
	inp(n);
	inp(q);
	
	build(1,0,n-1);
	while(q--)
	{
		inp(k);
		inp(l);
		inp(r);
		if(k==0)
		update(1,0,n-1,l,r);
		else
		{
			tree ans=query(1,0,n-1,l,r);
			printf("%d\n",ans.zero);
		}
	}
	return 0;
}