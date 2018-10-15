#include<stdio.h>
int main()
{
long long int t,g,m,sg,sm;
long long int i,x;
scanf("%lld",&t);
for(i=1;i<=t;i++)
{
    long long int max1=0,max2=0;
    printf("\n");
    scanf("%lld%lld",&g,&m);
    for(x=1;x<=g;x++)
    {
        scanf("%lld",&sg);
        if(sg>max1)
        max1=sg;
    }
    for(x=1;x<=m;x++)
    {
        scanf("%lld",&sm);
        if(sm>max2)
            max2=sm;
    }
    if(max1>=max2)
        printf("Godzilla\n");
    else
        printf("MechaGodzilla\n");
}
return 0;
}
