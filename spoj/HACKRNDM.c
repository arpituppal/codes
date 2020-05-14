#include<stdio.h>
#define N 1000000
int arr[N],ans[N];
void merge(int a[],int,int);
void mergesort(int [],int,int);
int bsearch(int a[],int,int);

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
 int bsearch(int b[],int item,int size)
 {
    int l=0,h=size-1,mid,flag=0;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(b[mid]==item)        {
            flag=1;
            break;
        }
        else if(item>b[mid])
        l=mid+1;
        else
        h=mid-1;
     }
     return flag;
 }
 int main()
 {
    int n,k1,i,t,c=0;
    scanf("%d %d",&n,&k1);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    mergesort(arr,0,n-1);
    for(i=0;i<n;i++)
    {
        t=bsearch(arr,arr[i]+k1,n);
        if(t==1)
        c++;
    }
    printf("%d\n",c);
    return 0;
 }
