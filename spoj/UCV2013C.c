#include<stdio.h>
int main()
{
    long long int d,f,b,m;
    while(1)
    {
        long long int fence,ans,spent;
        scanf("%lld %lld %lld %lld",&d,&f,&b,&m);
        if(d==0 && f==0 && b==0 && m==0)
        break;
        fence=f+2;
        fence=((fence-1)*(fence-2)/2)+1;
        spent=b*fence;
        if(d-spent>=m)
        printf("Farmer Cream will have %lld Bsf to spend.\n",d-spent);
        else
        {
            ans=d-spent;
            ans=m-ans;
            if(ans<0)
            ans=-1*ans;
            printf("The firm is trying to bankrupt Farmer Cream by %lld Bsf.\n",ans);
        }
    }
    return 0;
}
