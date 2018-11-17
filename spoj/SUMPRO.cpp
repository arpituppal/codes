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
#define mod 1000000007
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
LL x[1000000],y[1000000];
long long int power(long long int b,long long int e,long long ans)
{
	if(!e)return ans;
	if(e&1) ans=(ans*b)%mod;
	return power((b*b)%mod,e>>1,ans);
}
int main()
{
	LL t;
	LL inv=power(2,mod-2,1);
	inp1(t);
	while(t--)
	{
		long long int n,ans=0,sum=0;
		LL i=0,j=0;
		inp1(n);
		for(i=1;i*i<=n;i++)
		{
			x[j]=i;
			y[j]=n/i;
			ans=(ans+(x[j]*y[j]))%mod;
			j++;
			
		}
		LL k=j-1;
		for(i=k;i>=0;i--)
		{
			if(x[i]==y[i])
			continue;
			x[j]=y[i];
			y[j]=x[i];
			j++;
			
		}
		//for(i=0;i<k;i++)
		//printf("%d %d\n",x[i],y[i]);
		
		//for(i=0;i<j;i++)
		//printf("%d %d \n",x[i],y[i]);
		
		//ans=(x[0]*y[0])%mod;
		
		for(i=k;i<j-1;i++)
		{
			sum=(((x[i+1]-x[i]))*((x[i]+1+x[i+1])))%mod;
			sum=(sum*inv)%mod;
			sum=(sum*y[i+1])%mod;
			ans=(ans+sum)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
		
		
		
		