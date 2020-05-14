#include<stdio.h>
#define max(x,y) x>y?x:y
int knapsack(int W,int n)
{
    int i,j;
    int dp[n+1][W+1],wt[n+1],b[n+1];
    //dp[0][0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&wt[i],&b[i]);
        dp[i][0]=0;
    }
    for(j=0;j<=W;j++)
    dp[0][j]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=W;j++)
        {
            if(wt[i]>j)
            dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=(max(dp[i-1][j],(b[i]+dp[i-1][j-wt[i]])));
        }
    }
    return dp[n][W];
 }
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int W,n;
        scanf("%d %d",&W,&n);
        printf("Hey stupid robber, you can get %d.\n",knapsack(W,n));
    }
    return 0;
}    