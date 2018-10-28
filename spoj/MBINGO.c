#include<stdio.h>
#include<math.h>
int a[100],ans[100];
int main()
{
    int n,b,i,j;
    while(1)
    {
        int flag=0;
        scanf("%d %d",&n,&b);
        if(n==0 && b==0)
        break;
        for(i=0;i<b;i++)
        scanf("%d",&a[i]);
        ans[0]=1;
        for(i=0;i<b;i++)
        {
            for(j=i+1;j<b;j++)
            ans[(abs(a[j]-a[i]))]=1;
        }
        for(i=0;i<=n;i++)
        {
            if(ans[i]==0)
            {
                flag=1;
                break;
            }
        }
        for(i=0;i<=n;i++)
            ans[i]=0;
        if(flag==0)
        printf("Y\n");
        else
        printf("N\n");
     }
     return 0;
    }

