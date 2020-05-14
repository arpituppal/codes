#include<stdio.h>
#define N 300001
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
int i,n,max1=0,max2=0,ans=0;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
max2=arr[0];
for(i=1;i<n;i++)
    {
        if(arr[i]>max2)
                {
                if(max1<arr[i])
                        max1=arr[i];

                else
                        max2=arr[i];

                }
        }
    if(max2!=arr[0])
        ans+=1;
ans+=max2-1;
mergesort(arr,0,n-1);
printf("%d\n",ans);
return 0;

}

