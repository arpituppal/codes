#include<stdio.h>
char s[1000000];
int main()
{
    int x=0;
    while(scanf("%s",s)!=EOF)
    {
        x++;
        int i,flag=0;
        long long int ans=0;
        for(i=0;s[i]!='\0';i++)
        {
            if(flag==1)
            s[i]=(s[i]=='0'?'1':'0');
            if(s[i]=='1')
            {
                ans++;
                flag=(flag==0?1:0);
            }
        }
        printf("Game #%d: %lld\n",x,ans);
    }
    return 0;
}
