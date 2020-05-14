#include<stdio.h>
int main()
{
   long int a,b,c,d,g=1;
   while(scanf("%ld%ld%ld%ld",&a,&b,&c,&d)!=EOF)
   {
      long int e[4],f;
      long int max1=0,max2=0,i;
      e[0]=a;
      e[1]=b;
      e[2]=c;
      e[3]=d;
      for(i=0;i<4;i++)
      {
        if(e[i]>max1)
        {
          max2=max1;
          max1=e[i];
        }
        else if(e[i]>=max2 && e[i]<=max1)
        max2=e[i];
    }
     f=max1+max2;
     printf("Case %ld: %ld\n",g,f);
     g++;
     }
     return 0;
     }
