#include<stdio.h>
#include<string.h>
int main()
{
  int t,x;
  scanf("%d",&t);
  for(x=1;x<=t;x++)
  {
     char a[1000000],b[1000000];
     int l,l1,i,j,flag=1;
     scanf("%s",a);
     scanf("%s",b);
     l=strlen(a);
     l1=strlen(b);
     if(l<=l1)
     {
        for(i=0,j=0;i<l1,j<l1;i++,j++)
        {
          if(i==l)
          i=0;
          if(j==l1)
          break;
          if(j==l1-1 && i!=l-1 && a[l-1]!=b[j])
          flag=0;
         if(a[i]!=b[j])
          {
          flag=0;
          break;
          }
          }}
          else if(l>l1)
          {
            for(i=0,j=0;i<l,j<l;i++,j++)
            {
              if(j==l1)
              j=0;
              if(i==l)
                break;
              if(i==l-1 && j!=l1-1 && a[i]!=b[l1-1])
                flag=0;
              if(a[i]!=b[j])
              {
               flag=0;
               break;
               }}}
               if(flag==1)
               printf("YES\n");
               else
               printf("NO\n");
               }
               return 0;
            }
