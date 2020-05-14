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
inline void inp( LL &n )
{
n=0; LL ch=getcx();LL sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
} 
long long int minval(long long int a,long long int b,long long int c)
{
	if(a<=b && a<=c)
	return a;
	if(b<=a && b<=c)
	return b;
	if(c<=a && c<=b)
	return c;
}
int main()
{
	long long int arr[1010][3],n;;
	while(1)
	{
		int i,j;
		long long int mini=100000,mi,vol,ans=0;
		inp(n);
		if(n==0)
		break;
		for(i=0;i<n;i++)
		{
			inp(arr[i][0]);
			inp(arr[i][1]);
			inp(arr[i][2]);
			mi=minval(arr[i][0],arr[i][1],arr[i][2]);
			if(mi<mini && mi>0)
			mini=mi;
		}
		vol=(mini*mini*mini);
		//printf("vol=%lld\n",vol);
		for(i=0;i<n;i++)
		ans+=((arr[i][0]*arr[i][1]*arr[i][2])/vol);
		printf("%lld\n",ans);
	}
	return 0;
}