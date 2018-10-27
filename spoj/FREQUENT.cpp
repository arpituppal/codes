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
	int lfreq;   //no of elements consecutively same as leftmost element of given range
	int rfreq;	//no of elements consecutively same as rightmost element of given range
	int mxfreq;
};
struct tree seg[400005];

int arr[100005];

void build(int node,int st,int end)
{
	if(st==end)
	{
		seg[node].lfreq=1;
		seg[node].rfreq=1;
		seg[node].mxfreq=1;
		return ;
	}
	int mid=(st+end)>>1;
	build(2*node,st,mid);
	build(2*node+1,mid+1,end);
	
	if(arr[mid]==arr[mid+1])  //consecutive elements of two nodes same
	{
		if(arr[st]==arr[mid]) //all elements in left node are same
		seg[node].lfreq=seg[2*node].lfreq+seg[2*node+1].lfreq;
		else
		seg[node].lfreq=seg[2*node].lfreq;
		
		if(arr[mid+1]==arr[end])  //all elements in right node same
		seg[node].rfreq=seg[2*node+1].rfreq+ seg[2*node].rfreq;
		else
		seg[node].rfreq=seg[2*node+1].rfreq;
		
		seg[node].mxfreq=MAX(seg[2*node].mxfreq, MAX(seg[2*node+1].mxfreq, seg[2*node].rfreq + seg[2*node+1].lfreq));
	}
	else
	{
		seg[node].lfreq=seg[2*node].lfreq;
		seg[node].rfreq=seg[2*node+1].rfreq;
		seg[node].mxfreq=MAX(seg[2*node].mxfreq, seg[2*node+1].mxfreq);
	}
}

tree query(int node,int st,int end,int i,int j)
{
	if(i>end || j<st ||st>end) return (tree){0,0,0};
	if(i<=st && j>=end) return seg[node];
	
	int mid=(st+end)>>1;
	tree left=query(2*node,st,mid,i,j);
	tree right=query(2*node+1,mid+1,end,i,j);
	
	int lf,rf,mf;
	
	if(arr[mid]==arr[mid+1])
	{
		if(arr[st]==arr[mid]) //all elements in left node are same
		lf=left.lfreq+right.lfreq;
		else
		lf=left.lfreq;
		
		if(arr[mid+1]==arr[end])  //all elements in right node same
		rf=right.rfreq+ left.rfreq;
		else
		rf=right.rfreq;
		
		mf=MAX(left.mxfreq, MAX(right.mxfreq, left.rfreq + right.lfreq));
	}
	else
	{
		lf=left.lfreq;
		rf=right.rfreq;
		mf=MAX(left.mxfreq, right.mxfreq);
	}
	return (tree){lf,rf,mf};
}

int main()
{
	while(1)
	{
		int n,q,i,x,y;
		inp(n);
		if(n==0)
		break ;
		inp(q);
		
		for(i=0;i<n;i++)
		inp(arr[i]);
		
		build(1,0,n-1);
		while(q--)
		{
			inp(x);
			inp(y);
			x--;
			y--;
			tree ans=query(1,0,n-1,x,y);
			printf("%d\n",ans.mxfreq);
		}
	}
	return 0;
}