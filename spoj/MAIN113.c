#include<stdio.h>
long long int ans[30];
int main()
{
    int t,i;
    scanf("%d",&t);
    ans[0]=3;
    ans[1]=9;
    for(i=2;i<30;i++)
    ans[i]=(2*ans[i-1])+ans[i-2];
    while(t--)
    {
       long long int n;
        scanf("%lld",&n);
        printf("%lld\n",ans[n-1]);
     }
    return 0;
}
