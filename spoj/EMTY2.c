#include<stdio.h>
int stk[120001];
char s[120001];
int main()
{
    int t,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        int i=0,top=-1;
        scanf("%s",s);
        while(s[i]!='\0')
        {
           stk[++top]=(s[i]-48);
            if(top>=2)
            {
                if(stk[top-2]==1 && stk[top-1]==0 && stk[top]==0)
                top=top-3;
                //printf("top=%d\n",top);
            }
            i++;
        }
        if(top==-1)
            printf("Case %d: yes\n",x);
        else
            printf("Case %d: no\n",x);
    }
    return 0;
}
