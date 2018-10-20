#include<stdio.h>
int main()
{
   long long int t,x;
   char ch;
   scanf("%lld",&t);
   ch=getchar();
   int dates[]={31,28,31,30,31,30,31,31,30,31,30,31};
    char s[][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
   for(x=1;x<=t;x++)
   {
     long long int d,m,y,flag=0,i,g=0,f;
      scanf("%lld%lld%lld",&d,&m,&y);
      ch=getchar();
      if((y%100!=0)&&(y%4==0))
        dates[1]=29;
        else if(y%100==0)
          {
          if(y%400==0)
         dates[1]=29;
           }
        for(i=2001;i<y;i++)
        {
            flag=0;
            if(i%100!=0)
               {
               if(i%4==0)
               {

                flag=1;
                g=g+366;
            }}
            if(i%100==0)
             {
               if(i%400==0)
               {
                   flag=1;
                   g=g+366;
             }}
            if(flag==0)
            g=g+365;
        }
        for(i=0;i<(m-1);i++)
         g=g+dates[i];
         g=g+d;
         f=g%7;
           if(f==0)
             printf("%s\n\n",s[6]);
           else
             printf("%s\n\n",s[f-1]);
           dates[1]=28;
           }
           return 0;
           }
