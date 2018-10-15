#include<stdio.h>
#include<string.h>
int l,dp[50][300];
char s[100];
int solve(int curr,int prev)
{
       int i,sum=0;
       if(curr==l)
       return 1;
      // int res=dp[curr][prev];
       //if(res!=-1)
       //return res;
       int res=0;
       for(i=curr;i<l;i++)
       {
            sum+=s[i]-48;
            if(sum>=prev)
            res+=solve(i+1,sum);
        }
    return res;

}
int main()
{
    int t,x=0;
    while(1)
    {
        x++;
        scanf("%s",s);
        if(s[0]=='b')
        break;
      //  memset(dp,-1,sizeof(dp));
        l=strlen(s);
        int ans=solve(0,0);
        printf("%d. %d\n",x,ans);
    }
    return 0;
}
