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
inline void inp( long long int &n )
{
n=0; long long int ch=getcx();long long int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
} 
long long int power[64];
long long result(long long int x)
{
	long long int ans=0,i=0;
	while(x)
	{
		if(x%2==1)
		ans+=power[i];
		x=x/2;
		i++;
	}
	return ans;
}
int main()
{
	int i;
	long long int sum=1,pow=1,a,b,powsum=0;
	power[0]=1;
	sum=4;
	for(i=1;i<63;i++)
		power[i]=power[i-1]*2;
	
	power[1]=3;
	for(i=2;i<63;i++)
	{
		power[i]+=sum;
		sum+=power[i];
	}
	//for(i=0;i<63;i++)
	//printf("%lld\n",power[i]);
	inp(a);
	inp(b);
	printf("%lld\n",(result(b)-result(a-1)));
	return 0;
}