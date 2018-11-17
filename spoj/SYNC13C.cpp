#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int c1,c2;
        scanf("%d %d",&c1,&c2);
        if(c1%2==1 && c2%2==1)
        printf("Ramesh\n");
        else
        printf("Suresh\n");
    }
 return 0;
 }
