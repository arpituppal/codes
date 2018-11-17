#include<stdio.h>
int a[1000000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,flag=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
                if(a[i]>i)
                flag=1;
        }
        if(flag==0)
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}
