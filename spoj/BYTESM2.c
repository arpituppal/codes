#include<stdio.h>
#define max(a1,b1) a1>b1?a1:b1
int n[110][110],ans[110][110];
int maximum(int a,int b,int c)
{
    if(a>=b && a>=c)
    return a;
    if(b>=a && b>=c)
    return b;
    if(c>=a && c>=b)
    return c;
 }
 int main()
 {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int h,w,i,j,max1=-1;
            scanf("%d %d",&h,&w);
            for(i=0;i<h;i++)
            {
                for(j=0;j<w;j++)
                scanf("%d",&n[i][j]);
            }
            for(i=0;i<w;i++)
            ans[0][i]=n[0][i];
            for(i=1;i<h;i++)
            {
                ans[i][0]=max((n[i][0]+ans[i-1][0]),(n[i][0]+ans[i-1][1]));
                for(j=1;j<w-1;j++)
                {
                    ans[i][j]=maximum((n[i][j]+ans[i-1][j]),(n[i][j]+ans[i-1][j-1]),(n[i][j]+ans[i-1][j+1]));
                   //  printf("%d\n",ans[i][j]);
                }
                ans[i][w-1]=max((n[i][w-1]+ans[i-1][w-1]),n[i][w-1]+ans[i-1][w-2]);
               // printf("\n");
            }
            for(i=0;i<w;i++)
            {
                if(ans[h-1][i]>max1)
                max1=ans[h-1][i];
            }
            printf("%d\n",max1);
        }
        return 0;
    }
