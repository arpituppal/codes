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

map<LL,LL>mp;
char s[100];
int main()
{
	int n,i,homo=0,hetero=0,sz=0;
	LL num;
	inp(n);
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		inp1(num);
		//printf("str %s\n",s);
		if(s[0]=='i')
		{
			if(mp[num]==0)
			sz++;
			mp[num]++;

			if(mp[num]>1)
			homo++;
			if(sz>1)
			hetero++;

			//printf("size=%d\n",mp.size());
		}
		else if(s[0]=='d')
		{
			if(mp[num]!=0){

			mp[num]--;

			if(mp[num]==0)
			sz--;
			else if (mp[num]==1)
			homo--;

			//
			if(sz<=1)
			hetero=0;

			//printf("size=%d\n",mp.size());
			}
			//
			//printf("homo hetero %d %d\n",homo,hetero);
		}

		if(homo==0 && hetero==0)
		printf("neither\n");

		if(homo>=1 && hetero>=1)
		printf("both\n");

		if(homo>=1 && hetero==0)
		printf("homo\n");

		if(homo==0 && hetero>=1)
		printf("hetero\n");
	}
	return 0;
}
