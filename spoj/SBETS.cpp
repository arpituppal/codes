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
int arr[100];
int main()
{
	int t;
	inp(t);
	while(t--)
	{
		map<string,int>m;
		char s1[5],s2[5];
		string win="";
		int max=-1,i,g1,g2;
		for(i=1;i<=16;i++)
		{
			scanf("%s",s1);
			scanf("%s",s2);
			inp(g1);
			inp(g2);
			if(g1>g2)
			   {
			   	 m[s1]++;
			   	 if(m[s1]>max)
			   	 {
			   	 	max=m[s1];
			   	 	win=s1;
			   	 }
			   }
			else
			{
				m[s2]++;
				if(m[s2]>max)
				{
					max=m[s2];
					win=s2;
				}
			}
		}
		cout<<win<<endl;
	}
	return 0;
}
			