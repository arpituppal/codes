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

char s[100][100];
int dp[100][100];

int main()
{
      int n,i,j;
      scanf("%d",&n);
      for(i=0;i<n;i++)
            scanf("%s",s[i]);

      dp[0][0]=1;
      for(i=0;i<n;i++)
      {
            for(j=0;j<n;j++)
            {
                  if(s[i][j]!='0' && dp[i][j]!=0)
                  {
                        int num=s[i][j]-48;
                        if(num+j<n)
                              dp[i][num+j]+=dp[i][j];
                        if(num+i<n)
                              dp[num+i][j]+=dp[i][j];
                  }
            }
      }
      printf("%d",dp[n-1][n-1]);
      return 0;
}

