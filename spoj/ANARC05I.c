#include<stdio.h>
#include<string.h>
char s[1001];
int visited[2002][2002];
int main()
{
    while(1)
    {
        int i,j,x=1001,y=1001,ans=0;
        scanf("%s",s);
        if(s[0]=='Q')
        break;
        for(i=0;i<2002;i++)
        {
            for(j=0;j<2002;j++)
            visited[i][j]=0;
        }
        for(i=0;s[i]!='Q';i++)
        {
            visited[x][y]=1;
            if(s[i]=='U')
            y+=1;
            if(s[i]=='D')
            y-=1;
            if(s[i]=='R')
            x+=1;
            if(s[i]=='L')
            x-=1;
            if(visited[x][y]==1)
            ans++;
            else
            visited[x][y]=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}

