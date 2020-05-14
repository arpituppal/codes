#include<stdio.h>
#include<string.h>
#define as(n) n<0?-n:n
#define N 10000000
char s[N];
int dist(char a)
{
     int d;
    switch (a)
    {
        case 'G': d=1;
                break;
        case 'R': d=2;
                break;
        case 'Y': d=3;
                break;
        case 'B': d=4;
                break;
        case 'O': d=5;
                break;
    }
    return d;
 }
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        long long int c,l,j=1,sum,num=1,maxnum=0,ind=0;
        int diff,diff1;
        scanf("%lld %s",&c,s);
        sum=c;
        l=strlen(s);

       for(;j<l;j++)
        {

//           pos++;

          //  printf(" dist2=%d dist1=%d diff=%d\n",dist(s[j]),dist(s[j+1]),diff);


                diff=(dist(s[j])-dist(s[j-1]));
                diff=as(diff);
                sum=sum-diff;
                if(sum>=0)
               {
                  num++;
                 if(num>maxnum)
                 maxnum=num;

              }
       else
       {

            while(sum<0 && ind<=(j-1))
                {

                    diff1=(dist(s[ind])-dist(s[ind+1]));
                    sum+=as(diff1);
                    ind++;
                    num--;
                   // printf("YESS diff=%d sum=%lld ind=%d num=%lld\n",diff1,sum,ind,num);
                }
                num++;
       }
         //  printf("sum=%lld num=%lld maxnum=%lld char %c num=%lld j=%lld\n",sum,num,maxnum,s[j],num,j);
        }
        printf("Scenario #%d: %lld\n",i,maxnum);
    }
    return 0;
}

