#include<stdio.h>
int main()
{
long int n,x;
long long unsigned int a,b;
scanf("%ld",&n);
for(x=1;x<=n;x++)
{
scanf("%llu %llu", &a,&b);
long long unsigned int r1=0,r2=0,sum,r3=0;
while(a>0)
{
r1=(r1*10)+(a%10);
a=a/10;
}
while(b>0)
{
r2=(r2*10)+(b%10);
b=b/10;
}
sum=r1+r2;
while(sum>0)
{
r3=(r3*10)+(sum%10);
sum=sum/10;
}
printf("%d\n",r3);
}
return 0;
}
