#include<stdio.h>
int leap(int a)
   {
        int fl=0;
        if(a%100==0 && a%400==0)
           fl=1;
        if(a%100!=0)
        {
            if(a%4==0)
            fl=1;
        }
      return fl;
   }
    int calc(int d1,int m1,int year)
     {
         int dates[]={31,28,31,30,31,30,31,31,30,31,30,31};
         int k,t1,t2;
         int g=0;
         for(k=1901;k<year;k++)
         {
              t1=leap(k);
              if(t1==1)
              g=g+366;
              else
              g=g+365;
         }
          t2=leap(year);
          if(t2==1)
            dates[1]=29;
          for(k=0;k<(m1-1);k++)
             g=g+dates[k];
          g=g+d1;
          dates[1]=28;
          g=g%7;
          return (g);
      }
   int main()
    {
        int t,x;
        scanf("%d",&t);
        for(x=1;x<=t;x++)
        {
           int ans=0,w1,w2,w3,w4,w5;
           int t3,t4,y1,y2,i,j,f=0;
           scanf("%d%d",&y1,&y2);
           for(i=y1;i<=y2;i++)
            {

                f=0;
                for(j=1;j<=12;j++)
                 {
                    t3=calc(21,j,i);
                    if(t3==4)
                     f++;
                 }
               t4=leap(i);
               if(t4==1)
               ans+=(366-f);
               else
               ans+=(365-f);
            }
           w1=ans/144000;
           ans=ans%144000;
           w2=ans/7200;
           ans=ans%7200;
           w3=ans/360;
           ans=ans%360;
           w4=ans/20;
           ans=ans%20;
           w5=ans;
           printf("%d.%d.%d.%d.%d\n",w1,w2,w3,w4,w5);
      }
   return 0;
}

