#include<stdio.h>
#include<math.h>
int main()
{
int l;
double p=acos(-1);
double r,a;
while(1)
{
    scanf("%d",&l);
    if(l==0)
        break;
    r=l/p;
    a=(p*r*r)/2;
    printf("%.2lf\n",a);
}
return 0;
}
