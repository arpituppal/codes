#include<stdio.h>
int main()
{
    int n,i,m,min=100000,max=-1,f=0,flag=0,freq=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        if(m==0)
        f++;
        if(m<min)
        min=m;
        if(m>max)
        {
            max=m;
            freq=0;
        }
        if(m==max)
            freq++;
        if(m>=n)
        flag=1;
    }
    if(flag==1)
    printf("-1");
    else
    {
        if(f==n)
        printf("0");
        else
        {
            if(min==max)
            printf("%d",n);
            else
            {
                if(max!=(min+1))
                printf("-1");
                else if(freq==(n-max))
                printf("%d",max);
                else
                    printf("-1");
            }
       }
    }
    return 0;
}

