#include<stdio.h>
int main()
{
    while(1)
    {
        int n,m;
        scanf("%d",&n);
        if(n==0)
        break;
        m=((n)*(n+1)*((2*n)+1))/6;
        printf("%d\n",m);
     }
     return 0;
  }
