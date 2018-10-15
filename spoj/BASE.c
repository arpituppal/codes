#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[1000000],s1[1000000];
    int a[1000000];
    int b[3];
    while(gets(s)!=0)
    {
        int l,i=0,r=0,n=0,f=0,j,d,m=0,pos=0;
        l=strlen(s);
        for(;i<l;i++)
        {
            if(s[i]==' ')
            continue;
            else
            {
                j=i;
                while(s[j]!=' ' && j<l)
                {
                    if(s[j]>=48 && s[j]<=57)
                    a[m]=(s[j]-48);
                    else if(s[j]>=65 && s[j]<=90)
                    a[m]=((int)s[j]-55);
                    j++;
                    m++;
                }
                a[m++]=-1;
                i=j;
          }
       }

       for(i=0;i<m;i++)
       {
           if(a[i]==-1)
           {
               pos=i;
               break;
           }
       }
       for(i=pos+1;i<m;i++)
       {
           if(a[i]!=-1)
            r=(r*10)+a[i];
            else
           {
               b[f++]=r;
               r=0;
            }
       }
       f=0;
       for(i=pos-1;i>=0;i--)
       n+=a[i]*(pow(b[0],f++));
       i=0;
        while(n>0)
        {
          d=n%b[1];
          if(d<10)
          s1[i]=(d+48);
          else if(d==10)
          s1[i]='A';
          else if(d==11)
          s1[i]='B';
          else if(d==12)
          s1[i]='C';
          else if(d==13)
            s1[i]='D';
          else if(d==14)
            s1[i]='E';
          else if(d==15)
            s1[i]='F';
          i++;
          n=n/b[1];
        }
        if(i>7)
        printf("  ERROR\n");
        else
        {
           for(j=0;j<(7-i);j++)
           printf(" ");
           for(j=i-1;j>=0;j--)
           printf("%c",s1[j]);
           printf("\n");
        }
    }
    return 0;
}
