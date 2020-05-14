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

int arr[1005][1005],visited[1005][1005],n,m;
vector<pair<int,int> > vec;
int dx[]={-2,-2,2,2,1,-1,1,-1};
int dy[]={-1,1,-1,1,-2,-2,2,2};

int valid(int x,int y)
{
	if(x>=0 && y>=0 && x<n && y<m)
	return 1;
	return 0;
}
int main()
{
	int t=0;
	while(1)
	{
		int k,r,c,i,j,ans,x,y,l;
		t++;
		inp(n);
		inp(m);
		if(n==0 && m==0)
		break;

		ans=n*m;

		inp(k);
		for(i=1;i<=k;i++)
		{
			cin>>r>>c;
			r--;
			c--;
			arr[r][c]=2; //2 or queen
			vec.PB(MP(r,c));
			ans--;
		}
		inp(k);
		for(i=1;i<=k;i++)
		{
			cin>>r>>c;
			r--;
			c--;
			arr[r][c]=1; //1 for knight
			vec.PB(MP(r,c));
			ans--;
		}
		inp(k);
		for(i=1;i<=k;i++)
		{
			cin>>r>>c;
			r--;
			c--;
			arr[r][c]=3;
			vec.PB(MP(r,c));
			ans--;
		}
		//printf("ans %d\n",ans);
		for(l=0;l<vec.size();l++)
		{
			r=vec[l].first;
			c=vec[l].second;
			if(arr[r][c]==1)	//knight
			{
				for(j=0;j<8;j++)
				{
					int newx=r+dx[j];
					int newy=c+dy[j];
					if(valid(newx,newy) && arr[newx][newy]!=1 && arr[newx][newy]!=2 && arr[newx][newy]!=3 && !visited[newx][newy])
					{visited[newx][newy]=1; ans--;}
				}
				//printf("ans=%d\n",ans);
			}
			else if(arr[r][c]==2)	//queen
			{
				//printf("r=%d c=%d\n",r,c);
				for(i=r-1;i>=0;i--)	//up
				{
					if(arr[i][c]==1 || arr[i][c]==2 || arr[i][c]==3)
					break;
					if(arr[i][c]!=1 && arr[i][c]!=2 && arr[i][c]!=3 && !visited[i][c])
					{visited[i][c]=1; ans--;}
				}
				for(i=r+1;i<n;i++)	//down
				{
					if(arr[i][c]==1 || arr[i][c]==2 || arr[i][c]==3)
					break;
					if(arr[i][c]!=1 && arr[i][c]!=2 && arr[i][c]!=3 && !visited[i][c])
					{visited[i][c]=1; ans--;}
				}

				for(i=c-1;i>=0;i--)	//left
				{
					if(arr[r][i]==1 || arr[r][i]==2 || arr[r][i]==3)
					break;

					if(arr[r][i]!=1 && arr[r][i]!=2 && arr[r][i]!=3 && !visited[r][i])
					{visited[r][i]=1; ans--;}
				}

				for(i=c+1;i<m;i++)	//right
				{
					if(arr[r][i]==1 || arr[r][i]==2 || arr[r][i]==3)
					break;

					if(arr[r][i]!=1 && arr[r][i]!=2 && arr[r][i]!=3 && !visited[r][i])
					{visited[r][i]=1; ans--;}
				}

			//	printf("%d\n",ans);
				for(i=r+1,j=c+1;i<n&&j<m;i++,j++)	//right lower
				{
					if(arr[i][j]==1 || arr[i][j]==2 || arr[i][j]==3)
					break;
					if(arr[i][j]!=1 && arr[i][j]!=2 && arr[i][j]!=3 && !visited[i][j])
					{visited[i][j]=1;ans--;}
				}

				for(i=r-1,j=c-1;i>=0 && j>=0;i--,j--)	//left upper
				{
					if(arr[i][j]==1 || arr[i][j]==2 || arr[i][j]==3)
					break;

					if(arr[i][j]!=1 && arr[i][j]!=2 && arr[i][j]!=3 && !visited[i][j])
					{visited[i][j]=1;ans--;}
				}
				for(i=r-1,j=c+1; i>=0&&j<m; i--,j++)//right upper
				{
					if(arr[i][j]==1 || arr[i][j]==2 || arr[i][j]==3)
					break;
					if(arr[i][j]!=1 && arr[i][j]!=2 && arr[i][j]!=3 && !visited[i][j])
					{visited[i][j]=1; ans--;}
				}
				//printf("r=%d c=%d\n",r,c);
				for(i=r+1,j=c-1; i<n&&j>=0; i++,j--)	//left lower
				{
					//printf("r=%d c=%d\n",i,j);
					if(arr[i][j]==1 || arr[i][j]==2 || arr[i][j]==3)
					break;
					//printf("%d\n",ans);
					if(arr[i][j]!=1 && arr[i][j]!=2 && arr[i][j]!=3 && !visited[i][j])
					{visited[i][j]=1; ans--;}
				}
				//printf("ans=%d\n",ans);
			}
		}
		printf("Board %d has %d safe squares.\n",t,ans);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{arr[i][j]=0;visited[i][j]=0;}
		}
		vec.clear();
	}
	return 0;
}
