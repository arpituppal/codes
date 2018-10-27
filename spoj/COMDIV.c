#include<stdio.h>
long long int gcd(int x,int y)
{
  if(x<y)
  return gcd(y,x);
  if(y==0)
  return x;
  else
  return gcd(y,x%y);
 }
int main()
{
   long long int t,x;
   scanf("%lld",&t);
   for(x=1;x<=t;x++)
   {
      long long int a,b,h,i,c=0;
      scanf("%lld %lld",&a,&b);
      h=gcd(a,b);
      for(i=1;i*i<=h;i++)
      {
         if(h%i==0)
         c++;
      }
      i--;
      if(i*i==h)
      printf("%lld\n",((2*c)-1));
      else
      printf("%lld\n",(2*c));
    }
    return 0;
  }
