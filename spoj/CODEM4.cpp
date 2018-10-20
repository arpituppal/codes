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

int arr[100],dp[100][100];

int dumb(int i,int j)
{
	if(i>j)
	return 0;
	
	if(dp[i][j]!=-1)
	return dp[i][j];
	
	int val1,val2;
	//player 1 chooses ith value player 2 chooses that value which gives player1 max value
	
	
	val1=arr[i]+MAX(dumb(i+2,j),dumb(i+1,j-1));
	val2=arr[j]+MAX(dumb(i+1,j-1),dumb(i,j-2));
	
	dp[i][j]=MAX(val1,val2);
	return dp[i][j];
}

int smart(int i,int j)
{
	if(i>j)
	return 0;
	
	if(dp[i][j]!=-1)
	return dp[i][j];
	
	int val1,val2;
	//player 1 chooses ith value player 2 chooses that value which gives player1 max value
	
	val1=arr[i]+MIN(smart(i+2,j),smart(i+1,j-1));
	val2=arr[j]+MIN(smart(i+1,j-1),smart(i,j-2));
	
	dp[i][j]=MAX(val1,val2);
	return dp[i][j];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j;
		int dans=0,sum=0,sans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];}
		
		memset(dp,-1,sizeof(dp));
		dans=dumb(0,n-1
		);
		
		memset(dp,-1,sizeof(dp));
		sans=smart(0,n-1);
		
		printf("%d %d\n",dans,sans);
	}
	return 0;
}