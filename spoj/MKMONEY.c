#include<stdio.h>
#include<math.h>
int main()
{
    double p,i;
    int c,f=0;
    while(1)
    {
        f++;
        double res,ans;
        int j;
        scanf("%lf %lf %d",&p,&i,&c);
        if(c==0)
        break;
        res=p;
        for(j=0;j<c;j++)
        {
            ans=floor((res*i/c));
            res+=ans/100;
        }
//        printf("p=%.2lf i=%.2lf c=%d res=%.2lf\n",p,i,c,res);
        printf("Case %d. $%.2lf at %.2lf%% APR compounded %d times yields $%.2lf\n",f,p,i,c,res);
    }
return 0;
}
