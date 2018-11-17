#include<stdio.h>
int main()
{
 int t;
 scanf("%d",&t);
    while(t--)
    {
        int n,m,k=0,i,flag=0;
        long long int ans,r=1;
        scanf("%d",&n);
        m=n;
        if(n<10 && n!=0)
        printf("%d\n",n);
        else if(n==0)
            printf("10\n");
        else
        {
            for(i=9;i>=2;i--)
        {
            if(m%i==0)
            {
                while(m%i==0)
                {
                    if(k==0)
                   {
                        r=10;
                        ans=i;
                        m=m/i;
                        k=1;
 }
else
{
 m/=i;
ans=(i*r)+ans;
 r=r*10;
 }
}
             }
            if(m==1 || m<10)
                 flag=1;

         }
         if(flag==0)
         printf("-1\n");
         else
         printf("%lld\n",ans);
      }
    }
      return 0;
  }

