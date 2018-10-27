#include<stdio.h>
#include<string.h>
#include<math.h>
 int main()
   {
      char a[10000];
      while(scanf("%s",a)!=EOF)
      {
        int l,i,d=0,e=0;
        l=strlen(a);
        for(i=0;i<l;i++)
        {
          if(i%2==0)
          {
              if(a[i]>=65 && a[i]<=90)
              d++;
               if(a[i]>=97 && a[i]<=122)
                   e++;
            }
        else if(i%2==1)
          {

              if(a[i]>=97 && a[i]<=122)
                d++;
              if(a[i]>=65 && a[i]<=90)
                 e++;
          }
        }
        if(d>e)
            printf("%d\n",e);
        else
            printf("%d\n",d);
      }
        return 0;
      }
