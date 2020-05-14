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
long long int arr[100010];
int main()
{
	long long int n,m,low,high,mid;
	int i;
	inp(m);
	inp(n);
	for(i=0;i<n;i++)
	inp(arr[i]);
	sort(arr,arr+n);
	low=0;
	high=arr[n-1]-1;
	while(low!=high)
	{
		mid=(low+high+1)/2;
		long long int val=m;
		for(i=0;i<n;i++)
		{
			if(arr[i]>mid)
			val-=arr[i]-mid;
		}
		if(val>0)
		high=mid-1;
		else
		low=mid;
	}
	++low;
	for(i=n-1;i>=0;i--)
	{
		if(arr[i]>low)
		{
			m-=arr[i]-low;
			arr[i]-=arr[i]-low;
		}
	}
	--low;
	for(i=n-1;i>=0&& m>0;i--)
	{
		if(arr[i]>low)
		{
			--m;
			--arr[i];
		}
	}
	long long int ans=0;
	for(i=0;i<n;i++)
	ans+=(arr[i]*arr[i]);
	printf("%lld\n",ans);
	return 0;
}