#include<stdio.h>
#include<string.h>
char s[1000001];
int hash[1000001];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,c=0,i;
        long long int ans=0;
        scanf("%d %d",&n,&k);
        scanf("%s",s);
        hash[0]++;
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='1')
              c++;
            if(c>=k)
              ans+=hash[c-k];
            hash[c]++;
        }
        for(i=0;i<1000000;i++)
        hash[i]=0;
        printf("%lld\n",ans);
     }
    return 0;
}
