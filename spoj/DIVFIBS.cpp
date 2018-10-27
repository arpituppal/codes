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
typedef unsigned long long ULL;
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

int main() 
{
	int t;
	inp(t);
	while(t--)
	 {
		ULL l,r,m,a=0,b=1,c=1;
		scanf("%llu %llu %llu",&l,&r,&m);
	
		int cnt=0,i;
		if(c%m==0 && l==1) 
		cnt++;
		
		if(l==1)
		 l++;
		for(i= 2;i<l;i++)
		 {
			if(c>m) 
			c-= m;
			
			a=b;
			b=c;
			c=a+b;
		}
		
		for(i=l;i<=r;i++) 
		{
			if(c>m) 
			c-=m;
			
			a=b;
			b=c;
			if(c%m==0)
			cnt++;
			
			c=a+b;
		}
		printf("%d\n",cnt);
		
	}	
	return 0;
}