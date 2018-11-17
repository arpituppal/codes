#include<stdio.h>
int main()
{
    int n;
    while(1)
    {
        int m=2,f=0;
        scanf("%d",&n);
        if(n==0)
        break;
        while(m<=n)
        {
            m=m*2;
            f++;
        }
        printf("%d\n",f);
    }
    return 0;
}
