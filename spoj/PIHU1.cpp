#include<cstdio>
#include<algorithm>
long long int a[1001];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j,k,m,flag=0;
        long long int p;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
        scanf("%lld",&p);
        std::sort(a,a+n);
        for(i=0;i<n-2;i++)
        {
            m=p-a[i];
            j=i+1;
            k=n-1;
            while(j<k)
            {
                if(a[j]+a[k]==m)
                {
                    flag=1;
                    break;
                }
                else if(a[j]+a[k]<m)
                j++;
                else if(a[j]+a[k]>m)
                k--;
            }
        }
        if(flag==1)
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}