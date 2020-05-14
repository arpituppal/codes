#include<stdio.h>
#define min(a,b) a<b?a:b
#define INF 1000000000
int graph[110][110],dist[110][110];
void floyd(int v)
{
	int i,j,k;
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		dist[i][j]=graph[i][j];
	}
	for(k=1;k<=v;k++)
	{
		for(i=1;i<=v;i++)
		{
			for(j=1;j<=v;j++)
              {
              	if(dist[i][k]+dist[k][j]<dist[i][j])
              		dist[i][j]=dist[i][k]+dist[k][j];
       	    }
   		}
   }
}
int main()
{
    int n,e,t,m,u,v,x,y,w,ans=0,i;
    scanf("%d",&n);
    scanf("%d",&e);
    scanf("%d",&t);
    scanf("%d",&m);
	for(x=1;x<=n;x++)
	{
		for(y=1;y<=n;y++)
		{
		    if(x==y)
		    	graph[x][y]=0;
		    else
				graph[x][y]=INF;
		}
	}
    for(x=1;x<=m;x++)
    {
    	scanf("%d %d %d",&u,&v,&w);
 		graph[u][v]=w;
    }
    floyd(n);
    for(i=1;i<=n;i++)
    {
        if(dist[i][e]<=t)
        ans++;
    }
    printf("%d\n",ans);
    return 0;
    }

