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


char s[10000],arr[10000];


int main()
{
	int i,cnta=0,l,cntc=0,j=0;
	scanf("%s",s);
	l=strlen(s);
	
	arr[j++]=s[0];
	for(i=0;i<l;i++)
	{
		if(s[i]=='|')
		{
			arr[j++]=s[i+1];
			i++;
		}
	}
	for(i=0;i<j;i++)
	{
		if(arr[i]=='A' || arr[i]=='D' || arr[i]=='E')
		cnta++;
		if(arr[i]=='C' || arr[i]=='F' || arr[i]=='G')
		cntc++;
	}
	
	if(cnta>cntc)
	printf("A-mol\n");
	else if(cntc>cnta)
	printf("C-dur\n");
	else if(cnta==cntc)
	{
		if(s[l-1]=='A')
		printf("A-mol\n");
		else
		printf("C-dur\n");
	}
	return 0;
}