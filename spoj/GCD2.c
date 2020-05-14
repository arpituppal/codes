#include<stdio.h>
char b[300];
int remainder(int a)
{
    int i,rem=0;
    for(i=0;b[i]!='\0';i++)
        rem=((b[i]-48)+rem*10)%a;
    return rem;
}
int gcd(int a,int rem)
{
    if(a<rem)
    return gcd(rem,a);
    if(rem==0)
    return a;
    else
    return gcd(rem,a%rem);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,rem;
        scanf("%d",&a);
        scanf("%s",b);
        if(a==0)
        printf("%s\n",b);
        else
        {
            rem=remainder(a);
            printf("%d\n",gcd(a,rem));
        }
    }
    return 0;
}
