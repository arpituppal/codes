#include<stdio.h>
int main()
{
    double n;
    while(1)
    {
        scanf("%lf",&n);
        if(n==0.00)
        break;
        double sum=0;
        int i=0;
     while(sum<=n)
    {
            sum+=(double)1/(i+2);
            i++;
        }
       printf("%d card(s)\n",i);
    }
    return 0;
 }
