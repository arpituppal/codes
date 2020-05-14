#include<stdio.h>
#define max(x,y) x>y?x:y
int a[3000],b[3000],ans[3000][3000];
int lcs(int l1, int l2)
{
    int i1,j1;
    for(i1=0;i1<=l1;i1++)
    ans[i1][0]=0;
    for(i1=0;i1<=l2;i1++)
    ans[0][i1]=0;
    for(i1=1;i1<=l1;i1++)
    {
        for(j1=1;j1<=l2;j1++)
        {
            if(a[i1-1]==b[j1-1])
            ans[i1][j1]=ans[i1-1][j1-1]+1;
            else
            ans[i1][j1]=max(ans[i1][j1-1],ans[i1-1][j1]);
        }
     }
     return ans[l1][l2];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i=0,j=0,k=0,m,n,maxi=-1,p;
        while(1)
        {
            scanf("%d",&m);
            if(m==0)
            break;
            a[i++]=m;
        }
        while(1)
        {
            j=0;
            scanf("%d",&n);
            if(n==0)
            break;
            b[j++]=n;
            while(1)
            {
               scanf("%d",&m);
               if(m==0)
               break;
               b[j++]=m;
            }

            p=lcs(i,j);
            if(p>maxi)
            maxi=p;
        }
        printf("%d\n",maxi);
    }
    return 0;
}
