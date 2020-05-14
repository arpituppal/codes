#include<stdio.h>
int a[100][100];
int main()
{
    int t,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
         int n,i,j,k,r,s,d;
         long long int sum=0;
         scanf("%d",&n);
         for(i=0;i<n;i++)
         {
            for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
         }
         for(k=0;k<n;k++)
         {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j]=a[i][k]+a[k][j];
                }
            }
         }
        scanf("%d",&r);
        for(i=0;i<r;i++)
        {
            scanf("%d %d",&s,&d);
            sum+=a[s-1][d-1];
        }
        printf("Case #%d: %lld\n",x,sum);
    }
    return 0;
}
