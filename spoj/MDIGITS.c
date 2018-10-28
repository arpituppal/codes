#include<stdio.h>
int ans[2][10];
void digits(int n,int ch)
{
    int x=1,y,m=0,r,i;
    while(1)
    {
        r=n%10;
        n/=10;
        ans[ch][r]++;
        m=r*x+m;
        for(i=r-1;i>0;i--)
        ans[ch][i]+=x;
        if(n==0)
        break;
        y=n*x;
        if(r>0)
        i=0;
        else
        {
            i=1;
            ans[ch][0]+=y-x;
        }
        for(;i<10;i++)
        ans[ch][i]+=y;
        ans[ch][n%10]+=m;
        x=x*10;
      }
  }
  int main()
  {
        int a,b;
        while(1)
        {
            int i,j,sm,max;
            scanf("%d %d",&a,&b);
            if(a==0 && b==0)
            break;
            for(i=0;i<2;i++)
            {   
                for(j=0;j<10;j++)
                ans[i][j]=0;
            }
            sm=a<b?a:b;
            max=a>b?a:b;
            digits(max,0);
            if(sm>1)
            digits(sm-1,1);
            for(i=0;i<10;i++)
            printf("%d ",ans[0][i]-ans[1][i]);
            printf("\n");
        }
        return 0;
  }       