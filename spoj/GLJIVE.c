#include<stdio.h>
#include<math.h>
int main()
{
int a[10],s=0,sum=0,b=100,d=0,i;
for(i=0;i<10;i++)
scanf("%d",&a[i]);
for(i=0;i<10;i++)
{
s=s+a[i];
if(sum==100)
break;
else
d=abs(100-s);
if(d<=b)
{
sum=s;
b=d;
}
else
break;
}
printf("%d",sum);
return 0;
}
