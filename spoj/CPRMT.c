#include<stdio.h>
#include<string.h>
int a[26],b[26];
int main()
{
    char s[1001],s1[1001];
    while(scanf("%s",s)!=EOF)
    {
        int i,l1,l2;
        scanf("%s",s1);
        l1=strlen(s);
        l2=strlen(s1);
        for(i=0;i<l1;i++)
        a[s[i]-97]++;
        for(i=0;i<l2;i++)
        b[s1[i]-97]++;
        for(i=0;i<26;i++)
        {
            if(a[i]>0)
            {
                if(b[i]>0)
                {
                    while(a[i]>0&&b[i]>0)
                   {
                        printf("%c",(i+97));
                        a[i]--;
                        b[i]--;
                    }
                }
            }
        }
        printf("\n");
        for(i=0;i<26;i++)
        {
            a[i]=0;
            b[i]=0;
        }

    }
    return 0;
}
