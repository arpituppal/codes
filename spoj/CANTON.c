#include<stdio.h>
#define N 10000000
int a[N],b[N];
int main()
{
    int t;
     int i,k=1,e=1,num=1,den=1;
    for(i=1;i<=N;i++)
    {
       if(k<=e)
       {
           k++;
           a[i-1]=num;
           b[i-1]=den;
           if(e%2==1)
           {
               num=num-1;
               den=den+1;
           }
           if(e%2==0)
           {
               num=num+1;
               den=den-1;
           }
       }
       if(k>e)
       {
            k=1;
            e=e+1;
            if(e%2==1)
             {
                 num=e;
                 den=1;
             }
           if(e%2==0)
           {
               den=e;
               num=1;
           }
       }
    }
     scanf("%d",&t);
     while(t--)
     {
         int m;
         scanf("%d",&m);
         printf("TERM %d IS %d/%d\n",m,a[m-1],b[m-1]);
     }
     return 0;
}
