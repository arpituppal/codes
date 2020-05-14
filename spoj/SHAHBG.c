#include<stdio.h>
int main()
{
    int q,x,c=0,a[30000]={0};
    scanf("%d",&q);
    for(x=1;x<=q;x++)
    {
        int p;
        scanf("%d",&p);
        a[p]=1;
        if(p==0)
        {
            if(a[p+1]==0)
                c=1;
            printf("%d\n",c);
        }
        else
        {
            if(a[p-1]==0 && a[p+1]==0)
            c=c+1;
            if(a[p-1]==1 && a[p+1]==1)
                c=c-1;
            printf("%d\n",c);
        }
        }
        printf("Justice\n");
    return 0;
 }
