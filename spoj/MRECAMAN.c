#include<stdio.h>
long long int ans[10000000],a[10000000];
int main()
{
    long long int i,k;
    a[0]=0;
    ans[0]=1;
    for(i=1;i<500001;i++)
    {
        k=a[i-1]-i;
        if(k>0)
        {
            if(ans[k]==0)
            {
              a[i]=k;
               ans[k]=1;

            }
            else if(ans[k]==1)
            {

                    a[i]=a[i-1]+i;

                    ans[a[i]]=1;
            }

        }
        if(k<=0)
        {
            a[i]=a[i-1]+i;
            ans[a[i-1]+i]=1;

        }
    }
    while(1)
    {
        long long int n;
        scanf("%lld",&n);
        if(n==-1)
        break;
        printf("%lld\n",a[n]);
    }
    return 0;
}
