#include<stdio.h>
int main()
{
long long int t,n,x;
scanf("%lld",&t);
for(x=1;x<=t;x++)
{
scanf("%lld",&n);
long long int d,b;
b=n/2;
if(n%2==0)
d=b;
else
d=b+1;
printf("%lld\n",d);
}
return 0;
}
