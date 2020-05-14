#include<stdio.h>
long long int power(long long int a1)
{
    long long int k=2;
    while(k<a1)
    k=k*2;
    return k;
 }
int main()
{
    while(1)
    {
        long long int g,t,a,d,y,x=0,adv,total,k1,ans;
        scanf("%lld %lld %lld %lld",&g,&t,&a,&d);
        if(g==-1 && t==-1 && a==-1 && d==-1)
        break;
        x=(g*t*(t-1))/2; //no of group stage match
        adv=g*a+d;
        if(adv==1)
        {
            ans=x;
            y=0;
        }
        //total teams in knockout
        else
        {
        k1=power(adv);
        if(k1==adv)       //if power of 2
        y=0;
        else
        y=(k1-adv); //total teams required more
        total=adv+y;    //total teams in knockout
     //   printf("Grp match=%d team adv=%d y=%d total=%d\n",x,adv,y,total);
        while(total!=1)
        {
            total/=2;
            x+=total;   //no of matches in knockouts stages
        }
        ans=x;
    }
        printf("%lld*%lld/%lld+%lld=%lld+%lld\n",g,a,t,d,ans,y);
    }
    return 0;
 }
