#include<stdio.h>
int main()
{
    long long int q,i,j,m=0,n=0;
    scanf("%lld",&q);
    int f=0;
    if(q<=3)
    {
        printf("ANNE\n");
        return 0;
    }
    i=2;
    /*TRAIL DIVISION */
    while(i*i<=q)
    {
        j=0;
        if(q%i==0)
        {
            while(q%i==0)
            {
                q/=i;
                j++;
            }
            if(j>2)
            {
                f=1;
                break;
            }
            else
            m++;
            if(j==2)
            n=1;
            if(m>2)
            {
                f=1;
                break;
            }
            if(m==2 && n==1)
            {
                f=1;
                break;
            }
        }
        i++;
    }
    if(q>1)
    {
        m++;
        if(m>2)
        f=1;
        if(m==2 && n==1)
        f=1;
    }
    if(f==1 || m==1)
    printf("ANNE\n");
    else
    printf("MARIAN\n");
    return 0;
    }
