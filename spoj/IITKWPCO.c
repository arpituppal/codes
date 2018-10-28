#include<stdio.h>
int main()
{
  int t,x;
  scanf("%d",&t);
  int a[1000000]={0};
  for(x=1;x<=t;x++)
  {
    int n,i,d,f=0,max=0;
    scanf("%d",&n);
    int m;
    for(i=0;i<n;i++)
    {
      scanf("%d",&m);
      a[m-1]++;
      if(m>max)
        max=m;
      }
      for(i=0;i<(max/2);i++)
      {
        d=(2*i)+1;
        while(a[i]>0)
        {
          if(a[d]>0)
          {
           f++;
           a[i]--;
           a[d]--;
           }
           else
           break;
           }
      a[i]=0;
           }
        for(i=(max/2);i<max;i++)
            a[i]=0;
           printf("%d\n",f);
        }
        return 0;
        }
