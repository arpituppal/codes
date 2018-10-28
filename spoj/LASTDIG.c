#include<stdio.h>
#include<math.h>
int main()
{
long long int t,x;
long long int b,a;
scanf("%lld",&t);
for(x=1;x<=t;x++)
{
long long int p,s,r;
scanf("%lld %lld",&a,&b);
r=b%4;
if(b==0)
p=1;
if(b!=0 && r==0)
 p=pow(a,4);
 if(b!=0 && r!=0)
p=pow(a,r);
s=p%10;
printf("%lld\n",s);
}
return 0;
}
