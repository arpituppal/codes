/*
ARPIT UPPAL
MNNIT ALLAHABAD
*/
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

queue<int>q;
int visited[10000000],f,s,g,u,d;

void bfs()
{
	q.push(s);
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		if(curr==g)
		{
			printf("%d\n",visited[curr]);
			return ;
		}
		if(u!=0 && curr+u<=f && visited[curr+u]==0)
		{
			q.push(curr+u);
			visited[curr+u]=visited[curr]+1;
		}
		if(d!=0 && curr-d>=1 && visited[curr-d]==0)
		{
			q.push(curr-d);
			visited[curr-d]=visited[curr]+1;
		}
	
	}
	printf("use the stairs\n");
}
int main()
{
	inp(f);
	inp(s);
	inp(g);
	inp(u);
	inp(d);
	bfs();
	return 0;
}		