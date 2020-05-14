#include<stdio.h>
#include<algorithm>
#define mod 1000000007
int main()
{
    int t;
    scanf("%d",&t);
    int a[100];
    while(t--)
        {
          long long int ans=1;
         int flag=0,n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        std::sort(a,a+n);
        for(i=n-1;i>=0;i--)
         {
            a[i]-=i;
            if(a[i]<1)
            {
                flag=1;
                break;
            }
            ans=(ans*a[i])%mod;
        }
        if (flag==1)
        printf("0\n");
        else
        printf("%lld\n",ans);
    }
    printf("KILL BATMAN\n");
    return 0;
}
