#include<stdio.h>
int main()
{
    long long int n;
    scanf("%lld",&n);
    if(n%10!=0)
    printf("1\n%d\n",(n%10));
    else if(n%10==0)
    printf("2\n");
    return 0;
 }
