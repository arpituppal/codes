#include<stdio.h>
int main()
{
   int t,x;
   scanf("%d",&t);
   for(x=1;x<=t;x++)
   {
        long long int n,i,e,c=1,flag=0;
        scanf("%lld",&n);
        long long int a[n];
        scanf("%lld",&a[0]);
         e=a[0];
       for(i=1;i<n;i++)
       {
           scanf("%lld",&a[i]);
           if(e==a[i])
            c++;
           else
           {
               c--;
               if(c==0)
               {
                   e=a[i];
                   c=1;
               }
           }
       }
       for(i=0;i<n;i++)
       {
           if(a[i]==e)
            flag++;
       }
       if(flag>n/2)
        printf("YES %lld\n",e);
       else
        printf("NO\n");
   }
   return 0;
}
