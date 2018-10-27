#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,m;
        scanf("%lld %lld",&n,&m);
        if(m==0)
        printf("Airborne wins.\n");
        else
        printf("Pagfloyd wins.\n");
    }
    return 0;
}
