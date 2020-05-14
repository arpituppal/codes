#include<stdio.h>
int a[1001],ans[1001];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j,flag=0;
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            ans[a[i]]++;
         }
         for(i=0,j=n-1;i<=n/2;i++,j--)
         {
            if(ans[i]+ans[j]!=2)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        printf("NO\n");
        else
        printf("YES\n");
        for(i=0;i<n;i++)
        ans[i]=0;
    }
    return 0;
}
