#include<stdio.h>
int main()
{
   long long int t,x;
   scanf("%lld",&t);
   for(x=1;x<=t;x++)
   {
      double n;
      double f;
      scanf("%lf",&n);
      f=((2*n)+1)/n;
      printf("%.8lf\n",f);
    }
return 0;
}
