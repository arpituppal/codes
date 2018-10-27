#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int key,i,l,d,ans;
        char a[100050],s[100050];
        scanf("%d",&key);
        scanf("%s",a);
        l=strlen(a);
        for(i=0;i<l;i++)
        {
           d=(int)a[i];
           if(a[i]=='.')
           {
           printf(" ");
           continue;
           }
           if(key<=25)
           {
               if(d>=65 && d<=90)
               {
                    ans=d+key;
                    if(ans>90)
                    ans=(ans-90)+64;
                }
                else if(d>=97 && d<=122)
                {
                    ans=d+key;
                    if(ans>122)
                    ans=(ans-122)+96;
                }
                s[i]=(char)ans;
            }
            else if(key>=26)
            {
                ans=key-26;
                if(d>=65 && d<=90)
                {
                    ans=d+ans;
                    if(ans>90)
                    ans=(ans-90)+64;
                    ans=ans+32;
                }
                if(d>=97 && d<=122)
                {
                    ans=d+ans;
                    if(ans>122)
                    ans=(ans-122)+96;
                    ans=ans-32;
                }
                s[i]=(char)ans;
            }
            printf("%c",s[i]);
        }
        printf("\n");
     }
     return 0;
     }
