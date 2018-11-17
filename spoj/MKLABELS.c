#include<stdio.h>
#include<math.h>
int main()
{
  long long int n,x=0,m;
  while(1)
  {
    x++;
    scanf("%lld",&n);
    if(n==0)
     break;
    if(n==1)
      m=1;
    if(n>1)
     m=pow(n,(n-2));
    printf("Case %lld, N = %lld, # of different labelings = %lld\n",x,n,m);
    }
    return 0;
    }
