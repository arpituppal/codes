#include<stdio.h>
int main()
{
int t,x,i;
long long unsigned int n,m;
scanf("%d",&t);
for(x=1;x<=t;x++)
{
long long unsigned int z=0;
printf("\n");
scanf("%llu",&n);
for(i=1;i<=n;i++)
{
scanf("%llu",&m);
z=z+m;
z=z%n;
}
if(z==0)
printf("YES\n");
else
printf("NO\n");
}
return 0;
}
