#include<stdio.h>
#include<string.h>

int main()
{
    char s[100001],s1[100001];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int i,l,k=1,flag=0,j;
        l=strlen(s);
        s1[0]=s[0];
        for(i=1;i<l;i++)
        {
            if(s[i]!=s[i-1])
            s1[k++]=s[i];
        }
        for(i=0,j=k-1;i<k/2;i++,j--)
        {
            if(s1[i]!=s1[j])
            {
                flag=1;
                 break;
           }
        }
        if(flag==1)
        printf("NO\n");
        else
        printf("YES\n");
    }
    return 0;
}

