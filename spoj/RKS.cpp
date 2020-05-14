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
inline void inp( int &n )
{
n=0; int ch=getcx();int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
}
inline void inp1( LL &n )
{
n=0; LL ch=getcx();LL sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
}
LL arr[10000],temp[10000],cnt[10000],arr1[10000];
int b[10000],temp1[10000];

void merge(LL arr[],int b[],int l,int h)
{
      int i,k=l,j,mid;
      mid=(l+h)/2;
      i=l;
      j=mid+1;
      while(i<=mid && j<=h)
      {
           if(arr[i]==arr[j])
            {
                  if(b[i]<b[j])
                  {
                        temp[k]=arr[i];
                        temp1[k]=b[i];
                        i++;
                        k++;
                  }
                  else
                  {
                        temp[k]=arr[j];
                        temp1[k]=b[j];
                        k++;
                        j++;
                  }
            }
            else if(arr[i]>arr[j])
            {
                  temp[k]=arr[i];
                  temp1[k]=b[i];
                  k++;
                  i++;
            }
            else
            {
                  temp[k]=arr[j];
                  temp1[k]=b[j];
                  j++;
                  k++;
            }

      }
      while(i<=mid)
      {
            temp[k]=arr[i];
            temp1[k]=b[i];
            i++;
            k++;
      }
      while(j<=h)
      {
            temp[k]=arr[j];
            temp1[k]=b[j];
            j++;
            k++;
      }
      for(i=l;i<=h;i++)
      {
            arr[i]=temp[i];
            b[i]=temp1[i];
      }
}

void mergesort(LL arr[],int b[],int l,int h)
{
      if(l>=h)
            return;
      int mid=(l+h)/2;
      mergesort(arr,b,l,mid);
      mergesort(arr,b,mid+1,h);
      merge(arr,b,l,h);

}

int main()
{
      int n,i,j=0;
      LL c,val;
      inp(n);
      inp1(c);
      for(i=0;i<n;i++)
      {
           inp1(arr[i]);
           b[i]=i;
           arr1[i]=arr[i];
      }
      mergesort(arr,b,0,n-1);   //arr consists of elements and b their indexes
	cnt[0]=1;

	for(i=1;i<n;i++)
	{					 //now cnt will conain count and b will contain first index
		if(arr[i]==arr[i-1])
		cnt[j]++;
		else
		{
			j++;
			cnt[j]=1;
			b[j]=b[i];
		}
	}
	mergesort(cnt,b,0,j);

 	for(i=0;i<=j;i++)
      {
      	for(int k=1;k<=cnt[i];k++)
      	printf("%d ",arr1[b[i]]);

      }

      return 0;
}
