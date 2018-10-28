#include<stdio.h>
#include<string.h>
#define max(x,y) x>y?x:y
char s[5001],s1[5001];
int a[2][5001];
int lcs(int l)
{
    int i,j,k=1;
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
             int i,f=0,res,l1;
             scanf("%d",&l1);
             scanf("%s",s);
             for(i=l1-1;i>=0;i--)
             s1[f++]=s[i];
             res=lcs(l1);
             printf("%d\n",(l1-res));
        return 0;
      }
