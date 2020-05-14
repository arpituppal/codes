#include<stdio.h>
#include<string.h>
char s[200],s1[200],a[200];
int main()
{
    int t;
    scanf("%d\n",&t);
    while(t--)
    {
        int i=0,l,k=0,top=-1;
        char x,y;
         gets(s);
        l=strlen(s);
   
        while(i<l)
        {
            if(s[i]=='A' || s[i]=='O' || s[i]=='N')
            {
          
                s1[k++]=s[i];
                if(s[i]=='A' || s[i]=='N')
                    i+=3;
                if(s[i]=='O')
                    i+=2;
            }
            if(s[i]==' ' || s[i]==',')
            i++;
            if(s[i]=='(')
            a[++top]=s[i++];
            if(s[i]=='T' || s[i]=='F')
            a[++top]=s[i++];
            if(s[i]==')')
            {
                if(s1[k-1]=='A')
                {
                    x=a[top--];
                    y=a[top--];
                    if(x=='T' && y=='T')
                    a[top]='T';
                    else
                    a[top]='F';
                }
                if(s1[k-1]=='O')
                {
                    x=a[top--];
                    y=a[top--];
                    if(x=='F' && y=='F')
                    a[top]='F';
                    else
                    a[top]='T';
                }
                  if(s1[k-1]=='N')
                  {
                    x=a[top--];
                    x=(x=='T')?'F':'T';
                    a[top]=x;
                  }
                  k--;
                  i++;
                }
        }
        while(top!=-1)
        printf("%c",a[top--]);
        printf("\n");
       }
       return 0;
    }
