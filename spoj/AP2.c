#include<stdio.h>
int main()
{
long long int t,x;
scanf("%lld",&t);
for(x=1;x<=t;x++)
{
long long int b,m,s,n,a,d,i;
scanf("%lld %lld %lld",&b,&m,&s);
n=(2*s)/(b+m);
d=(m-b)/(n-5);
a=b-(2*d);
printf("%lld\n",n);
for(i=0;i<n;i++)
printf("%lld ",(a+(i*d)));
printf("\n");
}
return 0;
}
