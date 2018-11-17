#include<stdio.h>
int top[10000000],bottom[10000000];
int main()
{
    int n,i,u,v,ans,half,min=1000000,flag=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        top[u]++;
        bottom[v]++;
    }
    if(n%2==0)
        half=n/2;
    else
        half=(n/2)+1;
    for(i=0;i<1000000;i++)
    {
        if(top[i]>=half)
        {
            printf("0\n");
            return 0;
       }
    }
    for(i=0;i<1000000;i++)
    {
        if(bottom[i]+top[i]>=half)
        {
            flag=1;
            ans=(half-top[i]);
            if(ans<min)
            min=ans;
        }
   }
   if(flag==0)
   printf("Impossible\n");
   else
   printf("%d\n",min);
   return 0;
}
