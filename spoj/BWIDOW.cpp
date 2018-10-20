#include<stdio.h>
int a[1000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,max=-1,pos=0,x,flag=0;
        scanf("%d",&n);
        for(x=0;x<n;x++)
        {
          int r,R;
          scanf("%d %d",&r,&a[x]);
          if(r>max)
          {
              max=r;
              pos=x;
          }
        }
        for(x=0;x<n;x++)
        {
           if(max<a[x] && x!=pos)
           {
              flag=1;
              printf("-1\n");
              break;
           }
        }
        if(flag==0)
        printf("%d\n",(pos+1));
    }
    return 0;
 }
