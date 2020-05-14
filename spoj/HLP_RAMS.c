#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,m,f=0,odd,even;
        scanf("%lld",&n);
        m=n+1;
        while(n>0)
        {
           if(n%2==1)
           f++;
           n/=2;
        }
        odd=pow(2,f);
        even=m-odd;
        printf("%lld %lld\n",even,odd);
    }
    return 0;
}
