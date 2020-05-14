#include<stdio.h>
#include<string.h>
char pat[1000000],s[1000000];
int lps[1000000],f=0;
void presuff(char pat[],int la)
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
    presuff(pat,la);
    for(i=0;i<lb;)
    {
        if(s[i]==pat[j])
        {
            i++;
            j++;
            if(j==la)
            {
                //flag=1;
                f++;
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
    //if(flag==0)
//    printf("Pattern not found\n");
}
int main()
{
    int la,lb,t,i;
    //scanf("%d",&t);
    while(1)
    {
        f=0;
        scanf("%s",s);
        if(s[0]=='*')
            break;
        lb=strlen(s);
        presuff(s,lb);
        int a=lb-lps[lb-1];
       // printf("a=%d\n",a);
        for(i=0;i<a;i++)
            pat[i]=s[i];
        pat[i]='\0';
        la=strlen(pat);
        kmp(la,lb);
        if(lb-(la*f)==0)
        printf("%d\n",f);
        else
            printf("1\n");


    }
   // kmp(la,lb);
    return 0;
 }
