#include<stdio.h>
int main()
{
    long long int t,x;
    scanf("%lld",&t);
    int a[10000]={0};
    int b[100000]={0};
    for(x=1;x<=t;x++)
    {
        int n,r,i,flag=0;
        scanf("%d %d",&n,&r);
        for(i=1;i<=r;i++)
        {
           int r1,r2;
           scanf("%d %d",&r1,&r2);
           a[r1]=1;
           b[r2]=1;
        }
        for(i=0;i<n;i++)
        {
            if(a[i]==1)
            {
               if(b[i]==1)
               flag=1;
            }
            a[i]=0;
            b[i]=0;
        }
        if(flag==1)
        printf("Scenario #%lld: spied\n",x);
        else
        printf("Scenario #%lld: spying\n",x);
     }
     return 0;
    }

