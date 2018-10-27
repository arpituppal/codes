#include<stdio.h>
#define N 300000
long long int a[N];
int main()
{
    long long int n,m,i,sum=0,maxsum=0,c=0;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++)
    scanf("%lld",&a[i]);
    for(i=0;i<=n;i++)
    {
        if(sum>m)
        {
            while(sum>m && c<=(i-1))
            sum=sum-a[c++];
        }

            if(sum>maxsum)
            maxsum=sum;
            sum+=a[i];
    }

    printf("%lld\n",maxsum);
   return 0;
}
