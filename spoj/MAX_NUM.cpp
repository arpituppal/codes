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

char s[100010],ans[100010];
  int arr[100010][10];
int main()
{
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int k,i=0,idx=0,j=0,l,ansidx=0;

            memset(arr,-1,sizeof(arr));

            scanf("%s",s);
            scanf("%d",&k);

            l=strlen(s);

            if(k==0)
            {
                  printf("%s\n",s);
                  continue;
            }
            if(k>l)
            {
                  printf("\n");
                  continue;
            }
         /*   idx=0;
            while(k>0 && s[idx]==0 && idx<l)       //remove leading zeros
            {
                  k--;
                  idx++;
            }*/
            for(i=l-1;i>=0;i--)
                  arr[i][s[i]-48]=i;

            for(i=l-2;i>=0;i--)
            {
                  for(j=0;j<10;j++)
                  {
                        if(arr[i][j]==-1)
                              arr[i][j]=arr[i+1][j];
                  }
            }

          /*  for(i=0;i<l;i++)
            {
                  for(j=0;j<10;j++)
                        printf("%d ",arr[i][j]);
                  printf("\n");
            }*/
            idx=0;
            ansidx=0;
             while(1)
             {
             //     printf("k=%d\n",k);
                 // printf("ansidx=%d l-k=%d \n",ansidx,l-k);
                  if(k==0)
                  break;
                  if(l-idx==k)
                  {
                        idx=l;
                        break;
                  }
                /*  if(ansidx==(l-k))
                  {
                        idx=l;
                        break;
                  }
*/
                  for(i=9;i>=0;i--)
                  {
                 //       if(arr[idx][i]!=1)
                    //          printf("%d\n",arr[idx][i]);

                        if(arr[idx][i]!=-1 &&(arr[idx][i]-idx)<=k)
                        {
                         //     printf("YES\n");
                              ans[ansidx++]=s[arr[idx][i]];
                              k-=(arr[idx][i]-idx);
                              idx=arr[idx][i]+1;
                              break;
                        }
                  }
           }
            for(;idx<l;idx++)
            ans[ansidx++]=s[idx];
            ans[ansidx]='\0';
            printf("%s\n",ans);
      }
      return 0;
}
