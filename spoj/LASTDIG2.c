#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
long long int t,x,i;
scanf("%lld",&t);
 for(x=1;x<=t;x++)
 {
char a[10001];
long long unsigned int b;
    scanf("%s",a);
    scanf("%llu",&b);
    long long unsigned int p,m,s,n,r;
    int f=0;
    r=b%4;
    for(i=0;i<(strlen(a));i++)
    {
    if(a[i]!='0')
        f=1;
    }
    if(f==0)
    p=0;
        else
    {
      if(b==0)
        p=1;
      if(b!=0)
      {
       n=(int)a[(strlen(a)-1)];
       m=n-48;
       if(r==0)
        p=pow(m,4);
       else
        p=pow(m,r);
    }
    }
        s=p%10;
        printf("%llu\n",s);
 }
 return 0;
}
