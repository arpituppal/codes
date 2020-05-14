#include<stdio.h>
#include<string.h>
int main()
{
    char s[100001],s1[100001];
    while(scanf("%s",s)!=EOF)
    {
        int l,i,f=1,j,k=0;
        l=strlen(s);
        for(i=1;i<l;i++)
        {
            s1[k++]=s[i-1];
            if(s[i]==s[i-1])
             f++;
          // printf("i=%d f=%d k=%d s=%c\n",i,f,k-1,s[k-1]);
            if(s[i]!=s[i-1]|| i==l-1)
            {
                if(f>3)
                printf("%d!%c",f,s[i-1]);
                else
                {
                  //  printf("YESS\n");
                  if(i==l-1)
                  {
                      s1[k++]=s[i];

                  }

                       for(j=0;j<k;j++)
                        printf("%c",s1[j]);



                }
                f=1;
                k=0;
            }

        }
        printf("\n");
    }
    return 0;
 }
