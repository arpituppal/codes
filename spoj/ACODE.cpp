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
char s[5100];
long long int ans[5100];
int main()
{
      while(1)
      {
            int i,l,tdigit;
         scanf("%s",s);
            l=strlen(s);

            if(l==1 && s[0]=='0')
                  break;
            if(s[0]=='0')
                  ans[0]=0;
            else
            ans[0]=1;

            if(l>1)
            {
                  if(s[1]!='0')
                  ans[1]=ans[0];
                  else
                  ans[1]=0;
                  tdigit=((s[0]-48)*10+(s[1]-48));
                  if(tdigit>9 && tdigit<=26)
                  ans[1]+=ans[0];
            }
            for(i=2;i<l;i++)
            {
                  if(s[i]!='0')
                        ans[i]=ans[i-1];
                  else
                  ans[i]=0;

                  tdigit=((s[i-1]-48)*10+(s[i]-48));
                  if(tdigit>9 && tdigit<=26)
                        ans[i]+=ans[i-2];
;            }
            printf("%lld\n",ans[l-1]);
      }
      return 0;
}
