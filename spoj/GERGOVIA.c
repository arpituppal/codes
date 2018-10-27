#include<stdio.h>
int main()
{
long long int n,x,m;
while(1)
{
long long int a=0,s=0;
scanf("%lld",&n);
if(n==0)
break;
for(x=1;x<=n;x++)
{
scanf("%lld",&m);
a=a+m;
if(a>0)
s=s+a;
else
s=s-a;
}
printf("%lld\n",s);
}
return 0;
}
