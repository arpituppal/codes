#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,res;
        scanf("%d %d",&n,&m);
        if(n==0 && m==0)
        printf("0\n");
        else if(n==0 || m==0)
            printf("0\n");
        else
        {
            res=((n-m)&((m-1)/2));
            printf("%d\n",!res);
        }
    }
    return 0;
}
