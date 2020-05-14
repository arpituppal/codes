#include<stdio.h>
#define N 1000000
int a[N],ans[N];
int main()
{
    int i,j,k=0,c=0,n;
    for(i=2;i<33810;i++)
    {
        c=0;
        if(k==3000)
        break;
       //printf("i=%d a[i]=%d\n",i,a[i]);
        if(a[i]==0)
        {
            ans[k++]=i;
            for(j=i+1;j<33810;j++)
            {

                if(a[j]==0)
                {
                  c++;
                //  printf("for i=%d j=%d a[j]=%d c=%d \n",i,j,a[j],c);
                }
                if(c==i)
                {

                    a[j]=1;
                    c=0;
                   // printf("\nYESS for j= %d a[j]=%d\n",j,a[j]);
                }
           }
        }
     }
     while(1)
     {
        scanf("%d",&n);
        if(n==0)
        break;
        printf("%d\n",ans[n-1]);
      }
      return 0;
    }
