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

map<string,int>mp;
double dist[50][50];

int main()
{
	int x=0;
	while(1)
	{
		int n,m,i,j,k,flag=0;
		double cost;
		string s,src,dest;
		x++;
		inp(n);
		if(n==0)
		break;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			dist[i][j]=0;
		}

		for(i=0;i<n;i++)
		{
			cin>>s;
			mp[s]=i;
		}
		cin>>m;
		for(i=0;i<m;i++)
		{
			cin>>src;
			cin>>cost;
			cin>>dest;
			dist[mp[src]][mp[dest]]=cost;
		}

		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				dist[i][j]=MAX(dist[i][j],dist[i][k]*dist[k][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			if(dist[i][i]>1)
			{flag=1; break;}
		}
		if(flag==1)
		printf("Case %d: Yes\n",x);
		else
		printf("Case %d: No\n",x);
		getchar();
	}
	return 0;
}
