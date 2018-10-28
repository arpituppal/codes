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

char s[210][210];
int dp[210][210],n,m,mx=-1;

int valid(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<m && s[x][y]!='#')
	return 1;
	return 0;
}

int dfs(int x,int y,char ch)
{
	int ans1=0,ans2=0;
	
	//printf("=%d y=%d %c\n",x,y,s[x][y]);
	if(dp[x][y]!=-1)
	return dp[x][y];
	
	
	
	if(ch=='R')
	{
		if(valid(x,y+1))
		ans1=dfs(x,y+1,'R');
		
		
		if(valid(x+1,y))
		ans2=dfs(x+1,y,'L');
		
		
		int ans=MAX(ans1,ans2);
		
		if(s[x][y]=='T')
		dp[x][y]=ans+1;
		else
		dp[x][y]=ans;
		mx=MAX(mx,dp[x][y]);
		return dp[x][y];
	}
	if(ch=='L')
	{
		if(valid(x,y-1))
		ans1=dfs(x,y-1,'L');
		
		if(valid(x+1,y))
		ans2=dfs(x+1,y,'R');
		
		
		int ans=MAX(ans1,ans2);
		
		if(s[x][y]=='T')
		dp[x][y]=ans+1;
		else
		dp[x][y]=ans;
		
		mx=MAX(mx,dp[x][y]);
		return dp[x][y];
	}
}	
	
int main()
{	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j;
		mx=-1;
		
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		scanf("%s",s[i]);
		
		memset(dp,-1,sizeof(dp));
		
		if(s[0][0]=='#')
		{printf("0\n");continue;}
		
		int ans=dfs(0,0,'R');
		printf("%d\n",mx);
	}
	return 0;
}