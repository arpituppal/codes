#include<stdio.h>
#define N 1000
int arr[N],ans[N];
void merge(int a[],int,int);
void mergesort(int [],int,int);

void mergesort(int a[],int i,int j)
{
   int mid;
   if(i>=j)
   return;
   mid=(i+j)/2;
   mergesort(a,i,mid);
   mergesort(a,mid+1,j);
   merge(a,i,j);
}
void merge(int a[],int low,int high)
{
    int i,j,mid,k=low;
    mid=(low+high)/2;
    i=low,j=mid+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        ans[k++]=a[i++];
        else
        ans[k++]=a[j++];
    }
    while(i<=mid)
    ans[k++]=a[i++];
    while(j<=high)
    ans[k++]=a[j++];
    for(i=low;i<=high;i++)
    arr[i]=ans[i];
 }
 int main()
 {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,i;
        long long int sum=0;
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        mergesort(arr,0,n-1);
        for(i=0;i<n;i++)
        {
            if(k==0)
                break;
            if(arr[i]<0)
            {
                arr[i]=-arr[i];
                 k--;
            }
        }
        mergesort(arr,0,n-1);
        if(k>0)
        {
            if(k%2==0)
            {
                for(i=0;i<n;i++)
                sum+=arr[i];
            }
            else
            {
                arr[0]=-arr[0];
                for(i=0;i<n;i++)
                sum+=arr[i];
            }
         }
        else
          {
               for(i=0;i<n;i++)
                sum+=arr[i];
         }
        printf("%lld\n",sum);
    }
    return 0;
}
