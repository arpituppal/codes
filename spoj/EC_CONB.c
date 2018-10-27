#include<stdio.h>
#include<math.h>
int s[10000000],s1[1000000];
int main()
{
  long long int n,i;
  scanf("%lld",&n);
  for(i=0;i<n;i++)
  {
     long long int a,f,ans,j,k,rem;
     scanf("%lld",&a);
     if(a%2==1)
     s[i]=a;
     else if(a%2==0)
     {
        ans=0,f=0,j=0;
        while(a>0)
        {
        rem=a%2;
        a=a/2;
        s1[j++]=rem;
        }
        for(k=j-1;k>=0;k--)
            ans+=s1[k]*pow(2,f++);
            s[i]=ans;
    }

 }
 for(i=0;i<n;i++)
 printf("%lld\n",s[i]);
 return 0;
 }
