#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    char s[100000];
    while(t--)
    {
        long long int n,res,ans,i,k=0;
        scanf("%lld",&n);
        while(n>0)
        {
            res=n%5;
            if(res==0)
            n=(n/5)-1;
            else
            n=n/5;
            switch(res)
            {
                case 0: s[k++]='u';
                        break;
                case 1: s[k++]='m';
                        break;
                case 2: s[k++]='a';
                        break;
                case 3: s[k++]='n';
                        break;
                case 4: s[k++]='k';
                        break;
            }
        }
         for(i=k-1;i>=0;i--)
         printf("%c",s[i]);
         printf("\n");

       /* if(n<=5)
        printf("%c",word[n-1]);
        else if(n/5<=5)
        {
            if(n%5==0)
            printf("%cu",word[n/5-2]);
            else
            printf("%c%c",word[n/5-1],word[n%5-1]);
        }
        else
        {
             while(1)
             {
                res=n/5;

                if(res<=5)
                {
                    if(n%5==0)
                    printf("u");
                    else
                    printf("%c",word[n%5-1]);
                    break;
                }
                while(res>5)
                res=res/5;
                printf("%c",word[res-1]);
                n=n-5;
              }
          }
          printf("\n");*/
        }
        return 0;
    }
