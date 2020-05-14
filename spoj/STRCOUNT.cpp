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

LL ans[66][66];

int main()
{
      ans[0][0]=1;
      ans[0][2]=0;
      ans[0][1]=0;
      ans[1][0]=1;
      ans[1][1]=1;
      ans[2][0]=1;
      ans[2][1]=2;
      ans[2][2]=1;
      int i,j,k,x;
      for(i=3;i<=63;i++)
      {
            ans[i][0]=1;
            for(j=1;j<i;j++)
            {
                  for(k=1;k<=j;k++)
                        ans[i][j]+=ans[i-k][j];
                  for(x=0;x<=j;x++)
                        ans[i][j]+=ans[i-k][x];
            }
            ans[i][i]=1;
      }
      for(i=1;i<64;i++)
      {
            for(j=0;j<=i;j++)
                  printf("%lld ",ans[i][j]);
            printf("\n");
      }
      return 0;
}
