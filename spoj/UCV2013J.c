#include<stdio.h>
int main()
{
   long long int n;
   while(1)
   {
     scanf("%lld",&n);
     if(n==0)
     break;
     long long int i,v,s=0;
     for(i=0;i<n;i++)
     {
       scanf("%lld",&v);
       if(i>=n/2)
       s=s+v;
    }
    printf("%lld\n",s);
}
 return 0;
 }
