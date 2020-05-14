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
	int lsum,rsum,sum,mxsum;
};
struct tree seg[200010];

int arr[50000];

void build(int node,int st,int end)
{
	if(st==end)
	{
		seg[node].lsum=arr[st];
		seg[node].rsum=arr[st];
		seg[node].sum=arr[st];
		seg[node].mxsum=arr[st];
		return ;
	}
	int mid=(st+end)>>1;
	build(2*node,st,mid);
	build(2*node+1,mid+1,end);
	
	seg[node].lsum=MAX(seg[2*node].lsum, (seg[2*node].sum +seg[2*node+1].lsum));
	seg[node].rsum=MAX(seg[2*node+1].rsum, (seg[2*node].rsum+seg[2*node+1].sum));
	seg[node].sum=seg[2*node].sum+seg[2*node+1].sum;
	
	seg[node].mxsum=MAX(seg[2*node].mxsum, MAX(seg[2*node+1].mxsum, seg[2*node].rsum+seg[2*node+1].lsum));
}	
	
tree query(int node,int st,int end,int i,int j)
{
	if(i>end || j<st || st>end) return ((tree){INT_MIN,INT_MIN,INT_MIN,INT_MIN});
	if(i<=st && j>=end) return seg[node];
	
	int mid=(st+end)>>1;
	tree left=query(2*node,st,mid,i,j);
	tree right=query(2*node+1,mid+1,end,i,j);
	
	int ls,rs,s,ms;
	
	if(left.lsum==INT_MIN)
	return right;
	
	if(right.lsum==INT_MIN)
	return left;
	
	ls=MAX(left.lsum,(left.sum+right.lsum));
	rs=MAX(right.rsum,(left.rsum+right.sum));
	s=left.sum+right.sum;
	
	ms=MAX(left.mxsum,MAX(right.mxsum, left.rsum+right.lsum));
	
	//printf("ls %d rs %d s %d ms %d\n",ls,rs,s,ms);
	return ((tree){ls,rs,s,ms});
}

int main()
{
	int n,i,j,m,x,y;
	inp(n);
	for(i=0;i<n;i++)
	inp(arr[i]);
	
	build(1,0,n-1);
	
	inp(m);
	while(m--)
	{	
		inp(x);
		inp(y);
		x--;
		y--;
		tree ans=query(1,0,n-1,x,y);
		printf("%d\n",ans.mxsum);
	}
	return 0;
}