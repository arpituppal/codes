#include<stdio.h>
int main()
{
        int t,n,i;
        scanf("%d",&t);
        while(t--)
        {
             scanf("%d",&n);
             double res = 0;
                for(i=1;i<=n;i++)
                        res +=n/(double)i;
                printf("%.2f\n", res);
        }
  return 0;
}
