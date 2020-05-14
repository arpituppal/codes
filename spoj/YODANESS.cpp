/*
ARPIT UPPAL
MNNIT ALLAHABAD
*/
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
#include <string>
#include <sstream>
#include <utility>
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<long long> VLL;
typedef vector<bool> VB;
#define SZ(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A, x) (A.find(x) != A.end())
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rev(i, a, n) for(int i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
inline void inp( int &n )
{
n=0; int ch=getcx();int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
} 

map<string,int>m;

int arr[30010],ans[30010],c=0;
void merge(int a[],int,int);
void mergesort(int [],int,int);

void mergesort(int a[],int i,int j)
{
   int mid;
   if(i>=j)
   return;
   mid=(i+j)/2;
   mergesort(a,i,mid);
   mergesort(a,mid+1,j);
   merge(a,i,j);
}
void merge(int b[],int low,int high)
{
	int i,j,mid,k=low;
      mid=(low+high)/2;
      i=low,j=mid+1;
     while(i<=mid && j<=high)
    {
        if(b[i]<=b[j])
        ans[k++]=b[i++];
        else
        {
         c+=(j-k);
         ans[k++]=b[j++];
        }
    }
    while(i<=mid)
    ans[k++]=b[i++];
    while(j<=high)
    ans[k++]=b[j++];
    for(i=low;i<=high;i++)
    arr[i]=ans[i];
 }
int main()
{
 	int t;
 	inp(t);
 	char s[100000];
 	while(t--)
 	{
 		int n,i;
 		c=0;
 		
 		string word;
 		inp(n);
 		for(i=1;i<=n;i++)
 		{
 			scanf("%s",s);
 			//word=s;
 			m[s]=i;
 		}
 		for(i=0;i<n;i++)
 		{
 			scanf("%s",s);
 			//word=s;
 			arr[i]=m.find(s)->second;
 		}
 		mergesort(arr,0,n-1);
 		printf("%d\n",c);
 	}
 	return 0;
 }