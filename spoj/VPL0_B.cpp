#include<stdio.h>
#include<algorithm>
int main()
{
    int a[100000],b[100000];
    int t,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {   
        int n,u,i,m,max=0,k=0,j=1,copy,len=0;
        scanf("%d %d",&n,&u);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        std::sort(a,a+n);
        m=a[n-1]/u;
        while(m>0)
        {   
            max++;
            m/=10;
        }
        b[0]=a[0]/u;
        printf("Scenario #%d:\n\n",x);
        for(i=0;i<n;i++)
        {   
            
            if(a[i]/u==b[0])
            b[j++]=a[i]%u;
            else
            {   len=0;
                copy=b[0];
                while(copy>0)
                {   
                    len++;
                    copy/=10;
                }
                if(b[0]==0)
                len=1;
                for(k=1;k<=(max-len);k++)
                printf(" ");
                printf("%d | ",b[0]);
                for(k=1;k<j;k++)
                printf("%d ",b[k]);
                j=2;
                b[0]=a[i]/u;
                b[1]=a[i]%u;
                printf("\n");
            }
        }
                len=0;
                copy=b[0];
                while(copy>0)
                {   
                    len++;
                    copy/=10;
                }
                for(k=1;k<=(max-len);k++)
                printf(" ");
                printf("%d | ",b[0]);
                for(k=1;k<j;k++)
                printf("%d ",b[k]);
        printf("\n\n");
    }
    return 0;
}