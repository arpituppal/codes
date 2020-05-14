#include<stdio.h>
int main()
{
   long long int t,x;
   scanf("%lld",&t);
   int a[20]={0};
   for(x=1;x<=t;x++)
   {
     int n,p,i,j,f=1,g=1,h=1,flag,ans=0;
     scanf("%d%d",&n,&p);
     for(i=1;i<=n;i++)
     {
       flag=0;
       int m;
       for(j=0;j<p;j++)
       {
         scanf("%d",&m);
         if(m==1)
          {
            a[j]=1;
            flag++;
          }
        }
        if(flag>=p)
          h=0;
        if(flag==0)
        g=0;
      }
      for(j=0;j<p;j++)
       {
         if(a[j]==0)
         f=0;
         a[j]=0;
        }
     ans=(f*4)+(g*2)+(h*1);
     printf("Case %lld: %d\n",x,ans);
   }
     return 0;
}
