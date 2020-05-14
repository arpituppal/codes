     #include <iostream>
    #include <cstdio>
    #include <cstdlib>
    #include <cmath>
    #include <queue>
    #include <algorithm>
    #include <vector>
    #include <cstring>
    #include <stack>
    #include <cctype>
    #include <utility>
    #include <map>
    #include <string>
    #include <climits>
    #include <set>
    #include <sstream>
    #include <utility>
    #include <ctime>
    #include <cassert>
    #include <fstream>
    using namespace std;
    typedef long long LL;
    #define MS(A) memset(A, 0, sizeof(A))
    #define MSV(A,a) memset(A, a, sizeof(A))
    #define MAX(a,b) ((a >= b) ? (a) : (b))
    #define MIN(a,b) ((a >= b) ? (b) : (a))
    #define ABS(a) (((a) > 0) ? (a) : (-a))
    #define MP make_pair
    #define PB push_back
    #define getcx getchar_unlocked
    #define INF (int(1e9))
    #define INFL (LL(1e18))
    #define EPS 1e-12
    #define chkbit(s, b) (s & (1<<b))
    #define setbit(s, b) (s |= (1<<b))
    #define clrbit(s, b) (s &= ~(1<<b))
    inline void inp( int &n )
    {
    n=0; int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
    }
    int dx[]={-2,-2,2,2,1,-1,1,-1};
    int dy[]={-1,1,-1,1,-2,-2,2,2};
    int x1,yy1,x2,y2;
    int visited[10][10],dist[10][10];
     
    void bfs()
    {
    queue<pair<int,int> >q;
     
    visited[x1][yy1]=1;
    dist[x1][yy1]=0;
    q.push(MP(x1,yy1));
    while(!q.empty())
    {
    int i;
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    if(x==x2 && y==y2)
    return;
    for(i=0;i<8;i++)
    {
    int newx=x+dx[i];
    int newy=y+dy[i];
    if(newx>=1 && newy>=1 && newx<=8 && newy<=8)
    {
    if(!visited[newx][newy])
    {
    visited[newx][newy]=1;
    dist[newx][newy]=dist[x][y]+1;
    q.push(MP(newx,newy));
    }
    }
    }
     
    }
     
    }
    int main()
    {
    int t;
    inp(t);
    while(t--)
    {
    char start[5],dest[5];
     
    scanf("%s",start);
    scanf("%s",dest);
    x1=start[0]-96;
    yy1=start[1]-48;
    x2=dest[0]-96;
    y2=dest[1]-48;
    bfs();
    printf("%d\n",dist[x2][y2]);
     
    for(int i=0;i<10;i++)
    {
    for(int j=0;j<10;j++)
    {
    visited[i][j]=0;
    dist[i][j]=0;
    }
    }
    }
    return 0;
    }