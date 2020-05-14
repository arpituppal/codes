#include<stdio.h>
#include<string.h>
#define max(x,y) x>y?x:y
char s1[1000],s2[1000];
int a[1001][1001];
int main()
{
    while(1)
    {
      int i,j,l1,l2,lcs,ans=0;
      scanf("%s",s1);
     if(s1[0]=='#')
        break;
      scanf("%s",s2);
      l1=strlen(s1);
     l2=strlen(s2);
     for(i=1;i<=l1;i++)
     {
        for(j=1;j<=l2;j++)
        {
            if(s1[i-1]==s2[j-1])
            a[i][j]=a[i-1][j-1]+1;
            else
            a[i][j]=max(a[i][j-1],a[i-1][j]);
        }
     }
     lcs=a[l1][l2];
     ans=15*(l1-lcs)+30*(l2-lcs);
     printf("%d\n",ans);
    }
    return 0;
 }
