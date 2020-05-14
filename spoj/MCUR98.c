#include<stdio.h>
int a[10000000];
int main()
{
    long int sum,i,n;
    for(i=1;i<1000000;i++)
    {
        
        sum=0;
        n=i;
        if(a[i]==0)
        printf("%ld\n",i);
        while(n>0)
        {
            sum=sum+(n%10);
            n=n/10;
        }
        sum=sum+i;
        if(sum<1000000)
        a[sum]=1;
     }
    return 0;
    }
