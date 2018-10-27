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
char s[1010][1010];
int counti=0,last=0,trap[1010][1010],n,m;
void fill(int i, int j)
{
	if(i>=0 && j>=0 && i<n && j<m)
	{
		if(trap[i][j])
		{
			counti=trap[i][j];
			return ;
		}
		trap[i][j]=counti;
		if(s[i][j]=='W')
		fill(i,j-1);
		else if(s[i][j]=='E')
		fill(i,j+1);
		else if(s[i][j]=='N')
		fill(i-1,j);
		else if(s[i][j]=='S')
		fill(i+1,j);
		trap[i][j]=counti;
	}
}
int main()
{
	int i,j;
	inp(n);
	inp(m);
	for(i=0;i<n;i++)
	scanf("%s",s[i]);
	for(i=0;i<n;i++)
	{	
		for(j=0;j<m;j++)
		{
			if(!trap[i][j])
			{
				counti=last+1;
				fill(i,j);
				if(counti>last)
				last++;
			}
		}
	}
	printf("%d\n",last);
	return 0;
}