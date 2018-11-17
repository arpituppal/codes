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

char s[100010];
int hash[52];
int main()
{
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int n,i,ans=0,l;
            scanf("%d",&n);
            scanf("%s",s);
            memset(hash,0,sizeof(hash));
            l=strlen(s);
            for(i=0;i<l;i++)
            {
                  if(s[i]>=97 && s[i]<=122)
                        hash[s[i]-97]++;
                  if(s[i]>=65 && s[i]<=90)
                  {
                        if(hash[s[i]-65]==0)
                              ans++;
                        else
                              hash[s[i]-65]--;
                  }
            }
            printf("%d\n",ans);
      }
      return 0;
}
