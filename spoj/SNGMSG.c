#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    char s[600],num[10],ans[600],enc[50];
    while(t--)
    {
        int i=0,j=0,k=0,f=0,l,x,res;
        scanf("%s",num);
        scanf("%s",s);
        l=strlen(num);
        k=l;
        x=l-1;
        while(num[j]!='\0')
        {
            enc[i++]=num[j++];
            enc[k++]=num[x--];
        }
        enc[k]='\0';
        j=0;
        for(i=0;s[i]!='\0';i++)
        {
            if(f>(2*l-1))
            f=0;
            res=s[i]-(enc[f]-48);
            if(res<97)
               ans[j++]=(26+res);
            else
               ans[j++]=res;
            f++;
        }
        ans[j]='\0';
        printf("%s\n",ans);
    }
    return 0;
}
