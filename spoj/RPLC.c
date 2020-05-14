#include<stdio.h>
#include<math.h>
int main()
{
  long long int t,x;
  scanf("%lld",&t);
  char ch=getchar();
  for(x=1;x<=t;x++)
  {
    long long int n,m,i,sum=0,min=1;
    scanf("%lld",&n);
    ch=getchar();
    for(i=1;i<=n;i++)
    {
       scanf("%lld",&m);
       sum+=m;
       if(sum<0)
       {
           min+=abs(sum);
           sum=0;
       }}
       printf("Scenario #%lld: %lld\n",x,min);
       }
  return 0;
}
