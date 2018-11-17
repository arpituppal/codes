#include<stdio.h>
int main()
{
  int t,x;
  scanf("%d",&t);
  for(x=1;x<=t;x++)
  {
    int n,i,m,f=0,max=0;
    scanf("%d",&n);
    int a[200]={0};
    for(i=0;i<n;i++)
    {
     scanf("%d",&m);
     a[m]++;
     }
     for(i=0;i<200;i++)
     {
       if(a[i]>0 && (a[i]%i==0) && (a[i]>max))
       {
        max=a[i];
        f=i;
     }}
     if(f==0)
     printf("-1\n");
     else
     printf("%d\n",f);
     }
     return 0;
     }
