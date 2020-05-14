#include<stdio.h>
#define min(a1,b1) a1<b1?a1:b1
long long int a[25][3],ans[25][3];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j;
        long long int min1=1000000,t1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);
        }
        for(i=0;i<3;i++)
        ans[0][i]=a[0][i];
        if(n==2)
        {
        for(i=1;i<n;i++)
         {
            t1=min((a[i][0]+ans[i-1][1]),(a[i][0]+ans[i-1][2]));
            ans[i][0]=min((t1),(a[i][0]+ans[i-1][0]));
            t1=min((a[i][1]+ans[i-1][0]),(a[i][1]+ans[i-1][2]));
            ans[i][1]=min(t1,(a[i][1]+ans[i-1][1]));
            t1=min((a[i][2]+ans[i-1][0]),(a[i][2]+ans[i-1][1]));

           }
        }
        else
       {
        for(i=1;i<n;i++)
         {
            ans[i][0]=min((a[i][0]+ans[i-1][1]),(a[i][0]+ans[i-1][2]));
            ans[i][1]=min((a[i][1]+ans[i-1][0]),(a[i][1]+ans[i-1][2]));
            ans[i][2]=min((a[i][2]+ans[i-1][0]),(a[i][2]+ans[i-1][1]));
        }
    }
        for(i=0;i<3;i++)
        {
            if(ans[n-1][i]<min1)
            min1=ans[n-1][i];
        }
        printf("%lld\n",min1);
    }

    return 0;
}
