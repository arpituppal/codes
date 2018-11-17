#include<stdio.h>
#define min(a1,b1) a1<b1?a1:b1
int inp[110][110],ans[110][110];
int minimum(int a,int b,int c)
{
    if(a<=b && a<=c)
    return a;
    if(b<=a && b<=c)
    return b;
    if(c<=a && c<=b)
    return c;
}
int main()
{

        int n,m,i,j,min1=1000000;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            scanf("%d",&inp[i][j]);
        }
        for(i=0;i<n;i++)
        ans[0][i]=inp[0][i];
        for(i=1;i<n;i++)
        {
            ans[i][0]=min((inp[i][0]+ans[i-1][0]),(inp[i][0]+ans[i-1][1]));
            for(j=1;j<m-1;j++)
            ans[i][j]=minimum((inp[i][j]+ans[i-1][j]),(inp[i][j]+ans[i-1][j-1]),(inp[i][j]+ans[i-1][j+1]));
            ans[i][m-1]=min((inp[i][m-1]+ans[i-1][m-1]),(inp[i][m-1]+ans[i-1][m-2]));
        }
        for(i=0;i<m;i++)
        {
            if(ans[n-1][i]<min1)
            min1=ans[n-1][i];
        }
        printf("%d\n",min1);
        return 0;
}
