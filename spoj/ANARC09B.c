#include<stdio.h>
int main()
{
long long int n,m;
while(1)
{
long long int i=2,s=1,z;
scanf("%lld %lld",&n,&m);
if(n==0 && m==0)
break;
long long int a=n,b=m;
while(i<=n*m)
{
if(n%i==0 && m%i==0)
{
s=s*i;
n=n/i;
m=m/i;
}
else if(n%i==0&& m%i!=0)
{
s=s*i;
n=n/i;
}
else if(n%i!=0&& m%i==0)
{
s=s*i;
m=m/i;
}
if(n%i!=0 && m%i!=0)
i++;
}
z=(s/a)*(s/b);
printf("%lld\n",z);
}
return 0;
}
