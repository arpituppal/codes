#include<stdio.h>
#define N 100001
int arr[N],arr1[N],ans[N],ans1[N];
void merge(int a[],int a1[],int,int);
void mergesort(int [],int [],int,int);
void mergesort(int a[],int a1[],int i,int j)
{
   int mid;
   if(i>=j)
   return;
   mid=(i+j)/2;
   mergesort(a,a1,i,mid);
   mergesort(a,a1,mid+1,j);
   merge(a,a1,i,j);
}
void merge(int a[],int a1[],int low,int high)
{
    int i,j,mid,k=low;
    mid=(low+high)/2;
    i=low,j=mid+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
ans[k]=a[i];
ans1[k]=a1[i];
k++;
i++;
        }
        else
        {
ans[k]=a[j];
ans1[k]=a1[j];
k++;
j++;
        }
    }
    while(i<=mid)
    {
        ans[k]=a[i];
        ans1[k]=a1[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        ans[k]=a[j];
        ans1[k]=a1[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++)
    {
        arr[i]=ans[i];
        arr1[i]=ans1[i];
    }
 }
 int main()
 {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j,f=1;
        scanf("%d",&n);
    //starting time in arr and finish time in arr1
        for(i=0;i<n;i++)
        scanf("%d %d",&arr1[i],&arr[i]);
        mergesort(arr,arr1,0,n-1);
        i=0;
        for(j=1;j<n;j++)
        {
if(arr1[j]>=arr[i])
{
    f++;
    i=j;
}
        }
        printf("%d\n",f);

    }
    return 0;
}
