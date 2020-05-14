#include<stdio.h>
#define N 10000000
long long int a[N],b[N];
int main()
{
    a[0]=0;
    a[1]=0;
    long long int i,j,s=0;
    for(i=2;i*i<N;i++)
    {
        if(a[i]==0)
        {
          for(j=i*i;j<=N;j+=i)
          {
                if(a[j]==0)
            	a[j]=i;
           }
        }
         if(a[i]==0)
         a[i]=i;
        s+=a[i];
        b[i]=s;
    }
    for(;i<=N;i++)
    {
      if(a[i]==0)
      a[i]=i;
      s+=a[i];
      b[i]=s;
    }
    int t,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
         long long int n;
         scanf("%lld",&n);
         printf("%lld\n",b[n]);
     }
     return 0;
    }
