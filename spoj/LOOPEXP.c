#include<stdio.h>
double arr[100010];
int main()
{
    int i,t;
    arr[1]=1;
    for(i=2;i<=100010;i++)
      arr[i]=arr[i-1]+1.0/i;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%.15lf\n",arr[n]);
    }
    return 0;
}
