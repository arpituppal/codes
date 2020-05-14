#include<stdio.h>
#include<string.h>
int main()
{
long long int t,x;
scanf("%lld",&t);
for(x=1;x<=t;x++)
{
char a[50010];
long long int l,i,j,s=0,f=0,k=0,sum=0,d,r,z;
scanf("%s",a);
l=strlen(a);
for(i=0;i<l;i++)
s=s+(a[i]-48);
if(l<3)
{
f=0;
k=0;
}
else if(l>=3)
{
       d=(a[0]-48);
       for(j=0;j<l-1;j++)
        {
         sum=(d*3)+(a[j+1]-48);
         d=sum%7;
        }
        if(d!=0)
        {
        f=0;
        k=0;
        }
        else if(d==0)
        {
        if(s%9==0)
        {
        r=(((a[l-2]-48)*10)+(a[l-1]-48));
            if(r%4==0)
            f=1;
           }
        if(s%3==0)
        {
        z=((a[l-2]-48)*10)+(a[l-1]-48);
        if(z%25==0)
        k=1;
        }
        }
     }
     if(f==0 && k==0)
     printf("No No\n");
     if(f==1 && k== 0)
     printf("Yes No\n");
     if(f==0 && k==1)
     printf("No Yes\n");
     if(f==1 && k==1)
     printf("Yes Yes\n");
     }
     return 0;
     }