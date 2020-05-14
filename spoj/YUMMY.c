#include<stdio.h>
int main()
{
 long long int ans[16]={1,1,1,4,6,19,43,120,307,866,2336,6588,18373,52119,147700,422016};
 long long int t,x;
 scanf("%lld",&t);
 for(x=1;x<=t;x++)
 {
    int n;
    scanf("%d",&n);
    printf("Case #%lld: %lld\n",x,ans[n-1]);
 }
 return 0;
}
