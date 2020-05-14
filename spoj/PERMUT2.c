#include<stdio.h>
int main()
{
    int n,a[100000];
    while(1)
    {
        int i,flag=0;
        scanf("%d",&n);
        if(n==0)
        break;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
            if(a[a[i]-1]!=(i+1))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        printf("ambiguous\n");
        else
        printf("not ambiguous\n");
    }
    return 0;
}
