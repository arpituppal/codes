#include<stdio.h>
int main()
{
long long int t,i,j,n,m,x;
scanf("%lld",&t);
for(x=1;x<=t;x++)
{
long long int sum=0;
scanf("%lld%lld",&n,&m);
long long int a[m];
for(i=0;i<m;i++)
scanf("%lld",&a[i]);
long long int z;
for(i=0;i<m;i++)
{
for(j=0;j<m-(i+1);j++)
{
if(a[j]<a[j+1])
{
z=a[j];
a[j]=a[j+1];
a[j+1]=z;
}}}
long long int k=0,f=0;
for(k=0;k<m;k++)
{
    sum=sum+a[k];
    f++;
 if(sum>=n)
        break;
}
if(sum<n)
printf("Scenario #%lld:\nimpossible\n",x);
else
printf("Scenario #%lld:\n%lld\n",x,f);
printf("\n");
}
return 0;
}


