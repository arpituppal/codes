#include<stdio.h>

int main()
{
int t;
long long unsigned int n;
scanf("%d",&t);
while(t--)
{
scanf("%llu",&n);
double ans;
ans = (3.0/4.0) + (1.0/(2*(n+2)))-(1.0/(2*(n+1)));
printf("%.11f\n",ans);
}
return 0;
}
