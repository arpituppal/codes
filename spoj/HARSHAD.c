#include<stdio.h>
#define M 1000000
int b[M],m[M];
int main()
{
  
    b[0]=1;
    m[0]=0;
    long long int i,j,k,sum=0;
    int t,x,f=0;
     
  
    for(i=1;i<=M;i++)
    {
       k=i;
       sum=i;
       while(k>0)
       {
            sum+=k%10;
            k=k/10;
       }
       if(sum<=M)
       b[sum]=1;
    }
      int a[M]={0};
      a[0]=1;
      a[1]=1;
      

      for(i=2;i*i<M;i++)
    {
        if(a[i]==0)
         {
            for(j=i*i;j<M;j+=i)
            a[j]=1;
         }
    }
     for(j=1;j<=M;j++)
     {
        if(a[j]==0 && b[j]==0)
        ++f;
        m[j]=f;
     }
     scanf("%d",&t);
     for(x=1;x<=t;x++)
     {
        int d,e;
        scanf("%d %d",&d,&e);
        if(a[d]==0 && b[d]==0)
        printf("%d\n\n",((m[e]-m[d])+1));
        else
        printf("%d\n\n",(m[e]-m[d]));
      }
      return 0;
    }
