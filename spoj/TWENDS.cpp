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

int arr[1010],dp[1010][1010];

int solve(int i, int j)
{
	if(i>j)
	return 0;
	
	if(dp[i][j]!=-1)
	return dp[i][j];
	
	int val1,val2;
	if(arr[i+1]>=arr[j]) //player 1 took ith card now player 2 will go greedy so depending on his choice we will be left an array for player 1
	val1=arr[i]+solve(i+2,j);
	else
	val1=arr[i]+solve(i+1,j-1);
	
	//case 2- player 1 took jth card so now same thign as above
	if(arr[i]>=arr[j-1])
	val2=arr[j]+solve(i+1,j-1);
	else
	val2=arr[j]+solve(i,j-2);
	
	dp[i][j]= MAX(val1,val2); 
	return dp[i][j];
}
int main()
{
	int n,i,j,sum=0,ans,x=0;
	while(1)
	{
		inp(n);
		if(n==0)
		break;
		x++;
		sum=0;
		for(i=0;i<n;i++)
		{
			inp(arr[i]);
			sum+=arr[i];
		}
		memset(dp,-1,sizeof(dp));
		ans=solve(0,n-1);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",x,(2*ans-sum));
	}
	return 0;
}