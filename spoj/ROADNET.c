#include<stdio.h>
int a[200][200];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j,k,flag=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                flag=0;
                for(k=0;k<n;k++)
                {
                    if(k!=i && k!=j && a[i][k]+a[k][j]==a[i][j])
                    flag=1;
                }
            if(flag==0)
            printf("%d %d\n",i+1,j+1);
            }
         }
      }
        return 0;
     }
