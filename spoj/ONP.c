#include<stdio.h>
#include<string.h>
int p(char ch)
{
  if(ch=='(')
    return 0;
  else if(ch=='+')
    return 1;
  else if(ch=='-')
    return 2;
  else if(ch=='*')
    return 3;
  else if(ch=='/')
    return 4;
  else if(ch=='^')
    return 5;
 }
int main()
{
  int t,x;
  scanf("%d",&t);
  for(x=1;x<=t;x++)
  {
    char a[500],b[500];
    int l,i=0,top=-1;
    scanf("%s",a);
   while(a[i]!='\0')
    {
    	if(a[i]>=97 && a[i]<=122)
         printf("%c",a[i++]);
      else
      {
         if(a[i]=='(')
         b[++top]=a[i++];
         else if(a[i]==')')
         {
           while(b[top]!='(')
           printf("%c",b[top--]);
           top--;
           i++;
       }
         else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/' || a[i]=='^')
         {
           if(p(a[i])>p(b[top]))
           b[++top]=a[i++];
           else
           {
             while(p(a[i])<p(b[top]))
             printf("%c",b[top--]);
             b[++top]=a[i++];
            }
        }
      }}
      while(top!=-1)
      printf("%c",b[top--]);
      printf("\n");
      }
   return 0;
  }


