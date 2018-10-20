#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long double r1,r2,r3,r4,k1,k2,k3,k4,a;
        scanf("%Lf%Lf%Lf",&r1,&r2,&r3);
        k1=1/r1;
        k2=1/r2;
        k3=1/r3;
        a=sqrt((k1*k2)+(k2*k3)+(k3*k1));
        k4=(k1+k2+k3+(2*a));
        r4=1/k4;
        printf("%.6Lf\n",r4);
    }
    return 0;
 }
