#include<stdio.h>
#include<math.h>
int main()
{
int t;
unsigned long long int n,m,ans,i,k;
scanf("%d",&t);
while(t--)
{
scanf("%llu %llu %llu",&n,&k,&m);
if(n>=m)
{
        printf("0\n");
        continue;
}
m=m/n;
//printf("%llu %llu %llu",n,k,m);
i=k;
ans=0;
while(1)
{
    //printf("%llu\n",i);
    if(i<=m)
    {
        i=i*k;
        ans++;
        
    }
    else
        break;
}
printf("%llu\n",ans);}
return 0;
}
