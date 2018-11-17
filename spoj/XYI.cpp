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

vector<int>vec[510];

int main()
{
	int t,x;
	inp(t);
	for(x=1;x<=t;x++)
	{
		
		int i,n,m,one=0,two=0,three=0,four=0,flag=0;
		inp(n);
		inp(m);
		for(i=1;i<=n;i++)
		vec[i].clear();
		while(m--)
		{
			int u,v;
			inp(u);
			inp(v);
			vec[u].PB(v);
			vec[v].PB(u);
		}
		for(i=1;i<=n;i++)
		{
			if(vec[i].size()==1)
			one++;
			else if(vec[i].size()==2)
			two++;
			else if(vec[i].size()==3)
			three++;
			else if(vec[i].size()==4)
			four++;
			else
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		printf("Case %d: NotValid\n",x);
		else
		{
			if(four==1 && one>=1 && three==0)
			printf("Case %d: X\n",x);
			else if(three==1 && one>=1 && four==0)
			printf("Case %d: Y\n",x);
			else if(one>=1 && three==0 && four==0)
			printf("Case %d: I\n",x);
			else
			printf("Case %d: NotValid\n",x);
		}
	}
	return 0;
}			