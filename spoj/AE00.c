#include<stdio.h>
int main()
{
  int n,i,j,f,d;
  scanf("%d",&n);
  f=1;
  for(i=2;i<=n;i++)
  {
    d=0;
    for(j=1;j<=i/2;j++)
    {
      if((i%j==0)&& (j!=d))
      {

      d=i/j;
      f++;
    }
    if(j==d)
        break;
    }
  }
    printf("%d\n",f);
    return 0;
    }
