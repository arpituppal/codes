#include<stdio.h>
long long int hcf(long long int,long long int);
int main()
{
    int t,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
     long long int n,i,f;
     int flag=0;
     scanf("%lld",&n);
     for(i=n/2;i>0;i--)
     {
       f=hcf(n,i);
      if(f==1)
       {
        printf("%lld\n",i);
        break;
        }
    }
    }
    return 0;
    }
    long long int hcf(long long int a,long long int b)
    {
        if(a<b)
            return hcf(b,a);
     if(b==0)
      return a;
      else
      return hcf(b,a%b);
      }
