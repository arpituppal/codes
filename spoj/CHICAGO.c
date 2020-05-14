#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double a,b,ans;
        scanf("%lf %lf",&a,&b);
        ans=2*sqrt((a*a)-(b*b));
        printf("%.3lf\n",ans);
    }
return 0;
}
