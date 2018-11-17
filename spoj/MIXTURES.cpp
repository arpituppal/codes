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

int dp[110][110],sum[110][110],color[110];

int solve(int i, int j)
{
	int k;
	//printf("pp %d\n",dp[i][j]);
	if(dp[i][j]!=-1)
	return dp[i][j];
	
	if(i==j)
	return 0;
	
	dp[i][j]=INF;
	//printf("dpdpd %d\n",dp[i][j]);
	for(k=i;k<j;k++)
	{
		//printf("yes %d %d \n",sum[i][k],sum[k+1][j]);
		int val=solve(i,k)+solve(k+1,j)+sum[i][k]*sum[k+1][j];
		if(val<dp[i][j])
		dp[i][j]=val;
	}
	return dp[i][j];
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		//printf("%d\n",n);
		int i,j;
		memset(dp,-1,sizeof(dp));
		//memset(sum,0,sizeof(sum));
		//scanf("%d",&n);
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&color[i]);
			sum[i][i]=color[i];
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			sum[i][j]=(sum[i][j-1]+color[j])%100;
		}
		//int ans=0;		
		//printf("dd %d\n",dp[0][0]);
		int ans=solve(0,n-1);
		printf("%d\n",ans);
	}
	return 0;
}				