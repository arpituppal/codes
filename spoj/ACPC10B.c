#include<stdio.h>
#include<stdlib.h>
#define min(a,b) ((a >= b) ? (b) : (a))
#define INF 1000000000
int graph[100010][3];
int main()
{
    int n,x=0;
    while(1)
    {
        int i,j,ans1,ans2,ans,right,down,pdiag,sdiag;
        scanf("%d",&n);
        x++;
        if(n==0)
            break;
        for(i=0;i<n;i++)
            for(j=0;j<3;j++)
                scanf("%d",&graph[i][j]);
        graph[0][0]=INF;
        graph[0][2]=graph[0][1]+graph[0][2];
        for(i=1;i<n;i++)
        {
            for(j=0;j<3;j++)
            {
                right=(j==0)?INF:graph[i][j-1];
                down=graph[i-1][j];
                pdiag=(j==0)?INF:graph[i-1][j-1];
                sdiag=(j==2)?INF:graph[i-1][j+1];
                ans1=(min(right,down));
                ans2=(min(pdiag,sdiag));
                ans=(min(ans1,ans2));
                graph[i][j]+=ans;
            }
        }
        printf("%d. %d\n",x,graph[n-1][1]);
    }
    return 0;
}
