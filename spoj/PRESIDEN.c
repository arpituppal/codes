#include<stdio.h>
int hash[110];
int main()
{
    int a[110][110],t;
    scanf("%d",&t);
    while(t--)
    {
        int c,v,i,j,max1=-1,max2=-1,cand1,cand2,val,count1=0,count2=0;
        scanf("%d %d",&c,&v);
        for(i=1;i<=v;i++)
        {
            for(j=1;j<=c;j++)
                scanf("%d",&a[i][j]);
            hash[a[i][1]]++;
        }
     //   printf("hash:\n");
       // for(i=1;i<=c;i++)
         //   printf("%d ",hash[i]);
        val=(v/2)+1;
        for(i=1;i<=c;i++)
        {
            if(hash[i]>=max1)
            {
                max2=max1;
                cand2=cand1;
                max1=hash[i];
                cand1=i;
            }
            else if(hash[i]>=max2 && hash[i]<=max1)
            {
                max2=hash[i];
                cand2=i;
            }
            hash[i]=0;
        }
    //    printf("cand1=%d cand2=%d\n",cand1,cand2);
        if(max1>=val)
        printf("%d 1\n",cand1);
        else
        {
            for(i=1;i<=v;i++)
            {
                for(j=1;j<=c;j++)
                {
                    if(a[i][j]==cand1)
                    {
                        count1++;
                        break;
                    }
                    if(a[i][j]==cand2)
                    {
                        count2++;
                        break;
                    }
                }
            }
    //        printf("count1=%d count2=%d\n",count1,count2);
            if(count1>count2)
            printf("%d 2\n",cand1);
            else
            printf("%d 2\n",cand2);
        }
    }
  return 0;
    }
