#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,m,max=-1,f=0,flag=0,freq=0;
        long long int min=10000000000;
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
     printf("-1\n");
     else
     {
         if(f==n)
         printf("0\n");
         else
         {
             if(min==max)
             printf("%d\n",n);
             else
            {
                if(max!=(min+1))
                printf("-1\n");
                else if(freq==(n-max))
                printf("%d\n",max);
                else
                    printf("-1\n");
            }
       }
    }
}
    return 0;
}
