#include<stdio.h>
int main()
{
    int r,b,i,j,sum;
    scanf("%d %d",&r,&b);
    sum=r+b;
    for(i=3;i<=5000;i++)
    {
        for(j=i;j>=3;j--)
        {
            if(i*j==sum && r==2*i+2*j-4)
            printf("%d %d\n",i,j);
        }
    }
    return 0;
 }

