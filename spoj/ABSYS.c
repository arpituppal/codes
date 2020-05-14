#include<stdio.h>
#include<string.h>
int main()
{
    long long int t;
    char ch;
    scanf("%lld",&t);
    ch=getchar();
    while(t--)
    {
        char s[1000000],a1[1000000],a2[1000000],a3[1000000];
        int l,f1=0,f2=0,f3=0,i,pos1,pos2,f=0,ans=0;
        ch=getchar();
        gets(s);
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]=='+')
            pos1=i;
            if(s[i]=='=')
            pos2=i;
        }
        for(i=0;i<pos1;i++)
        {
            if(s[i]!=' ')
            a1[f++]=s[i];
            if(s[i]=='m')
            f1=1;
        }
        a1[f]='\0';
        f=0;
        
       for(i=pos1+1;i<pos2;i++)
        {
            if(s[i]!=' ')
            a2[f++]=s[i];
            if(s[i]=='m')
            f2=1;
        }
        a2[f]='\0';
        f=0;
        for(i=pos2+1;i<l;i++)
        {
            if(s[i]!=' ')
            a3[f++]=s[i];
            if(s[i]=='m')
            f3=1;
        }
        a3[f]='\0';
        f=0;
        if(f1==1)
        {
            ans=(atoi(a3)-atoi(a2));
            printf("%d + %s = %s\n",ans,a2,a3);
        }
        else if(f2==1)
        {
            ans=(atoi(a3)-atoi(a1));
            printf("%s + %d = %s\n",a1,ans,a3);
        }
        else if(f3==1)
        {
            ans=(atoi(a1)+atoi(a2));
            printf("%s + %s = %d\n",a1,a2,ans);
        }
    }
    return 0;
}
