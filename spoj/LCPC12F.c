#include<stdio.h>
int hash[100001];
int main() 
{
    int t,X,N,arr[100000],i,j,k;
    long long int count;
    scanf("%d",&t);
    for (k=1;k<=t;k++)
    {
        scanf("%d %d",&X,&N);
        for(i=0;i<=100000;i++) 
            hash[ i ] = 0;
        count=0;
        for(i=0;i<N;i++)
        scanf("%d",&arr[i]);
        for(i=0;i<N;i++)
        {
     
            if(X>=arr[i])
                count+= hash[X-arr[i]];
            
            hash[arr[i]]+=1;
        }
        printf( "%d. %lld\n",k,count);
    }
    return 0;
}