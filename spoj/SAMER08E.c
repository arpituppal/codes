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
int main()
{
    int dates[]={31,28,31,30,31,30,31,31,30,31,30,31};
    while(1)
    {
       int n,x,d1,m1,y1,sum=0;
       long long int c1,s=0;
       scanf("%d",&n);
       if(n==0)
        break;
        scanf("%d %d %d %lld",&d1,&m1,&y1,&c1);
        for(x=2;x<=n;x++)
        {
            int d2,m2,y2;
            long long int c2;
            scanf("%d %d %d %lld",&d2,&m2,&y2,&c2);
            if(y1==y2)
            {
                int t;
                t=leap(y1);
                if(t==1)
                dates[1]=29;
                if(m1==m2)
                {
                   if((d2-d1)==1)
                   {
                      sum++;
                      s+=(c2-c1);
                    }
                }
               else if((m2-m1)==1)
               {
                   if((d1==dates[m1-1]) && (d2==1))
                   {
                      sum++;
                      s+=c2-c1;
                    }
                }
               dates[1]=28;
            }
             else if((y2-y1)==1)
              {
                 if(m1==12 && m2==1)
                 {
                     if(d1==31 && d2==1)
                    {
                       sum++;
                       s+=c2-c1;
                    }
                }
            }
            d1=d2;
            m1=m2;
            y1=y2;
            c1=c2;
         }
         printf("%d %lld\n",sum,s);
        }
        return 0;
        }
