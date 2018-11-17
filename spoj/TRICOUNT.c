#include<stdio.h>
int main()
{
  long long int t,x;
  scanf("%lld",&t);
  for(x=1;x<=t;x++)
  {
    long long int n,g,ans=0;
    scanf("%lld",&n);
    g=(n*(n+2)*((2*n)+1));
    ans=g/8;
    printf("%lld\n",ans);
    }
    return 0;
 }
