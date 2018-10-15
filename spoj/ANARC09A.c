#include<stdio.h>
int main()
{
    char s[3000];
    int k=0;
    while(1)
    {
        int open=0,close=0,i=0,ans;
        scanf("%s",s);
        k++;
        if(s[0]=='-')
        break;
        while(s[i]!='\0')
        {
            if(s[i]=='{')
            open++;
            else
            {
                open--;
                if(open<0)
                {
                    open=1;
                    close++;
                }
            }
            i++;
        }
        ans=close+open/2;
        printf("%d. %d\n",k,ans);
        }
        return 0;
    }
