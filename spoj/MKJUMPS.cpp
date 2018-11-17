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

int visited[11][11],n,m,ans=0,res=0;
vector<pair<int,int> >vec;

int dx[]={-2,-2,2,2,1,-1,1,-1};
int dy[]={-1,1,-1,1,-2,-2,2,2};

int valid(int x,int y)
{
	if(x>=0 && y>=0 && x<n && y<m && visited[x][y]==0)
	return 1;
	return 0;
}

void dfs(int x, int y,int cnt)
{
		int i;
		//visited[x][y]=1;

		//printf("x=%d y=%d\n",x,y);
		res=MAX(res,cnt);

		for(i=0;i<8;i++)
		{
			int newx=x+dx[i];
			int newy=y+dy[i];
			if(valid(newx,newy))
			{
				visited[newx][newy]=1;
				dfs(newx,newy,cnt+1);
				visited[newx][newy]=0;
			}
		}
	}


int main()
{
	int x=0;
	while(1)
	{
		int start,i,j,a,b;
		res=0;
		m=-1;
		ans=0;
		x++;

		inp(n);
		if(n==0)
		break;

		for(i=0;i<n;i++)
		{
			inp(a);
			inp(b);
			m=MAX(m,a+b);
			vec.PB(MP(a,b));
			ans+=b;
		}
		start=vec[0].first;

		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			visited[i][j]=0;
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<vec[i].first;j++)
			visited[i][j]=1;
			for(j=vec[i].second+vec[i].first;j<m;j++)
			visited[i][j]=1;

			//for(j=0;j<m;j++)
			//printf("%d ",visited[i][j]);
			//printf("\n");
		}
		//printf("%d\n",ans);


		visited[0][start]=1;
		dfs(0,start,1);
		ans=ans-res;
		if(ans==1)
		printf("Case %d, %d square can not be reached.\n",x,ans);
		else
		printf("Case %d, %d squares can not be reached.\n",x,ans);
		vec.clear();

	}
	return 0;
}
