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

unsigned long long int modu(unsigned long long int base,unsigned long long int exp,unsigned long long int newmod)
{
     unsigned long long int res=1;
     while(exp>0)
      {
          if(exp%2==1)
           res=(res*base)%newmod;
            exp=exp>>1;
            base=(base*base)%newmod;
      }
      return res;
 }
int main()
{
      unsigned long long int n,ans,modi=1000000007;

      while(scanf("%llu",&n)!=EOF)
      {
           unsigned long long int newmod=(3*modi);
          //  printf("%llu\n",newmod);
            if(n%2==1)
                  ans=(modu(2,n,newmod)+1)/3;
            else
                  ans=(modu(2,n,newmod)+2)/3;
            printf("%llu\n",ans);
      }
      return 0;
}
