#include<stdio.h>
int main()
{
   int t,x;
   scanf("%d",&t);
  int a[1000000],i=1,j,k,pos=0,c=2;
       a[0]=1;
       while(1)
       {
        j=0;
        k=a[pos];
         while(j!=k)
         {
         	j++;
           if(i>=1000000)
           break;
           a[i++]=c;
         }
          if(i>=1000000)
            break;
            pos++;
            c++;
       }
       for(x=1;x<=t;x++)
       {
           int n;
           scanf("%d",&n);
           printf("Case #%d: %d\n",x,a[n-1]);
       }
       return 0;
 }
