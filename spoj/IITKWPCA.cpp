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

 map<string,int>mp;
int main()
{
      int t;
      scanf("%d",&t);
      getchar();
     // cout<<t<<endl;
      while(t--)
      {

            int i=0,l,j,ans=0;
            string s,s1="";

            getline(cin,s);
            l=s.length();
           // cout<<"tring "<<s<<endl;
           while(i<l && s[i]==' ')
           i++;
            for(;i<l;)
            {
                  //cout<<s[i]<<endl;
                   //printf("%d\n",i);
                  if(s[i]!=' ')
                        s1=s1+s[i++];

                  else
                  {
                        //cout<<"--- "<<s1<<endl;

                        mp[s1]=1;
                        s1="";
                        j=i+1;
                        while(j<l && s[j]==' ')
                              j++;
                        i=j;


                  }
            }

            if(s1!="")
            {mp[s1]=1;}
            ans=mp.size();
            printf("%d\n",ans);
            mp.clear();
           // printf("%d\n",mp.size());
      }
      return 0;
}
