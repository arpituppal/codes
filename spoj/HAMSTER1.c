#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int v,k1,k2;
        double theta,points,pi=3.14159265;
        scanf("%d %d %d",&v,&k1,&k2);
        if(k1==0)
            theta=pi/2.0;
        else if(k2==0)
            theta=pi/4.0;
        else
            theta=atan(-(double)4.0*k1/(double)k2)/2;
        if(theta<0)
            theta+=pi/2.0;
        points=((double)v*v)/10.0*(k1*sin(2.0*theta)+k2*sin(theta)*sin(theta)/2.0);
        printf("%.3lf %.3lf\n",theta,points);
    }
    return 0;
}
