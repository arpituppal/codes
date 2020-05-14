#include<cstdio>
#define N 1000001

using namespace std;

long long int a[N],b[N];
int main()
{
	int i,j;
	long long int s=0;
    for(i=1;i<=N/2;i++)
    {
        for(j=2*i;j<=N;j+=i)
         a[j]+=i;
         s+=a[i];
        b[i]=s;
    }
    for(;i<=N;i++)
    {
        s+=a[i];
        b[i]=s;
    }
    int t,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
      long long int n;
      scanf("%lld",&n);
      printf("%lld\n",b[n]);
     }
     return 0;
 }
