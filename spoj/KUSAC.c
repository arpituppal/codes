#include<stdio.h>
int gcd(int a,int b)
{
if(a<b)
return gcd(b,a);
if(b==0)
return a;
else
return gcd(b,a%b);
}
int main()
{
    int n,m,h;
    scanf("%d %d",&n,&m);
    if(n>m && n%m==0)
    printf("0\n");
    else
    {
        h=gcd(n,m);
        printf("%d\n",(m-h));
    }
return 0;
}
