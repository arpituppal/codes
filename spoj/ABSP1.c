#include<stdio.h>
#include<math.h>
long long int a[10001];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i;
        long long int sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i]*(2*i-n+1);
        }
       printf("%lld\n",sum);
    }
    return 0;
}
