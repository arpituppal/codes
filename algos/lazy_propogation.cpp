				/*Range update in segment tree
				Lazy propogation */
			
			
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

int seg[400005],flag[400005],arr[100005];

void build(int node,int st,int end)
{
	if(st==end)
	{
		seg[node]=0;
		flag[node]=0; //false
		return ;
	}
	int mid=(st+end)>>1;
	build(2*node,st,mid);
	build(1*node+1,mid+1,end);
	seg[node]=0; 	//initially all switches are off
	flag[node]=0;
}

void flag_resolve(int node,int st,int end)
{
	if(flag[node]==1)	//pending update
	{
		flag[node]=0;		//update done
		seg[node]=(end-st+1)-seg[node];	//on switches become off , off become on now push this in children
		
		if(st!=end)
		{
			flag[2*node]=!flag[2*node];
			flag[2*node+1]=!flag[2*node+1];
		}
	}
}


void update(int node,int st,int end,int i,int j)
{
	if(i>end || j<st || st>end)
	{
		flag_resolve(node,st,end);
		return ;
	}
	if(i<=st && j>=end)
	{
		flag[node]=!flag[node];
		flag_resolve(node,st,end);
		return ;
	}
	
	flag_resolve(node,st,end);
	int mid=(st+end)>>1;
	update(2*node,st,mid,i,j);
	update(2*node+1,mid+1,end,i,j);
	
	if(st!=end)
	seg[node]=seg[2*node]+seg[2*node+1];
}

int query(int node,int st,int end,int i,int j)
{
	if(st>end || i>end || j<st)  
	return 0;
	
	flag_resolve(node,st,end); // resolve the flag coz this node will be answer or this plus some child value will contain
	
	if(i<=st && j>=end)
	return seg[node];
	
	int mid=(st+end)>>1;
	return (query(2*node,st,mid,i,j) + query(2*node+1,mid+1,end,i,j));
}
	
int main()
{
	int n,m,i,j,k,l,r;
	inp(n);
	inp(m);
	
	build(1,0,n-1);
	while(m--)
	{
		inp(k);
		inp(l);
		inp(r);
		l--;
		r--;
		if(k==0)
		update(1,0,n-1,l,r);
		else
		printf("%d\n",query(1,0,n-1,l,r));
	}
	return 0;
}