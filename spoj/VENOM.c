#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int ans=0;
        int h,p,a;
        scanf("%d %d %d",&h,&p,&a);
        if(h<=p)
        {
            printf("1\n");
            continue;
        }
        double y=(p-2*a);
        double z=2*(a-h);
        double root=sqrt(y*y-4*p*z);
        ans=ceil((-1*y+root)/(2*p));
        ans=ans+(ans-1);
        printf("%lld\n",ans);
    }
    return 0;
}
