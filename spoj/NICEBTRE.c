#include<stdio.h>
#define MAX(a,b) ((a >= b) ? (a) : (b))
int i=0;
char s[100000];
int max(int a,int b)
{

    if(a>b)
        return a;
    else
        return b;
}
int depth()
{
    if(s[i++]=='l')
    return 1;
    else
    return max(depth(),depth())+1;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        i=0;
        scanf("%s",s);
        printf("%d\n",depth()-1);
    }
    return 0;
}
