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
 
int sieve[100000];
int visited[100000];
int bfs(int start, int finish)
{
	queue<pair<int,int> >q;
	int ans=0,i,j=1,k,num;
	for(i=0;i<10000;i++)
	visited[i]=0;
	if(start==finish)
	return ans;
	q.push(MP(start,ans));
	visited[start]=1;
	while(!q.empty())
	{
		int n=q.front().first;
		j=1;
		ans=q.front().second;
		q.pop();
		int a[]={n/1000,(n/100)%10,(n/10)%10,n%10};
		for(i=0;i<4;i++)
		{
			for(;j<10;j++)
			{
				if(j==a[i])
				continue;
				int res=0;
				for(k=0;k<4;k++)
				{
					if(k==i)
					num=j;
					else
					num=a[k];
					res=(res*10)+num;
				}
				if(sieve[res]==0 && !visited[res])
				{
					if(res==finish)
					return ans+1;
					q.push(MP(res,ans+1));
					visited[res]=1;
				}
			}
			j=0;
		}
	}		
}

int main()
{
	int i,j,t,n,m;
	for(i=2;i*i<=10000;i++)
	{
		if(!sieve[i])
		{
			for(j=i*i;j<=10000;j+=i)
			sieve[j]=1;
		}
	}
	inp(t);
	while(t--)
	{
		inp(n);
		inp(m);
		printf("%d\n",bfs(n,m));
	}
	return 0;
}