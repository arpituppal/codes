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

int arr[300][300],visited[300][300],hash[1000000],counti=0,n,m;
int issafe(int x,int y)
{
	if(x>=0 && y>=0 && x<n && y<m)
	return 1;
	return 0;
}
void solve(int x,int y)
{
	//printf("yes\n");
	visited[x][y]=1;
	counti++;
	if(issafe(x,y-1))
	{
		if(arr[x][y-1]==1 && !visited[x][y-1])
		solve(x,y-1);
	}
	if(issafe(x,y+1))
	{
		if(arr[x][y+1]==1 && !visited[x][y+1])
		solve(x,y+1);
	}
	if(issafe(x-1,y))
	{
		if(arr[x-1][y]==1 && !visited[x-1][y])
		solve(x-1,y);
	}
	if(issafe(x+1,y))
	{
		if(arr[x+1][y]==1 && !visited[x+1][y])
		solve(x+1,y);
	}
}
	
int main()
{
	int i,j;
	while(1)
	{	
		int maxi=-1,ans=0;
		inp(n);
		inp(m);
		if(n==0 && m==0)
		break;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			inp(arr[i][j]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			visited[i][j]=0;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(arr[i][j]==1 && !visited[i][j])
				{
					counti=0;
					ans++;
					solve(i,j);
					hash[counti]++;
					maxi=MAX(maxi,counti);
				}
			}
		}
		printf("%d\n",ans);
		for(i=0;i<=maxi;i++)
		{
			if(hash[i]>0)
			printf("%d %d\n",i,hash[i]);
			hash[i]=0;
		}
	}
	return 0;
}