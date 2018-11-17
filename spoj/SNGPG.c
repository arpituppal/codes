#include<stdio.h>
int n[100001];
int main()
{
    n[0]=1;
    n[1]=2;
    n[2]=3;
    n[3]=4;
    int i,t;
    for(i=4;i<100001;i++)
    n[i]=n[i-1];
    scanf("%d",&t);
    while(t--)
    {
         int a,b;
         scanf("%d %d",&a,&b);
         if(a==0)
         printf("%d\n",n[b]);
         else
         printf("%d\n",n[b]-n[a-1]);
    }
     return 0;
}
