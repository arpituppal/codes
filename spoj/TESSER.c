#include<stdio.h>
#include<string.h>
char pat[1000000],s[1000000];
int lps[1000000],arr[1000000];
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
                printf("YES\n");
                return ;
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
    printf("NO\n");
}
int main()
{
    int t,la,lb,n,i;
    scanf("%d",&t);
    while(t--)
    {
        int j=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        scanf("%s",pat);
        for(i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
            s[j++]='G';
            else if(arr[i]<arr[i-1])
            s[j++]='L';
            else
            s[j++]='E';
        }
        s[j]='\0';
        la=strlen(pat);
        lb=strlen(s);
        kmp(la,lb);
    }
        return 0;
 }
#include<stdio.h>
#include<string.h>
char pat[1000000],s[1000000];
int lps[1000000],arr[1000000];
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
                printf("YES\n");
                return ;
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
    printf("NO\n");
}
int main()
{
    int t,la,lb,n,i;
    scanf("%d",&t);
    while(t--)
    {
        int j=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        scanf("%s",pat);
        for(i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
            s[j++]='G';
            else if(arr[i]<arr[i-1])
            s[j++]='L';
            else
            s[j++]='E';
        }
        s[j]='\0';
        la=strlen(pat);
        lb=strlen(s);
        kmp(la,lb);
    }
        return 0;
 }
