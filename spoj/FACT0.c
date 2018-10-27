#include<stdio.h>
int main()
{
    while(1)
    {
        long long int n,i=2,f=0;
        scanf("%lld",&n);
        if(n==0)
        break;
         while(i*i<=n)
          {
            f=0;
           while(n%i==0)
             {
                f++;
                n=n/i;
                }

          if(f>0)
          printf("%lld^%lld ",i,f);
          i++;
        }
     if(n>1)
     printf("%lld^1 ",n);
     printf("\n");
     }
     return 0;
     }
