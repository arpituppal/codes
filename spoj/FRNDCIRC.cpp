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
#include <unordered_map>
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


int sz[100005],parent[100005];

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
	//printf("%d %d\n",sz[u],sz[v]);
	parent[u]=v;
	sz[v]+=sz[u];
}

int main()
{	
	int t;
	inp(t);
	while(t--)
	{
		unordered_map<string,int> mp;
//		std::unordered_map<string,int>mp;
		int n,i,k=1,val1,val2;
		inp(n);
		while(n--)
		{
		string s,s1;
		cin>>s>>s1;
	
		if(mp[s]==0)
		{
			mp[s]=k;
			val1=k;
			parent[k]=k;
			sz[k]=1;
			k++;
		}
		else
		val1=mp[s];
		
		if(mp[s1]==0)
		{
			mp[s1]=k;
			val2=k;
			parent[k]=k;
			sz[k]=1;
			k++;
		}
		else
		val2=mp[s1];
		
		int l1=find(val1);
		int l2=find(val2);
		//printf("%d %d\n",l1,l2);
		if(l1==l2)
		printf("%d\n",sz[l1]);
		else
		{
			uni(l1,l2);
			printf("%d\n",sz[l2]);
		}
	}
		for(i=0;i<k;i++)
		sz[i]=1;
	}
	return 0;
}	
		
	