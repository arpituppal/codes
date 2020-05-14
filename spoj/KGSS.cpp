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
	int maxi,max2;
};
struct tree seg[400010];

int arr[100010];

void build(int node,int st,int end)
{
	if(st==end)
	{
		seg[node].maxi=arr[st];
		seg[node].max2=-1;
		return ;
	}
	int mid=(st+end)>>1;
	build(2*node,st,mid);
	build(2*node+1,mid+1,end);
	
	if(seg[2*node].maxi > seg[2*node+1].maxi)
	{
		seg[node].maxi=seg[2*node].maxi;
		seg[node].max2=MAX(seg[2*node+1].maxi,seg[2*node].max2);
	}
	else
	{
		seg[node].maxi=seg[2*node+1].maxi;
		seg[node].max2=MAX(seg[2*node].maxi,seg[2*node+1].max2);
	}
}

tree query(int node,int st,int end,int i,int j)
{
	if(i>end || j<st || st>end) return ((tree){-1,-1});
	if(i<=st && j>=end) return seg[node];
	
	int m,m2;
	int mid=(st+end)>>1;
	tree ans1=query(2*node,st,mid,i,j);
	tree ans2=query(2*node+1,mid+1,end,i,j);
	
	//printf("AA %d %d %d %d\n",ans1.maxi,ans1.max2,ans2.maxi,ans2.max2);
	if(ans1.maxi > ans2.maxi)
	{
		 m=ans1.maxi;
		 m2=MAX(ans1.max2,ans2.maxi);
	}
	else
	{
		m=ans2.maxi;
		m2=MAX(ans2.max2,ans1.maxi);
	}
	return( (tree){m,m2});
}

void update(int node,int st,int end,int idx,int val)
{
	//printf("St=%d end=%d\n",st,end);
	if(st==end)
	{
		if(st==idx)
		{seg[node].maxi=val; seg[node].max2=-1;arr[idx]=val;}
		return ;
	}
	
	int mid=(st+end)>>1;
	if(idx<=mid)
	update(2*node,st,mid,idx,val);
	else
	update(2*node+1,mid+1,end,idx,val);
	int m1,m2;
	
	
	if(seg[2*node].maxi>seg[2*node+1].maxi)
	{
		m1=seg[2*node].maxi;
		m2=MAX(seg[2*node].max2,seg[2*node+1].maxi);
	}
	else
	{
		m1=seg[2*node+1].maxi;
		m2=MAX(seg[2*node+1].max2,seg[2*node].maxi);
	}
	seg[node].maxi=m1;
	seg[node].max2=m2;
	
	//printf("node=%d maxi=%d max2=%d\n",node,seg[node].maxi,seg[node].max2);
}

int main()
{
	int n,q,i,idx,val,x,y;
	char ch;
	inp(n);
	for(i=0;i<n;i++)
	inp(arr[i]);
	
	build(1,0,n-1);
	
	inp(q);
	while(q--)
	{
		scanf(" %c",&ch);
		//char ch1=getchar();
		scanf("%d %d",&x,&y);
		//printf("%c\n",ch);
		x--;
		
		//printf("%c\n",ch);
		if(ch=='U')
			update(1,0,n-1,x,y);
		else
		{
			y--;
			tree ans=query(1,0,n-1,x,y);
			
			printf("%d\n",(ans.maxi+ans.max2));
		}
	}
	return 0;
}