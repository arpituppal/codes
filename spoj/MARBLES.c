#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
			long long int n,k,ans=1,i;
			scanf("%lld %lld",&n,&k);
			n=n-1;
			k=k-1;
			if(k>n-k)
			k=n-k;
		   for(i=0;i<k;i++)
		   ans=ans*(n-i)/(i+1);
		   printf("%lld\n",ans);
	}
	return 0;
}