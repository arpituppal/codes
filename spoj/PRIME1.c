#include<stdio.h>
#define N 10000000
long long int a[N];
int main()
{
    int t,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
       long long int m,n,i,j;
       scanf("%lld %lld",&m,&n);
       for(i=2;i*i<n;i++)
       {
          for(j=(((m+i-1)/i)*i-m);j<=n-m;j+=i)
          {
             if((m+j)==i)
             continue;
             a[j]=1;
            }
        }
        for(i=0;i<=(n-m);i++)
        {
        	if(m+i==1)
        	continue;
           if(a[i]==0)
           printf("%lld\n",(i+m));
           else
           a[i]=0;
        }
        printf("\n");
    }
    return 0;
}
