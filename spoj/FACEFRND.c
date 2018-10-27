#include<stdio.h>
int main()
{
    int n,i,j,f=0;
    scanf("%d",&n);
    int a[10000]={0},b[10000]={0};
    for(i=1;i<=n;i++)
    {
        int m,r;
        scanf("%d %d",&r,&m);
        a[r]=1;
        for(j=1;j<=m;j++)
        {
            int p;
            scanf("%d",&p);
            b[p]++;
        }
    }
    for(i=0;i<10000;i++)
    {
        if(b[i]>0)
        {
            if(a[i]==0)
            f++;
        }
     }
     printf("%d\n",f);
     return 0;
    }
