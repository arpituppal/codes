#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,a;
        long long int b;
        scanf("%d",&n);
        n=n-1;
        if(n==0)
        printf("poor conductor\n");
        else
        {
            a=n/5;
            if(n%5!=0)
            a=a+1;
            b=(5*a)-n;
            if(a%2==0)
            {
                if(b==0)
                printf("%d W L\n",a);
                if(b==1)
                printf("%d A L\n",a);
                if(b==2)
                printf("%d A R\n",a);
                if(b==3)
                printf("%d M R\n",a);
                if(b==4)
                printf("%d W R\n",a);
            }
            else
            {
                if(b==4)
                printf("%d W L\n",a);
                if(b==3)
                printf("%d A L\n",a);
                if(b==2)
                printf("%d A R\n",a);
                if(b==1)
                printf("%d M R\n",a);
                if(b==0)
                printf("%d W R\n",a);
            }
        }
    }
    return 0;
}
