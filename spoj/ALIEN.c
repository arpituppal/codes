#include<stdio.h>
#define N 100000
long long int a[N];
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {

        long long int n,m,i,sum=0,maxsum=0,c=0,num=0,maxnum=0;
        scanf("%lld %lld",&n,&m);
        for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
        for(i=0;i<=n;i++)
        {
            if(sum>m)
            {
                while(sum>m && c<=(i-1))
                {
                    sum=sum-a[c++];
                    num--;
                }
            }

            if( num>maxnum || (num==maxnum)&&(sum<maxsum))
            {
                    maxsum=sum;
                    maxnum=num;
            }
            sum+=a[i];
            num++;
    //        printf("sum=%lld maxsum=%lld\n",sum,maxsum);
    }
    printf("%lld %lld\n",maxsum,maxnum);
    }
   return 0;
}
