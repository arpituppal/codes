#include<stdio.h>
int main()
{
     long long int t,x;
     scanf("%lld",&t);
     for(x=1;x<=t;x++)
     {
          long long int w,b;
          scanf("%lld %lld",&w,&b);
          if(b%2==1)
          printf("1.000000\n");
          else
          printf("0.000000\n");
          
     }
     return 0;
}