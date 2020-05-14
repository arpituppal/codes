#include<stdio.h>
int main()
{
    int n;
    while(1)
    {
        int i,kill=0,m=0,last=0;
        scanf("%d",&n);
        if(n==0)
        break;
        while(last!=13)
        {
            kill=0;
            m++;
            for(i=2;i<=n-1;i++)
            kill=(kill+m)%i;
            last=kill+2;
        }
        printf("%d\n",m);
    }
    return 0;
}
