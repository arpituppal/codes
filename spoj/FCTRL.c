#include<stdio.h>
int main()
{
    long long int t,x;
    scanf("%lld",&t);
    for(x=1;x<=t;x++)
    {
       long long int n,f=5,s=0;
       scanf("%lld",&n);
       while(f<=n)
       {
          s=s+(n/f);
          f=f*5;
        }
       printf("%lld\n",s);
     }
       return 0;
   }
