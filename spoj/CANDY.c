#include<stdio.h>
int main()
{
long long int n,m;
int x;
while(1)
{
scanf("%lld",&n);
if(n==-1)
break;
long long int s=0,z=0,b;
long long int a[n];
for(x=0;x<n;x++)
{
scanf("%lld",&m);
s=s+m;
a[x]=m;
}
b=s/n;
if(s%n==0)
{
for(x=0;x<n;x++)
{
    if(a[x]<b)
        z=z+(b-a[x]);
}
printf("%d\n",z);
}
else
    printf("-1\n");
}
return 0;
}