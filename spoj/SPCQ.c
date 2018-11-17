#include<stdio.h>
long long int digsum(long long int num)
{
      long long int num1=num;
      long long int sum=0;
      while(num1>0)
      {
        sum+=(num1%10);
        num1=num1/10;
      }
      if(num%sum==0)
        return num;
      digsum(num+1);

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
         long long int n,m,sum=0,i;
         scanf("%lld",&n);
         m=digsum(n);
         printf("%lld\n",m);

    }
    return 0;
}

