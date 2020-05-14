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
#define MOD 1000000007
inline void inp( int &n )
{
n=0; int ch=getcx();int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
} 
unsigned long long int hash[10];
char s[10010];
int main()
{
	int t,x;
	inp(t);
	for(x=1;x<=t;x++)
	{
		int i,l,j;
		unsigned long long int ans=0;
		scanf("%s",s);
		l=strlen(s);
		hash[s[0]-48]=1;
		
		for(i=1;i<l;i++)
		{
			ans=0;
			for(j=0;j<(s[i]-48);j++)
			ans=(ans%MOD+hash[j]%MOD)%MOD;
			hash[s[i]-48]=((hash[s[i]-48]%MOD+ans%MOD)%MOD+1)%MOD;
			//arr[i]=ans+1;
		}
		ans=0;
		for(i=0;i<10;i++)
		ans=(ans%MOD+hash[i]%MOD)%MOD;
		printf("Case %d: %llu\n",x,ans);
		for(i=0;i<10;i++)
		hash[i]=0;
	}
	return 0;
}