#include<stdio.h>
#include<string.h>
char s[1000000],pat[1000000];
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
/*void kmp(int la,int lb)
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
                //printf("Found at %d %d\n",i-la,i-1);
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
//    if(flag==0)
  //  printf("Pattern not found\n");
}*/
int main()
{
    int la,lb,i,j=0,ans;
    while(scanf("%s",s)!=EOF)
    {
        j=0;
        la=strlen(s);
        for(i=la-1;i>=0;i--)
        pat[j++]=s[i];
        pat[j++]='1';
        for(i=0;i<la;i++)
        pat[j++]=s[i];
        pat[j]='\0';
      //  printf("%s\n",pat);
        lb=strlen(pat);
        presuff(lb);
        ans=lps[lb-1];
        printf("%s",s);
        for(i=la-ans-1;i>=0;i--)
        printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
