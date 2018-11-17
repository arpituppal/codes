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


vector<int>vec[1000];
set<int>s;
int indeg[1000];

int main()
{
	int n,m,i,u,v,k;
	inp(n);
	inp(m);
	for(i=0;i<m;i++)
	{
		inp(u);
		inp(k);
		
		indeg[u]+=k;
		while(k--)
		{
			inp(v);
			vec[v].PB(u);
		}
	}
	
	for(i=1;i<=n;i++)
	{
		if(indeg[i]==0)
		s.insert(i);
	}
	
	while(!s.empty())
	{
		int idx=*(s.begin());
		s.erase(s.begin());
		printf("%d ",idx);
		
		for(i=0;i<vec[idx].size();i++)
		{
			indeg[vec[idx][i]]--;
			if(indeg[vec[idx][i]]==0)
			s.insert(vec[idx][i]);
		}
	}
	printf("\n");
	return 0;
}