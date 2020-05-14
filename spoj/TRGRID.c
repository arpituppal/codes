#include<stdio.h>
int main()
{
long long int t,x;
scanf("%lld",&t);
for(x=1;x<=t;x++)
{
long long int n,m;
scanf("%lld %lld",&n,&m);
if(n==m)
{
if(n%2==0)
printf("L\n");
else
printf("R\n");
}
if(n!=m)
{
if(n>m)
{
if(m%2==0)
printf("U\n");
if(m%2==1)
printf("D\n");
}
if(m>n)
{
if(n%2==0)
printf("L\n");
if(n%2==1)
printf("R\n");
}}
}
return 0;
}
