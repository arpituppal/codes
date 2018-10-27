#include<stdio.h>
int main()
{
long long int t,n,x,y;
long long int i,z,k;
scanf("%lld",&t);
for(i=1;i<=t;i++)
{
long long int s=0;
scanf("%lld",&n);
long long int a[n];
long long int b[n];
for(z=0;z<n;z++)
{
scanf("%lld",&x);
a[z]=x;
}
for(z=0;z<n;z++)
{
    scanf("%lld",&y);
    b[z]=y;
}
long long int l,v;
for(z=0;z<n;z++)
{
for(k=0;k<n-(z+1);k++)
{
if(a[k]>a[k+1])
{
l=a[k];
a[k]=a[k+1];
a[k+1]=l;
}
if(b[k]>b[k+1])
{
v=b[k];
b[k]=b[k+1];
b[k+1]=v;
}}}
for(z=0;z<n;z++)
s=s+(a[z]*b[z]);
printf("%lld\n",s);
}
return 0;
}
