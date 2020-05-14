#include<stdio.h>
#define N 100000
int a[N],b[N];
int main()
{
  int i,j,k=0,t;
  for(i=2;i<N;i++)
  {
      if(a[i]==0)
      {
         for(j=2*i;j<=N;j+=i)
         a[j]++;
      }
    if(a[i]>=3)
    b[k++]=i;
  }
   scanf("%d",&t);
   while(t--)
   {
        int n;
        scanf("%d",&n);
        printf("%d\n",b[n-1]);
    }
return 0;
}
