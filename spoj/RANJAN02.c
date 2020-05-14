#include<stdio.h>
#include<math.h>
long long int a[36];
int main()
{
    int t,i;
    scanf("%d",&t);
    a[1]=3;
    for(i=2;i<=35;i++)
    a[i]=a[i-1]*3;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n==0)
            printf("0\n");
        else
        printf("%lld\n",(a[n]-1));
    }
    return 0;
}
