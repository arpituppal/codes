#include<stdio.h>
int a[1000000],b[1000000],ans[1000000];
int main()
{
    int n;
    while(1)
    {
        int sum=0,flag=0,i;
        scanf("%d",&n);
        if(n==0)
        break;
        for(i=0;i<n;i++)
        ans[i]=-1;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
            sum+=b[i];
        }
        if(sum!=0)
        flag=1;
       else
       {
           for(i=0;i<n;i++)
            {
                if(ans[(b[i]+i)]!=-1)
                {
                    flag=1;
                    break;
                }
                ans[(b[i]+i)]=a[i];
            }
       }
        if(flag==1)
        printf("-1\n");
        else
        {
            for(i=0;i<n;i++)
            printf("%d ",ans[i]);
            printf("\n");
        }

    }
    return 0;
}
