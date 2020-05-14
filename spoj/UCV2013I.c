#include<stdio.h>
#include<math.h>
int main()
{
    double r,n;
    while(1)
    {
        double ans;
        scanf("%lf %lf",&r,&n);
        if(r==0 && n==0)
        break;
        ans=r/sin(acos(-1)*0.5/n);
        printf("%.2lf\n",ans);
    }
    return 0;
}
