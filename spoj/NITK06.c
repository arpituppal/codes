#include<stdio.h>
int main()
{
    int t,x;
    scanf("%d",&t);
    long long int a[10000];
    for(x=1;x<=t;x++)
    {
        long long int n,i;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
        for(i=0;i<n-1;i++)
        {
                a[i+1]=a[i+1]-a[i];
                a[i]=0;
                if(a[i+1]<0)
                break;
            }
                if(a[n-1]==0)
                printf("YES\n");
                else
                printf("NO\n");
            }
            return 0;
            }
