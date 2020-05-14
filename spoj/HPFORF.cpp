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

char s[510][510];
int visited[510][510],comp[100000],mx=-1,n,m;

int safe(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<m)
	return 1;
	return 0;
}
	
int dfs(int x, int y, int c)
{
	int i,j,ans,ans1=0,ans2=0,ans3=0,ans4=0;
	if(visited[x][y]!=0)
	return 0;
	
	visited[x][y]=c;
	
	if(safe(x,y+1) )
	{
	  if( s[x][y+1]=='.' && !visited[x][y+1])
		ans1=dfs(x,y+1,c);
	 else if(s[x][y+1]=='*')
	  	ans1++;
	}
	
	if(safe(x,y-1) )
	{
		if( s[x][y-1]=='.' && !visited[x][y-1])
		ans2=dfs(x,y-1,c);
		else if(s[x][y-1]=='*')
		ans2++;
	}
	
	
	if(safe(x+1,y) )
	{
		if( s[x+1][y]=='.' && !visited[x+1][y])
		ans3=dfs(x+1,y,c);
		else if(s[x+1][y]=='*')
		ans3++;
	}
	
	if(safe(x-1,y) )
	{
		 if(s[x-1][y]=='.' && !visited[x-1][y])
   		 ans4=dfs(x-1,y,c);
		 else if(s[x-1][y]=='*')
		 ans4++;
	}
	ans=ans1+ans2+ans3+ans4;
	mx=MAX(ans,mx);
	return ans;
}
	
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{	
		int k,i,j,c=1,x,y;
		mx=-1;
		scanf("%d %d %d",&n,&m,&k);
		for(i=0;i<n;i++)
		scanf("%s",s[i]);
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(!visited[i][j] && s[i][j]=='.')
				{
					mx=-1;
					int ans=dfs(i,j,c);
					comp[c++]=mx;
					//printf("mx= %d\n",mx);
				}
			}
		}
		/*for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			printf("%d ",visited[i][j]);
			printf("\n");
		}*/
		while(k--)
		{
			scanf("%d %d",&x,&y);
			x--;
			y--;
			printf("%d\n",comp[visited[x][y]]);
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			visited[i][j]=0;
		}
		for(i=0;i<c;i++)
		comp[i]=0;
	}
	
	return 0;
}	
		