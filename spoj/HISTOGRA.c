#include<stdio.h>
long long int arr[100000],stk[100000],area[100000];
long long int largestarea(int n)
{
    int top=-1,i;
    long long int t,max=-1;
    for(i=0;i<n;i++)
    area[i]=0;
    for(i=0;i<n;i++)
    {
        while(top!=-1)
        {
            if(arr[i]<=arr[stk[top]])
            top--;
            else
            break;
        }
        if(top==-1)
        t=-1;
        else
        t=stk[top];
        area[i]=i-t-1;
        stk[++top]=i;
    }
    top=-1;
    for(i=n-1;i>=0;i--)
    {
        while(top!=-1)
        {
            if(arr[i]<=arr[stk[top]])
            top--;
            else
            break;
        }
        if(top==-1)
        t=n;
        else
        t=stk[top];
        area[i]+=t-i-1;
        stk[++top]=i;
    }
    for(i=0;i<n;i++)
    {
        t=arr[i]*(area[i]+1);
        if(t>max)
        max=t;
    }
    return max;
}
    int main()
    {
        int n;
        while(1)
        {
            int i;
            long long int ans;
            scanf("%d",&n);
            if(n==0)
            break;
            for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
            ans=largestarea(n);
            printf("%lld\n",ans);
        }
    return 0;
}

