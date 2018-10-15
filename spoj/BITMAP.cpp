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

queue<pair<int,int> >q;
int visited[200][200];
int main()
{
	char a[200][200];
	int t,ans[200][200];
	int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
	scanf("%d",&t);
	while(t--)
	{
		int n,m,i,j,x,y,d;
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		scanf("%s",a[i]);
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]=='1')
				{
					ans[i][j]=0;
					visited[i][j]=1;
					q.push(MP(i,j));
				}
			}
		}
		while(!q.empty())
		{
			 x=q.front().first;
			 y=q.front().second;
			 d=ans[x][y];
			 q.pop();
			 for(i=0;i<4;i++)
			 {
			 //	printf("x=%d y=%d\n",x,y);
			 	int x1=x+dx[i];
			 	int y1=y+dy[i];
			 //	printf("new: x=%d y=%d\n",x1,y1);
			 	if(x1>=0 && x1<n && y1>=0 && y1<m && !visited[x1][y1])
			 	{
			 //		printf("yes with d=%d\n",d);
			 		visited[x1][y1]=1;
			 		ans[x1][y1]=d+1;
			 		q.push(MP(x1,y1));
			 	}
			 }
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				visited[i][j]=0;
				printf("%d ",ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
			 	