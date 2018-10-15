#include<stdio.h>
#define max(x,y) x>y?x:y
int a[1000000];
int main()
{
    int n,i,j,k,m=-1;
    scanf("%d",&n);
    char ch=getchar();
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        if(a[i]>m)
        m=a[i];
    }
    if(k==n)
    printf("%d",m);
    else
    printf("%d ",m);
    for(i=1;i<=n-k;i++)
    {
        if(a[i-1]==m)
        {
            m=-1;
            for(j=i;j<i+k;j++)
            {
                if(a[j]>m)
                m=a[j];
            }
        }
        else
        m=max(m,a[i+k-1]);
        if(i==n-k)
        printf("%d",m);
        else
        printf("%d ",m);
    }
    return 0;
}
