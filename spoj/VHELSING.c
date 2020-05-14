#include <stdio.h>
#include <math.h>
int main()
{
    double i,r,j,v;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&r);
        j=2-sqrt(2);
        v=8*j*r*r*r;
        printf("%.4lf\n",v);
    }
    return 0;
}
