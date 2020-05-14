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
void output(int x)  // Fast Output
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
    int len=0,data[10];
	while(x)
	{
		data[len++]=x%10;
		x/=10;
	}
	if(!len)
		data[len++]=0;
	while(len--)
		putchar(data[len]+48);
	//putchar('\n');
}
 //1st one is mod 2nd is node number
int visited[20010],ans[1000000];
long long int bfs(int n)
{
	queue<pair<int,long long int> >q;
	int rem;
	visited[1%n]=1;
	//printf("mod=%d\n",1%n);
	q.push(MP(1%n,1));
	while(!q.empty())
	{
		int val=q.front().first;
		long long int node=q.front().second;
		q.pop();
		if(val==0)
		 return node;
		 if(!visited[(val*10)%n])
       		{
       		  //   printf("val=%d node=%lld\n",((val*10)%n),(2*node));
       			visited[((val*10)%n)]=1;
       			 q.push(MP(((val*10)%n),(2*node)));
       		}
		if(!visited[(val*10+1)%n])
		    {
		  //  	printf("val=%d node=%lld\n",((val*10+1)%n),(2*node+1));
		    		visited[((val*10+1)%n)]=1;
		    	 	q.push(MP(((val*10+1)%n),(2*node+1)));
		    }
    }	 
}
int main()
{
	int t;
	inp(t);
	while(t--)
	{
		int n,i,j=0;
		inp(n);
		for(i=0;i<=20010;i++)
		visited[i]=0;
		long long int node=bfs(n);
	//	printf("node=%lld\n",node);
		while(node!=0)
		{
			if(node%2==1)
			 ans[j++]=1;
			 else
			 ans[j++]=0;
			 node/=2;
		}
		for(i=j-1;i>=0;i--)
		output(ans[i]);
		printf("\n");
	}
	return 0;
}
