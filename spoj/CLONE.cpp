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

int arr[50000];
string s;
map<string,int>mp;
int main()
{
      while(1)
      {
            int n,m,i;
            scanf("%d %d",&n,&m);
            if(n==0 && m==0)
                  break;
            for(i=0;i<n;i++)
            {
                  cin>>s;
                  mp[s]++;
            }
            map<string,int>::iterator it;
            for(it=mp.begin();it!=mp.end();it++)
            {
                    arr[it->second-1]++;
            }
            for(i=0;i<n;i++)
            printf("%d\n",arr[i]);
            mp.clear();
            for(i=0;i<n;i++)
                  arr[i]=0;
      }
      return 0;
}
