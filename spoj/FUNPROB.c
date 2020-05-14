#include<stdio.h>
int main()
{
    while(1)
    {
        double n,m,ans=0;
        scanf("%lf%lf",&n,&m);
        if(n==0 && m==0)
        break;
        if(n==0)
        printf("1.000000\n");
        else if(m<n)
        printf("0.000000\n");
        else
        {
           ans=(m-n+1)/(m+1);
           printf("%.6lf\n",ans);
        }
    }
return 0;
}
