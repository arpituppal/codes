#include<stdio.h>
#include<string.h>
char pat[1000010];
int lps[1000010],f=0;
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
}*/
int main()
{
    int x,la,t,i,a;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        f=0;
        scanf("%d",&la);
        scanf("%s",pat);
        presuff(la);
        printf("Test case #%d\n",x);
        for(i=2;i<=la;i++)
        {
           // presuff(i);
            a=i-lps[i-1];
         //printf("a=%d\n",a);
        //for(i=0;i<a;i++)
          //  pat[i]=s[i];
        //pat[i]='\0';
        //la=strlen(pat);
        //kmp(la,lb);
          if(i%a==0 && (i/a)!=1)
          printf("%d %d\n",i,i/a);
        }
    }
   // kmp(la,lb);
    return 0;
 }
