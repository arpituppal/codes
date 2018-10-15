#include<stdio.h>
#include<string.h>
int main()
{
int t,x,i,j;
char a[11];
scanf("%d",&t);
for(x=1;x<=t;x++)
{
int f=1;
scanf("%s",a);
int l=strlen(a);
for(i=0,j=l-1;i<l/2;i++,j--)
{
if(a[i]!=a[j])
{

    f=0;
    break;
}}
if(f==1)
    printf("YES\n");
else
    printf("NO\n");
}
return 0;
}
