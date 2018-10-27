#include<stdio.h>
int main()
{
  int g,b;
  while(1)
 {
 int f,t=0;
 scanf("%d %d",&g,&b);
 if(g==-1 && b==-1)
 break;
 if(g==0 && b==0)
 f=0;
 if((g==b) && g!=0)
 f=1;
 if(b>g)
 {
     t=g;
     g=b;
     b=t;
 }
 if(g%(b+1)==0)
 f=g/(b+1);
 else if(g%(b+1)!=0)
 f=(g/(b+1))+1;
 printf("%d\n",f);
 }
 return 0;
 }
