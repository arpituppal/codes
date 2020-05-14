#include<stdio.h>
#include<string.h>
char s1[2000],s2[2000];
int a[2001][2001];
int min(int x,int y,int z)
{
    if(x<=y && x<=z)
    return x;
    else if(y<=x && y<=z)
    return y;
    else
    return z;
}
 int main()
 {
      int l1,l2,i,j,c;
      int t;
      scanf("%d",&t);
      while(t--)
      {
         scanf("%s",s1);
         scanf("%s",s2);
         l1=strlen(s1);
         l2=strlen(s2);
         for(i=0;i<=l1;i++)
            a[0][i]=i;
         for(i=0;i<=l2;i++)
            a[i][0]=i;
          for(i=1;i<=l1;i++)
           {
              for(j=1;j<=l2;j++)
              {
                  if(s1[i-1]==s2[j-1])
                   c=0;
                  else
                   c=1;
              a[i][j]=min((a[i-1][j-1]+c),(a[i][j-1]+1),(a[i-1][j]+1));
             }
         }
         printf("%d\n",a[l1][l2]);
      }
    return 0;
  }
