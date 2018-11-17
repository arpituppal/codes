#include<stdio.h>
#include<math.h>
long long int gcd(long long int a,int b)
{
if(a<b)
return gcd(b,a);
if(b==0)
return a;
else
return gcd(b,a%b);
}
int main()
{
   long long int t,x;
   scanf("%lld",&t);
   for(x=1;x<=t;x++)
   {
        long long int s1,s2,h,ans;
        int flag=0;
        scanf("%lld %lld",&s1,&s2);
        if(s1>0 && s2<0)
        {
           flag=1;
           s2=-s2;
         }
        else if(s1<0 && s2>0)
        {
           flag=1;
           s1=-s1;
        }
        else if(s1<0 && s2<0)
        {
            s1=-s1;
            s2=-s2;
        }
        h=gcd(s1,s2);
        s1=s1/h;
        s2=s2/h;
        if(flag==0)
        ans=abs(s1-s2);
        else if(flag==1)
        ans=s1+s2;
        printf("%lld\n",ans);
      }
      return 0;
     }
