#include<stdio.h>
int main()
{
  int t,x;
  scanf("%d",&t);
  for(x=1;x<=t;x++)
  {
     double n,s;
     scanf("%lf",&n);
     s=n/(n+1);
     printf("%.8lf\n",s);
    }
    return 0;
    }
