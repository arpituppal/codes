#include<stdio.h>
#include<string.h>
#define max(x,y) x>y?x:y
char s[6100],s1[6100];
int a[2][6101];
int lcs()
{
    int i,j,l,k=1;
   l=strlen(s);
    for(i=0;i<=l;i++)
    a[0][i]=0;
    for(i=1;i<=l;i++)
    {
        a[k][0]=0;
        for(j=1;j<=l;j++)
        {
           if(k==1)
            {
              if(s[i-1]==s1[j-1])
              a[k][j]=a[k-1][j-1]+1;
              else
              a[k][j]=max(a[k][j-1],a[k-1][j]);
            }
            if(k==0)
            {
                if(s[i-1]==s1[j-1])
                a[k][j]=a[k+1][j-1]+1;
                else
                a[k][j]=max(a[k+1][j],a[k][j-1]);
                }
            }
         /*   printf("k=%d\n",k);
          for(j=0;j<=l;j++)
           printf("%d ",a[k][j]);
           printf("\n");   */
           if(k==1)
           k=0;
           else
           k=1;
       }
       return a[l%2][l];
     }
     int main()
     {
        int t;
        scanf("%d",&t);
        while(t--)
         {
            int i,f=0,res,l1;
            scanf("%s",s);
            l1=strlen(s);
            for(i=l1-1;i>=0;i--)
            s1[f++]=s[i];
            res=lcs();
           printf("%d\n",(l1-res));
          }
        return 0;
      }
