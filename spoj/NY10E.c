#include<stdio.h>
long long int a[65][10];
int main()
{
    int i,j;
    long long int t;
    long long int sum=0;
    for(i=0;i<10;i++)
    {
       a[0][i]=1;
       sum+=a[0][i];
    }
    for(i=1;i<65;i++)
    {
        a[i][0]=sum;
        for(j=1;j<10;j++)
        {
            a[i][j]=a[i][j-1]-a[i-1][j-1];
            sum+=a[i][j];
        }
     }
     scanf("%lld",&t);
     while(t--)
     {
        long long int x,n;
        scanf("%lld %lld",&x,&n);
        printf("%lld %lld\n",x,a[n][0]);
    }
    return 0;
 }
