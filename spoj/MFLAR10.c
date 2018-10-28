#include<stdio.h>
#include<string.h>
int main()
{
char a[2000]; int i;
while(1)
{
int f=1;
gets(a);
if(strlen(a)==1 && a[0]=='*')
break;
int b=a[0];
if(b>=97)
b=b-32;
for(i=1;i<strlen(a);i++)
{
if(a[i]==32)
{
int c=a[i+1];
if(c>=97)
c=c-32;
if(c!=b )
{
f=0;
break;
}}}
if(f==1)
printf("Y\n");
else
printf("N\n");
}
return 0;
}
