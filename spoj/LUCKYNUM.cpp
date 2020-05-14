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

 //1st stores mod 2nd's 1st stores no of 8 and 2nd's 2nd stores no of 6
int visited[10010][2],mx=-1,flag=0;
void bfs(int x)
{

      queue<pair<int,pair<int,int> > >q;
	int i;
	//printf("%d\n",q.front().first);
	q.push(MP(6%x,MP(0,1)));
	visited[6%x][0]=1;
	q.push(MP(8%x,MP(1,0)));
	visited[8%x][1]=1;
	while(!q.empty())
	{
		int val=q.front().first;
		int eight=q.front().second.first;
		int six=q.front().second.second;
		q.pop();
		if(eight+six>200)
		return ;
		if(val>=mx)
		mx=val;
		//printf("val=%d eight=%d six=%d\n",val,eight,six);
		if(val==0)
		{
			flag=1;
			for(i=1;i<=eight;i++)
			printf("8");
			for(i=1;i<=six;i++)
			printf("6");
			printf("\n");
			return ;
		}
		int rem6=(val*10+6)%x;
		int rem8=(val*10+8)%x;
		//printf("rem6=%d rem8=%d\n",rem6,rem8);
		if(visited[val][0]==1) //the val came by adding 6 as last digit
		{
			if(!visited[rem6][0])
			{
				q.push(MP(rem6,MP(eight,six+1)));
				visited[rem6][0]=1;
			}
		}
		if(visited[val][1]==1)
		{
			if(!visited[rem6][0])
			{
				q.push(MP(rem6,MP(eight,six+1)));
				visited[rem6][0]=1;
			}
			if(!visited[rem8][1])
			{
				q.push(MP(rem8,MP(eight+1,six)));
				visited[rem8][1]=1;
			}
		}
	}
}

int main()
{
	int t;
	inp(t);
	while(t--)
	{
		int x,i;
		mx=-1;
		flag=0;
		inp(x);
		bfs(x);
		if(flag==0)
			printf("-1\n");
		for(i=0;i<=10009;i++)
		{
			visited[i][0]=0;
			visited[i][1]=0;
		}

	}
	return 0;
}
