#include<stdio.h>
int a[1001];
int main()
{
    int i,j,min;
    for(i=1;i*i<=1000;i++)
    a[i*i]=1;
    for(i=1;i<=1000;i++)
    {
        if(a[i]==1)
        continue;
        else
        {
            min=1000000;
            for(j=1;j<=i/2;j++)
            {
                if(a[j]+a[i-j]<min)
                min=a[j]+a[i-j];
            }
            a[i]=min;
        }
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}
