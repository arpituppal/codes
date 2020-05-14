#include<stdio.h>
#include<math.h>
int main()
{
   long long int n,x;
   scanf("%lld",&n);
   for(x=1;x<=n;x++)
   {
     int x,y,flag=0,ans=0;
     scanf("%d %d",&x,&y);
     if(x%2==0 && y%2==0 && abs(y-x)<=2)
      {
       ans=x+y;
       flag=1;
       }
      if(x%2!=0 && y%2!=0 && abs(y-x)<=2)
        {
          ans=(x+y)-1;
          flag=1;
          }
       if(y>x)
          flag=0;
      if(x%2!=0 && y%2==0)
           flag=0;
      if(x%2==0 && y%2!=0)
          flag=0;
     if(abs(x-y)>2)
        flag=0;
     if(flag==0)
        printf("No Number\n");
     else if(flag==1)
         printf("%d\n",ans);
        }
     return 0;
     }
