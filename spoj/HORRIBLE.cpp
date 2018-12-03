#include<stdio.h>
long long int bit1[100002],bit2[100002];
void update(long long int arr[],int n,int idx,long long int val)
{
    while(idx<=n)
    {
        arr[idx]+=val;
        idx+=(idx & -idx);
    }
}
long long int query(long long int arr[],int n,int idx)
{
       long long int sum=0;
       while(idx>0)
       {
            sum+=arr[idx];
            idx-=(idx & -idx);
       }
      return sum;
}
int main()
{
    int t,n,c,i,a,p,q;
    long long int ans,sum1,sum2,v;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d",&n);
        scanf("%d",&c);
        for(i=1;i<=c;i++)
        {
            scanf("%d",&a);
            if(a==0)
            {
                scanf("%d",&p);
                scanf("%d",&q);
                scanf("%lld",&v);
                update(bit1,n,p,v);
                update(bit1,n,q+1,(-1*v));
                update(bit2,n,p,(v*(p-1)));
                update(bit2,n,q+1,(-1*(v*q)));
            }
            if(a==1)
            {
                scanf("%d",&p);
                scanf("%d",&q);
                sum1=((query(bit1,n,q)*q)-(query(bit2,n,q)));
                sum2=((query(bit1,n,p-1)*(p-1))-(query(bit2,n,p-1)));
                ans=sum1-sum2;
                printf("%lld\n",ans);
           }
       }
       for(i=0;i<=n;i++)
       {
         bit1[i]=0;
         bit2[i]=0;
       }
   }
   return 0;
}
