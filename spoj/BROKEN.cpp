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
string s;
int freq[500];
int main()
{
      while(1)
      {
            int m,i,j,cnt=0,l,maxlen=-1,len=0;
            scanf("%d",&m);

            if(m==0)
                  break;
                  getchar();
            getline(cin,s);
            //gets(s);
            l=s.length();
            i=0;j=0;
            while(i<l && j<l)
            {

                  int a=s[j];

                 // printf("i=%d j=%d freqi=%d freqj=%d\n",i,j,freq[(int)s[i]],freq[a]);
                  if(freq[a]>0)           //repeating charcater so include it
                  {
                        freq[a]++;
                        len++;
                        maxlen=MAX(maxlen,len);
                      //  printf("YES at i=%d mxlen=%d\n",i,maxlen);
                  }
                  else                    //new distinct character
                  {
                       // printf("YYY at j=%d cnt=%d\n",j,cnt);
                        if(cnt+1<=m)            //no harm including this
                        {
                              //printf("YESSSSSS at j=%d\n",j);
                              freq[a]++;
                              cnt++;
                              len++;
                              maxlen=MAX(maxlen,len);
                              //printf("YES freq%d\n",freq[a]);
                        }
                        else               //harm, exclude fro left side
                        {
                              while(freq[(int)s[i]]>1)
                              {
                                    freq[(int)s[i]]--;
                                    i++;
                                    len--;
                              }

                              freq[(int)s[i]]--;
                              freq[a]++;
                             // printf("YES at i=%d freq\n",i);
                              i++;
                              maxlen=MAX(maxlen,len);
                        }
                  }

                  j++;
            }
            printf("%d\n",maxlen);
            memset(freq,0,sizeof(freq));
      }
return 0;
}
