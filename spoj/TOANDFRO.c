#include<stdio.h>
#include<string.h>
int main()
{
int n,t,d,i,j;
char a[200];
while(1)
{
t=0,d=0;
int x=0;
scanf("%d",&n);
if(n==0)
break;
scanf("%s",a);
d=strlen(a);
t=d/n;
char b[t][n];
for(i=0;i<t;i++)
{
if(i%2==0)
{
for(j=0;j<n;j++)
b[i][j]=a[x++];
}
else
{
for(j=n-1;j>=0;j--)
    b[i][j]=a[x++];
}}
int k=0,l=0;
while(l<n)
{
    if(k==t)
    {
  k=0;
  l=l+1;
    }
    else
    {
     printf("%c",b[k++][l]);
    }
}
printf("\n");
}
return 0;
}
