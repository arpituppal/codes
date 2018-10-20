#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n%2==1)
        printf("0\n");
        else
        printf("1\n");
    }
return 0;
}
