#include<stdio.h>
#define N 1000000
long long int arr[N],ans[N],res=0;
void merge(long long int a[],long long int,long long int);
void mergesort(long long int [],long long int,long long int);

void mergesort(long long int a[],long long int i,long long int j)
{
  long long  int mid;
   if(i>=j)
   return;
   mid=(i+j)/2;
   mergesort(a,i,mid);
   mergesort(a,mid+1,j);
   merge(a,i,j);
}
void merge(long long int b[],long long int low,long long int high)
{
long long int i,j,mid,k=low;
    mid=(low+high)/2;
    i=low,j=mid+1;
    while(i<=mid && j<=high)
    {
        if(b[i]<b[j])
        {
          ans[k++]=b[i];
         res+=(high-j+1)*arr[i++];
         }
        else
         ans[k++]=b[j++];
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
    int t;
    long long int n;
    scanf("%d",&t);
    while(t--)
      {
        res=0;
       scanf("%lld",&n);
       int i;
       for(i=0;i<n;i++)
       scanf("%lld",&arr[i]);
       mergesort(arr,0,n-1);
       printf("%lld\n",res);
       }
       return 0;
 }
