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
inline void inp( int &n )
{
n=0;int ch=getcx();int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
}
long long int arr[100010],ans[100010];
int main()
{
      int t,x;
      inp(t);
     for(x=1;x<=t;x++)
      {
            int n,q,i,u,v;
            inp(n);
            inp(q);
            ans[1]=1;
            scanf("%lld",&arr[1]);
            for(i=2;i<=n;i++)
            {
                  scanf("%lld",&arr[i]);

                  if(arr[i]!=arr[i-1])
                  ans[i]=ans[i-1]+1;
                  else
                  ans[i]=ans[i-1];
            }
            printf("Case %d:\n",x);
            for(i=1;i<=q;i++)
            {
                  inp(u);
                  inp(v);
                  printf("%lld\n",(ans[v]-ans[u]+1));
            }
      }
      return 0;
}
