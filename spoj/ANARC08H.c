#include<stdio.h>
int main()
{
    int n,d;
    while(1)
    {
        int i,ans=0;
        scanf("%d %d",&n,&d);
        if(n==0)
        break;
        for(i=1;i<=n;i++)
        ans=(ans+d)%i;
        printf("%d %d %d\n",n,d,(ans+1));
    }
    return 0;
}
