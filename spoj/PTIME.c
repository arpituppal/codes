#include<stdio.h>
#define N 10001
int a[N],b[N];
int fact(int n,int p)
{
    int q=p,ans=0,div;
    if(n<p)
    return 0;
 //   if(p>n/2)
   // return 1;
     while(1)
    {
        div=n/q;
         if(div<1)
        break;
         ans+=div;
         q=p*q;

    }
      return ans;
 }
 int main()
 {
     int m,i,j,k=0,t;
     for(i=2;i*i<N;i++)
     {
         if(a[i]==0)
         {
             for(j=i*i;j<=N;j+=i)
             {
                 if(a[j]==0)
                 a[j]=1;
             }
             b[k++]=i;
          }
      }
       for(;i<N;i++)
      {
      	if(a[i]==0)
      	b[k++]=i;
      
      }
  while(scanf("%d",&m)!=EOF)
     {
          int f=0;
         for(i=0;i<k;i++)
         {
              if(b[i]>m)
              break;
              if(b[i]<=m)
              t=fact(m,b[i]);
              if(t!=0)
                f++;
              if(t!=0 & f==1)
              printf("%d^%d",b[i],t);
              if(t!=0 && f>1)
                printf(" * %d^%d",b[i],t);
          }
         printf("\n");
     }
     return 0;
 }
