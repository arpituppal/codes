#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int s[1000000];
    while(t--)
    {
        long long int n,res,ans,i,k=0;
        scanf("%lld",&n);
        while(n>0)
        {
            res=n%2;
            if(res==0)
            n=(n/2)-1;
            else
            n=n/2;
            switch(res)
            {
                case 0: s[k++]=6;
                        break;
                case 1: s[k++]=5;
                        break;
            }
        }
         for(i=k-1;i>=0;i--)
         printf("%d",s[i]);
         printf("\n");
        }
        return 0;
    }
