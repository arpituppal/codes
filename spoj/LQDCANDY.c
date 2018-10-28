#include<stdio.h>
#include<math.h>
int a[500];
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int n,n1,i,k=0,ans,m;
        scanf("%lld",&n);
        n1=n;
        while(n1>0)
        {
            a[k++]=n1%2;
            n1/=2;
        }
        //for(i=0;i<k;i++)
          //  printf("%d ",a[i]);

        for(i=0;i<k;i++)
        {
            if(a[i]==1)
            {
                //printf("FOUND at i=%d\n",i);
                if(i!=k-1)
                ans=(k-i);
                else
                ans=0;
                break;
            }
        }
        m=pow(2,k);
        if(m/n==2)
        m=m/2;
        printf("%lld %lld\n",m,ans);
    }
    return 0;
}
