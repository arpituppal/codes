#include<stdio.h>
#include<string.h>
#include<math.h>
int  main()
{
     int t,x;
     scanf("%d",&t);
     for(x=1;x<=t;x++)
     {
          double r,v,a,b,ans=0,g=9.806,pi;
          pi=2*acos(0.0);
          scanf("%lf %lf",&r,&v);
          a=(r*g)/v;
          b=a/v;
          if(b>1)
          printf("Scenario #%d: -1\n",x);
          else
          {
              ans=(asin(b)*180.0)/pi;
              ans=ans/2;
              printf("Scenario #%d: %.2lf\n",x,ans);
          }
     }
     return 0;
 }
