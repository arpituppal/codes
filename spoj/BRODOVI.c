#include<stdio.h>
int b[5001],a[5001];
int main()
{
    int n,i,j,k,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i]--;
    }
    for(i=1;i<n;i++)
    {
        if(b[i]==0)
        {
            k=a[i];
            for(j=i;j<n;j++)
            {
                if(k==a[j])
                {
                    b[j]=1;
                    k+=a[i];
                }
            }
            ans++;
         }
     }
     printf("%d\n",ans);
    return 0;
}
