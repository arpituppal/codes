#include<stdio.h>
#include<string.h>
char pat[1000000],s[1000000];
int lps[1000000];
void presuff(int la)
{
    int len=0,i;
    for(i=1;i<la;)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            len=lps[len-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
     }
}
void kmp(int la,int lb)
{
    int i,j=0,flag=0;
    presuff(la);
    for(i=0;i<lb;)
    {
        if(s[i]==pat[j])
        {
            i++;
            j++;
            if(j==la)
            {
                flag=1;
                printf("%d\n",i-la);
                j=lps[j-1];
            }
        }
        else
        {
            if(j!=0)
            j=lps[j-1];
            else
            i++;
        }
    }
    if(flag==0)
    printf("\n");
}
int main()
{
    int la,lb,n;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s %s",pat,s);
        la=strlen(pat);
        lb=strlen(s);
        kmp(la,lb);
        printf("\n");
    }
    return 0;
}
