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
int a[1005][1005],netout[1010];
int main()
{
	int n,x=0;
	while(1)
	{
		x++;
		int i,j,outsum=0,sum=0,insum=0,newsum=0;
		inp(n);
		if(n==0)
		break;
		for(i=0;i<n;i++)
		 {
		 	outsum=0;
		      for(j=0;j<n;j++)
		    	{
		    	     inp(a[i][j]);
			     outsum+=a[i][j];
			}
			netout[i]=outsum;
			sum+=outsum;
		}
		for(i=0;i<n;i++)
		{
			insum=0;
			for(j=0;j<n;j++)
			    insum+=a[j][i];
		      if(netout[i]>=insum)
		         netout[i]=netout[i]-insum;
		         else
		         netout[i]=0;
	     }
	     
	     for(i=0;i<n;i++)
	     newsum+=netout[i];
	     printf("%d. %d %d\n",x,sum,newsum);
	}
	return 0;
}