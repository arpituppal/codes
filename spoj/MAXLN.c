#include<stdio.h>
int main()
{
    int t,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
       long long int r;
       double ans;
       scanf("%lld",&r);
       ans=(4*r*r)+0.25;
       printf("Case %d: %.2lf\n",x,ans);
    }
    return 0;
 }
