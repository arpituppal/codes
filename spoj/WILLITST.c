#include<stdio.h>
int main()
{

    long long unsigned int n,f=0;
    scanf("%llu",&n);
    while(n>=2)
    {
        if(n%2!=0)
        {
            f=1;
            break;
        }
        else
        n=n/2;
    }
    if(f==0)
        printf("TAK\n");
    else
        printf("NIE\n");
    return 0;
}
