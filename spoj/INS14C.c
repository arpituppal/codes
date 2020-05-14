#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,k;
    char s[1010];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        scanf("%s",s);
        int i=0,flag=1,l=strlen(s);
        while(l!=k)
       {
           //printf("%d\n",l);
            if(flag==1)
            {
                i=0;
                while(s[i]!='1'&& i<l)
                    i++;
                    if(i==l)
                        i=0;
                while(i<l-1)
                    {
                        s[i]=s[i+1];
                        i++;
                    }
                    s[i]='\0';
                    flag=0;
                    l=l-1;
            }
            else
            {
                flag=1;
                i=0;
                while(s[i]!='0'&& i<l)
                    i++;
                    if(i==l)
                        i=0;
                while(i<l-1)
                   {
                        s[i]=s[i+1];
                        i++;
                   }
                   s[i]='\0';
                   l=l-1;
            }
        }
        printf("%s\n",s);
    }
    return 0;
}
