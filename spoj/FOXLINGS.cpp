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

map<int,int>mp;
set<int>s;
set<int>::iterator it;

int parent[200005];

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
	
	it=s.find(ans1);
	if(it!=s.end())
	s.erase(it);
	/*
	it=s.find(ans2);
	if(it!=s.end())
	s.erase(it);
	
	*/
	//s.erase(s.find(ans1));
	s.insert(ans2);
}
	
int main()
{
	int n,m,i,num=1,val1,val2,u,v,cnt=0,ans=0;
	inp(n);
	inp(m);
	
	while(m--)
	{
		inp(u);
		inp(v);
		if(u==v)
		continue;
		if(mp[u]==0)
		{
			val1=num; 
			parent[val1]=val1;
			cnt++;
			mp[u]=num++;
		}
		else
		val1=mp[u];
		
		if(mp[v]==0)
		{
			val2=num;
			parent[val2]=val2;
			mp[v]=num++;
			cnt++;
		}
		else
		val2=mp[v];
		
		if(find(val1)!=find(val2))
		uni(val1,val2);
	}
	ans=(n-cnt)+s.size();
	printf("%d\n",ans);
	return 0;
}