#include<stdio.h>
long long int squareroot(long long int num)
{
    long long int n,n1;
	if(num==0)
	   return 0;
	 n=(num/2)+1;
	 n1=(n+(num/n))/2;
	while(n1<n)
	{
		n=n1;//x++;
		n1=(n+(num/n))/2;
	}
	//printf("iterated %lld times\n",x);
	return n;
}
int main()
{
    int t,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        long long int n,ans=0,last;
        scanf("%lld",&n);
      //  last=n%10;
       // if(last!=2 && last!=3 && last!=7 && last!=8)
        //printf("Case %d: No\n",x);
       // if(last==2||last==3||last==7||last==8)
       // {
            ans=squareroot(n);

            if(ans*ans==n)
            printf("Case %d: Yes\n",x);
            else
            printf("Case %d: No\n",x);
        //}
    }
    return 0;
}

