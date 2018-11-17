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

char s[100],s1[1000];
int main()
{
      while(1)
      {
            int i,j,l,l1,ans=0,carry=0,sum=0,dig1,dig2;
            scanf("%s %s",s,s1);
            l=strlen(s);
            l1=strlen(s1);
            if(l==1 && s[0]=='0' && l1==1 && s1[0]=='0')
            break;
            i=l-1;
            j=l1-1;
            while(i>=0 && j>=0)
            {
                  dig1=s[i]-48;
                  dig2=s1[j]-48;
                  sum=dig1+dig2+carry;
                  if(sum>9)
                  { carry=sum/10; ans++;}
                  else
                  carry=0;
                  i--;
                  j--;
            }
            while(i>=0)
            {
                  dig1=s[i]-48;
                  sum=dig1+carry;
                  if(sum>9)
                  {carry=sum/10; ans++;}
                  else
                  carry=0;
                  i--;
            }
            while(j>=0)
            {
                  dig2=s1[j]-48;
                  sum=dig2+carry;
                  if(sum>9)
                  {carry=sum/10; ans++;}
                  else
                  carry=0;
                  j--;
            }
            if(ans==0)
            printf("No carry operation.\n");
            else if(ans==1)
            printf("1 carry operation.\n");
            else
            printf("%d carry operations.\n",ans);

      }
      return 0;
}
