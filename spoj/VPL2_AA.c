#include<stdio.h>
#include<math.h>
int main()
{
    int t,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        double a0,at,t,p,k,ans;
        scanf("%lf %lf %lf %lf",&a0,&at,&t,&p);
        k=(2.303/t)*log(a0/at);
        ans=(2.303/k)*log(a0/p);
        printf("Scenario #%d: %.2lf\n",x,ans);
     }
     return 0;
     }
