#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
long long int t,x;
scanf("%lld",&t);
printf("\n");
for(x=1;x<=t;x++)
{
long long int i=0,j;
long long int s=1,f=0,d;
char n[40];
scanf("%s",n);
printf("\n");
d=strlen(n);
for(j=1;j<d;j++)
{
    if((n[j]-48)==(n[j-1]-48))
      f++;
   else
    {
        s=s*pow(2,f);
        f=0;
    }
   if(j==d-1)
    s=s*pow(2,f);
}
if(s==1)
printf("1\n");
else
printf("%lld\n",s);
printf("\n");
}
return 0;
}
