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
#define MOD 1000000007

char s[150][150];
int visited[150][150],dist[150][150],m,n,sx,sy,ex,ey;
queue<pair<int,int> >q;

int valid(int x, int y)
{
	if(x>=0 && x<m && y>=0 && y<n)
	return 1;
	return 0;
}

void bfs(int sx,int sy)
{
	visited[sx][sy]=1;
	dist[sx][sy]=0;
	q.push(MP(sx,sy));
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		if(x==ex && y==ey)
		return ;
		if(valid(x+1,y)==1 && !visited[x+1][y] && s[x+1][y]!='*')
		{
			q.push(MP(x+1,y));
			visited[x+1][y]=1;
			dist[x+1][y]=dist[x][y]+1;
		}
		if(valid(x-1,y)==1 && !visited[x-1][y] && s[x-1][y]!='*')
		{
			q.push(MP(x-1,y));
			visited[x-1][y]=1;
			dist[x-1][y]=dist[x][y]+1;
		}
		if(valid(x,y+1)==1 && !visited[x][y+1] && s[x][y+1]!='*')
		{
			q.push(MP(x,y+1));
			visited[x][y+1]=1;
			dist[x][y+1]=dist[x][y]+1;
		}
		if(valid(x,y-1)==1 && !visited[x][y-1] && s[x][y-1]!='*')
		{
			q.push(MP(x,y-1));
			visited[x][y-1]=1;
			dist[x][y-1]=dist[x][y]+1;
		}
	}
}
int main()
{
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int i,j;
            scanf("%d %d",&m,&n);
            for(i=0;i<m;i++)
            {
                  scanf("%s",s[i]);
                  for(j=0;j<n;j++)
                  {
                  	//printf("%c\n",s[i][j]); 
                        if(s[i][j]=='$')
                        {sx=i; sy=j;}
                        if(s[i][j]=='#')
                        {ex=i; ey=j;}
                  }
           }
           //cout<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<endl;
           bfs(sx,sy);
           if(dist[ex][ey]==0)
           printf("-1\n");
           else
           printf("%d\n",dist[ex][ey]);
           
           for(i=0;i<m;i++)
           {
           		for(j=0;j<n;j++)
           		{
           			visited[i][j]=0;
           			dist[i][j]=0;
           		}
           }
           while(!q.empty())
           q.pop();
     }
     return 0;
}		
