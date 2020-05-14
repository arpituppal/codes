#include<cstdio>
#include<algorithm>
int a[1000000],b[1000000];
int main()
{
    int n,i,j=0,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    scanf("%d",&b[i]);
    std::sort(a,a+n);
    std::sort(b,b+n);
    for(i=0;i<n;i++)
    {
        if(b[i]>a[j])
        {
            ans++;
            j++;
        }
     }
     printf("%d\n",ans);
    return 0;
 }