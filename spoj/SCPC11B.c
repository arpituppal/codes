#include<stdio.h>
int main()
{
long long int n;
while(1)
{
     scanf("%lld",&n);
     if(n==0)
     break;
     long long int a[n+1];
     int f=1;
     long long int x,i,j,t;
     for(x=0;x<n;x++)
     scanf("%lld",&a[x]);
     a[n]=1422;
     for(i=0;i<n+1;i++)
      {
        for(j=0;j<(n+1)-(i+1);j++)
         {
          if(a[j]>a[j+1])
           {
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
         }}}
     for(i=0;i<n;i++)
       {
        if((a[i+1]-a[i])>200)
         {
           f=0;
           break;
         }
       }
     if((a[n]-a[n-1])>100)
     f=0;
     if(f==1)
     printf("POSSIBLE\n");
     else
     printf("IMPOSSIBLE\n");
   }
 return 0;
}
