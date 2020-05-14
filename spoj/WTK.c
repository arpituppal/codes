#include<stdio.h>
long long int answer(long long int n,long long int k)
{

    if(n==1)
        return 1;
    else
        return ((answer(n-1,k+1)+k-1)%n)+1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       long long int n,k=1,i=2,r=0;
        scanf("%lld",&n);
        long long int ans=answer(n,1);
         printf("%d\n",(ans));
    }
    return 0;
 }
