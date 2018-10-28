#include<stdio.h>
int main()
{
long long int t,n;
long long int i,x;
scanf("%lld",&t);
for(i=1;i<=t;i++)
{
long long int s=0;
long long int a,m,b,c;
printf("\n");
scanf("%lld",&n);
m=(n-1)/2;
b=2+((m-1)*2);
s=(m*b)/2;
a=s%n;
printf("%lld\n",a);
}
return 0;
}
