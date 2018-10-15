#include<stdio.h>
#define N 50000
int arr[N],ans[N];
void merge(int b[],int , int);
int mergesort(int ar[],int i,int j)
{
int mid;
if(i>=j)
return 0;
else
{
mid=(i+j)/2;
mergesort(ar,i,mid);
mergesort(ar,mid+1,j);
merge(ar,i,j);
}
}
void merge(int b[],int k,int l)
{
int mid,i,j,c=k;
/*printf("\n");
  for(i=k;i<=l;i++)
  printf("%d ",b[i]);
  printf("\n");*/
mid=(k+l)/2;
i=k;j=mid+1;
while(i<=mid && j<=l)
{
if(b[i]>b[j])
{
ans[c++]=b[j++];
}
else
{
ans[c++]=b[i++];
}
}
while(i<=mid)
{
ans[c++]=b[i++];
}
while(j<=l)
{
ans[c++]=b[j++];
}
for(i=k;i<=l;i++) //low to high
{
arr[i]=ans[i];
}
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,i1;
        scanf("%d %d",&n,&k);

        for(i1=0;i1<n;i1++)
        scanf("%d",&arr[i1]);

        mergesort(arr,0,n-1);

        int min=1000000000;

      for(i1=0;i1<=n-k;i1++)
        {
               if(ans[i1+k-1]-ans[i1]<min)
                min=ans[i1+k-1]-ans[i1];
         }
         printf("%d\n",min);
        }
        return 0;
    }
