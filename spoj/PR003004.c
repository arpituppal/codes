#include<stdio.h>
long long int ans[2][10];
void digits(long long int n,int ch)
{
    long long int x=1,y,m=0,r,i;
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
        int t;
        long long int a,b;
        scanf("%d",&t);
        while(t--)
        {
            long long int i,j;
            long long unsigned int sum=0;
            scanf("%lld %lld",&a,&b);
            for(i=0;i<2;i++)
            {
                for(j=0;j<10;j++)
                ans[i][j]=0;
            }
            if(b>=0)
            digits(b,0);
            if(a>0)
            digits(a-1,1);
            for(i=0;i<10;i++)
            sum+=(i*(ans[0][i]-ans[1][i]));
            printf("%llu\n",sum);
        }
        return 0;
  }
