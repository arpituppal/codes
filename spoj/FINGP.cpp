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

char s[110],s1[110];
vector<string>vec;

int main()
{
	int i,j,k,l,l1,n,flag;
	gets(s);
	l=strlen(s);
	inp(n);
	for(i=0;i<n;i++)
	{
		k=l-1;
		flag=0;
		gets(s1);
		l1=strlen(s1);
		if(l>l1)
		continue;
		j=l1-1;
		while(k>=0 && j>=0)
		{
			if(s[k]!=s1[j])
			{flag=1; break;}
			k--;
			j--;
		}
		if(flag==0)
		{string str=s1; vec.PB(str);}
	}
	if(vec.size()==0)
	printf("Wrong fingerprints!\n");
	else
	{
		printf("%d\n",vec.size());
		sort(vec.begin(),vec.end());
		for(i=0;i<vec.size();i++)
		cout<<vec[i]<<endl;
	}
	return 0;
}

