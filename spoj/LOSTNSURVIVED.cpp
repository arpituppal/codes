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

multiset<int>ms;
multiset<int>::iterator it;

int parent[100010],sz[100010];

int find(int u)
{	
	if(u==parent[u])
	return u;
	int root=find(parent[u]);
	parent[u]=root;
	return root;
}

void uni(int u,int v)
{
	int ans1=find(u);
	int ans2=find(v);
	parent[ans1]=ans2;
	
	sz[ans2]+=sz[ans1];
	ms.insert(sz[ans2]);
}
int main()
{
	int n,q,i,j,a,b,mini=1,maxi=1;
	inp(n);
	inp(q);
	for(i=1;i<=n;i++)
	{parent[i]=i; sz[i]=1; ms.insert(1);}
	
	while(q--)
	{	
		inp(a);
		inp(b);
		
		int ans1=find(a);
		int ans2=find(b);
		
		
		if(ans1==ans2)
		{printf("%d\n",maxi-mini); continue;}
		
		it=ms.find(sz[ans1]);
		ms.erase(it);
		it=ms.find(sz[ans2]);
		ms.erase(it);
		
		uni(ans1,ans2);
		
		 mini=*(ms.begin());
		multiset<int>::reverse_iterator rit=ms.rbegin();
		 maxi=*rit;
		printf("%d\n",(maxi-mini));
		
	}
	return 0;
}