/*
ARPIT UPPAL
MNNIT ALLAHABAD
*/
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

LL bit[1000000];
char s[100];
int n;
void update(int idx, LL val)
{
	while(idx<=n)
	{	
		bit[idx]+=val;
		idx+=(idx & -idx);
		
	}
}
LL query(int idx)
{
	LL sum=0;
	while(idx>0)
	{
		sum+=bit[idx];
		idx-=(idx & -idx);
	}
	return sum;
}
int main()
{
	int t,x;
	inp(t);
	for(x=1;x<=t;x++)
	{
		printf("Case #%d\n",x);
		memset(bit,0,sizeof(bit));
		int q,u,v;
		LL c,k;
		inp(n);
		inp(q);
		inp1(c);
		while(q--)
		{
			scanf("%s",s);
			int l=strlen(s);
			if(s[0]=='a') //add or addin 
			{
				if(l==3) //add
				{
					inp(u);
					inp(v);
					inp1(k);
					update(u,k);
					update(v+1,-1*k);
				}	
				else if(l==5) //addin
				{
					inp(u);
					inp1(k);
					update(u,k);
					update(u+1,-1*k);
				}
			}
			if(s[0]=='m') //minus or minuin
			{
				if(l==5) //minus
				{
					inp(u);
					inp(v);
					inp1(k);
					k=-1*k;
					update(u,k);
					//printf("====%lld\n",-1*k);
					update(v+1,-1*k);
				}
				else if(l==7)
				{
					inp(u);
					inp1(k);
					k=-1*k;
					update(u,k);
					update(u+1,-1*k);
				}
			}
			if(s[0]=='r')   //reset
			{
				inp(u);
				inp1(k);
				LL val=query(u);
				val+=c;
				//printf("%lld\n",val);
				LL val1=k-val;
				
				update(u,val1);
				update(u+1,-1*val1);
			}
			if(s[0]=='f')
			{
				inp(u);
				LL ans=query(u);
				//LL ans1=0;
				//LL ans1=query(u-1);
				printf("%lld\n",ans+c);
			}
		}
		char ch=getchar();
	}
	return 0;
}
