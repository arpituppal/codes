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
long long int base=2;
long long int mod(long long int exp)
{
      long long int res=1;
      while(exp>0)
      {
            if(exp%2==1)
            res=(res*base)%MOD;
            exp=exp>>1;
            base=(base*base)%MOD;
      }
      return res;
}
int main()
{
      int t,x;
      scanf("%d",&t);
      for(x=1;x<=t;x++)
      {
            long long int n,ans;
            base=2;
            scanf("%lld",&n);
            if(n==1)
            printf("Case %d: 1\n",x);
            else
            {
                  long long int power=mod(n-2);
                //  printf("power=%lld\n",power);
                  ans=((n+1)*power)%MOD;
                  printf("Case %d: %lld\n",x,ans);
            }
      }
      return 0;
}
