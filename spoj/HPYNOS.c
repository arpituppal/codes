#include<stdio.h>
int happy(long long int);
int f=0;
int main()
{
     long long int n;
     int d;
     scanf("%lld",&n);
     d=happy(n);
    printf("%d\n",d);
    return 0;
}
    int happy(long long int a)
     {
        long long int sum=0,t;
        while(a>0)
        {
            t=a%10;
           sum=sum+(t*t);
            a=a/10;
        }
        f++;
        if(sum==145)
        return -1;
        else if(sum==1)
        return f;
        else
        return happy(sum);
     }
