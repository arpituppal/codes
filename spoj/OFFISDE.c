#include<stdio.h>
int main()
{
int a,d,i,j,t,t1;
while(1)
{
scanf("%d %d",&a,&d);
if(a==0 && d==0)
break;
int b[a];
int c[d];
for(i=0;i<a;i++)
scanf("%d",&b[i]);
for(i=0;i<d;i++)
scanf("%d",&c[i]);
for(i=0;i<a;i++)
{
for(j=0;j<a-(i+1);j++)
{
if(b[j]>b[j+1])
{
t=b[j];
b[j]=b[j+1];
b[j+1]=t;
}}}

for(i=0;i<d;i++)
{
for(j=0;j<d-(i+1);j++)
{
if(c[j]>c[j+1])
{
t1=c[j];
c[j]=c[j+1];
c[j+1]=t1;
}}}
int f=0;
if(b[0]==c[1])
f=1;
else if(b[0]==c[0]&& b[0]==c[1])
f=1;
else if(c[0]<b[0] && c[1]<b[0])
f=1;
if(f==1)
printf("N\n");
else
printf("Y\n");
}
return 0;
}
