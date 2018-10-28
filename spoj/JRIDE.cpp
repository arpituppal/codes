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

int arr[100010];

int main()
{
	int t,x;
	inp(t);
	for(x=1;x<=t;x++)
	{
		int b,i,j,sum=0,mx=INT_MIN,maxst=1,maxend=1,currst=1,cnt=0;
		inp(b);
		b--;
		for(i=1;i<=b;i++)
		{
			inp(arr[i]);
			if(arr[i]<0)
			cnt++;
			//printf("ARR %d\n",arr[i]);
		}
		if(cnt==b)
		{printf("Route %d has no nice parts\n",x); continue;}

		for(i=1;i<=b;i++)
		{
			sum+=arr[i];
			if(sum>mx)
			{
				mx=sum;
				maxst=currst;
				maxend=i;
			}
			else if(sum==mx)
			{
				if((i-currst)>(maxend-maxst))
				{
					maxst=currst;
					maxend=i;
				}
				else if ((i-currst)==(maxend-maxst))
				{
					if(currst <maxst)
					{maxst=currst; maxend=i;}
				}
			}

			if(sum<0)
			{sum=0; currst=i+1;}
		}
		printf("The nicest part of route %d is between stops %d and %d\n",x,maxst,maxend+1);
	}
	return 0;
}
