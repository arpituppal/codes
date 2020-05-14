#include<stdio.h>
#define N 100000
int arr[N],ans[N],c;
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
void merge(int b[],int low,int high)
{
    int i,j,mid,k=low;
    mid=(low+high)/2;
    i=low,j=mid+1;
    while(i<=mid && j<=high)
    {
        if(b[i]<=b[j])
        ans[k++]=b[i++];
        else
        {
         c+=(j-k);
         ans[k++]=b[j++];
        }
    }
    while(i<=mid)
    ans[k++]=b[i++];
    while(j<=high)
    ans[k++]=b[j++];
    for(i=low;i<=high;i++)
    arr[i]=ans[i];
 }
 int main()
 {
      int t,n;
      scanf("%d",&t);
      while(t--)
      {
       scanf("%d",&n);
       int i;
       c=0;
       for(i=0;i<n;i++)
       scanf("%d",&arr[i]);
       mergesort(arr,0,n-1);
       printf("%d\n",c);
       }
       return 0;
 }
