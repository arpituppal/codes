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

int row,col,flag=0;

int valid(int x,int y)
{
	if(x>=0 && x<row && y>=0 && y<col)
	return 1;
	return 0;
}

void dfs(int i,int j,int visited[26][26],int cnt,int r[],int c[])
{
	r[cnt-1]=i;
	c[cnt-1]=j;
	if(cnt==row*col)	//all squares visited
	{
		//cout<<"YES\n";
		flag=1;
		int k;
		for(k=0;k<row*col;k++)
		printf("%c%d",'A'+r[k],1+c[k]);
		printf("\n");
		return ;
	}
	if(flag==0 && valid(i-2,j-1) && !visited[i-2][j-1])
	{
		visited[i-2][j-1]=1;
		dfs(i-2,j-1,visited,cnt+1,r,c);
		visited[i-2][j-1]=0;
	}
	if(flag==0 && valid(i-2,j+1) && !visited[i-2][j+1])
	{
		visited[i-2][j+1]=1;
		dfs(i-2,j+1,visited,cnt+1,r,c);
		visited[i-2][j+1]=0;
	}
	if(flag==0 && valid(i-1,j-2) && !visited[i-1][j-2])
	{
		visited[i-1][j-2]=1;
		dfs(i-1,j-2,visited,cnt+1,r,c);
		visited[i-1][j-2]=0;
	}
	if(flag==0 && valid(i-1,j+2) && !visited[i-1][j+2])
	{
		visited[i-1][j+2]=1;
		dfs(i-1,j+2,visited,cnt+1,r,c);
		visited[i-1][j+2]=0;

	}
	if(flag==0 && valid(i+1,j-2) && !visited[i+1][j-2])
	{
		visited[i+1][j-2]=1;
		dfs(i+1,j-2,visited,cnt+1,r,c);
		visited[i+1][j-2]=0;
	}

	if(flag==0 && valid(i+1,j+2) && !visited[i+1][j+2])
	{
		visited[i+1][j+2]=1;
		dfs(i+1,j+2,visited,cnt+1,r,c);
		visited[i+1][j+2]=0;
	}
	if(flag==0 && valid(i+2,j-1) && !visited[i+2][j-1])
	{
		visited[i+2][j-1]=1;
		dfs(i+2,j-1,visited,cnt+1,r,c);
		visited[i+2][j-1]=0;
	}
	if(flag==0 && valid(i+2,j+1) && !visited[i+2][j+1])
	{
		visited[i+2][j+1]=1;
		dfs(i+2,j+1,visited,cnt+1,r,c);
		visited[i+2][j+1]=0;
	}

}


int solve(int r[],int c[])
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			int visited[26][26]={0};
			visited[i][j]=1;
			flag=0;
			dfs(i,j,visited,1,r,c);		//cell i,j cnt=no of squares visited; r,c- to store coordinates

			if(flag==1)
			return 1;
			//cout<<"IN\n";
		}
	}
	return 0;
}
int main()
{
	int tc;
	inp(tc);

	while(tc--)
	{
		//cout<<"before t "<<tc<<endl;
		int i,c[30],r[30];
		inp(col);
		inp(row);
		//cout<<"t "<<tc<<endl;
		int ans=solve(r,c);
		if(ans==0)
		printf("-1\n");

	}
	return 0;
}
