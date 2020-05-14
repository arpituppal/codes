#include<stdio.h>
#include<math.h>
char a[10000000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,k,i,curr=2,j=0,prev;
        scanf("%lld %lld",&n,&k);
        n=n-1;
        //for(i=1;i<n;i++)
        //curr*=2;
       // printf("%llu\n",curr);
        curr=k;
        while(curr>1)
        {
            prev=curr/2;
            if(curr%2!=0)
            {
                prev+=1;
            //if(curr==(prev*2))
                a[j++]='L';
            }
            //if(curr==((prev*2)+1))
              if(curr%2==0)
                    a[j++]='R';
            curr=prev;
        }
        a[j]='M';
        for(i=j-1;i>=0;i--)
        {
            if(a[i+1]=='M' && a[i]=='L')
                a[i]='M';
            else if(a[i+1]=='M' && a[i]=='R')
                a[i]='F';
            else if(a[i+1]=='F' && a[i]=='L')
                a[i]='F';
            else if(a[i+1]=='F' && a[i]=='R')
                a[i]='M';
        }
        if(a[0]=='M')
            printf("Male\n");
        if(a[0]=='F')
            printf("Female\n");
    }
    return 0;
}
