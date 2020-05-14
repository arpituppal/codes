#include<stdio.h>
int main()
{
   long int t,x;
   scanf("%ld",&t);
   for(x=1;x<=t;x++)
   {
      long int n,i=2,f=0,ev=0,odd=0;
      scanf("%ld",&n);
      while(i*i<=n)
      {
          f=0;
        while(n%i==0)
        {
          f++;
          n=n/i;
          }
         if(f%2==0 && f!=0)
         ev++;
         if(f%2==1 && f!=0)
           odd++;
          i++;
        }
     if(n>1)
     odd++;
     if(ev>odd)
     printf("Psycho Number\n\n");
     else
     printf("Ordinary Number\n\n");
    }
    return 0;
    }
