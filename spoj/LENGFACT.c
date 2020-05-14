#include<stdio.h>
#include<math.h>
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
        long long int n,ans;
        double pi= 3.14159265358979323;
        double e=2.71828182845904523536;
        scanf("%lld",&n);
        if(n==0 || n==1)
        ans=1;
        else
        ans=((log(2*pi*n)/2+n*(log(n)-1))/log(10))+1;
        printf("%lld\n",ans);
    }
    return 0;
    }
