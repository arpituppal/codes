#include<stdio.h>
int hash[20010],ans1[10010],ans2[10010];
int main()
{
    int n,a[10010],b[10010];
    while(1)
    {
        int i,mid=10000,m,max=-1,sum=0,j=0,k=0;
        scanf("%d",&n);
        if(n==0)
        break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            hash[mid+a[i]]++;
            if(mid+a[i]>max)
            max=mid+a[i];
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
            hash[mid+b[i]]++;
            if(mid+b[i]>max)
            max=mid+b[i];
        }
        for(i=0;i<n;i++)
        {
            sum+=a[i];
            if(hash[mid+a[i]]==2)
            {
                ans1[j++]=sum;
                sum=0;
            }
        }
        ans1[j++]=sum;
        sum=0;
        for(i=0;i<m;i++)
        {
            sum+=b[i];
            if(hash[b[i]+mid]==2)
            {
                ans2[k++]=sum;
                sum=0;
            }
        }
        ans2[k++]=sum;
        sum=0;
        for(i=0;i<j;i++)
        {
            if(ans1[i]>ans2[i])
            sum+=ans1[i];
            else
            sum+=ans2[i];
        }
        printf("%d\n",sum);
        for(i=0;i<=max;i++)
        hash[i]=0;
    }
    return 0;
}