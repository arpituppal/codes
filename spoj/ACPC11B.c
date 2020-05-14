#include<stdio.h>
#include<math.h>
int main()
{
long long int t,x,n,m;
long long int a[1000],b[1000];
scanf("%lld",&t);
for(x=1;x<=t;x++)
{
long long int i,j,d,f;
scanf("%lld",&n);
for(i=0;i<n;i++)
scanf("%lld",&a[i]);
scanf("%lld",&m);
for(i=0;i<m;i++)
scanf("%lld",&b[i]);
f=abs(a[0]-b[0]);
for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {

        d=abs(a[i]-b[j]);
        if(d<f)
            f=d;
    }
}
printf("%lld\n",f);
}
return 0;
}
