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

LL a[100005],b[100005];

int main()
{
	int t;
	inp(t);
	while(t--)
	{
		int n,i,j,flag=0;
		LL val;
		
		inp(n);
		for(i=0;i<n;i++)
		inp1(a[i]);
		
		for(i=0;i<n;i++)
		inp1(b[i]);
		
		val=MIN(a[0],b[0]);
		
		for(i=1;i<n;i++)
		{
			if(flag==1)
			break;
			
			if(a[i]<b[i]) //check whether minimum is greater than val
			{
				if(a[i]>=val)
				val=a[i];
				
				else if(b[i]>=val)	//if not check other value
				val=b[i];
				else	
				flag=1;
			}
			else
			{
				if(b[i]>=val)
				val=b[i];
				else if(a[i]>=val)
				val=a[i];
				else
				flag=1;
			}
		}
		
		if(flag==0)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}