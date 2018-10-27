#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,ans,ans1,ans2;
        double ans3;
        scanf("%lld",&n);
        ans1=ceil(sqrt((8*n)-7));
        ans2=ans1-1;
        if(ans2%2==1)
        ans2+=1;
        ans=ans2/2;
        printf("%lld\n",ans);
    }
return 0;
}
