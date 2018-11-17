#include<stdio.h>
double a[300001];
int s(double num)
{
    if(num>1 && num<2)
    return 1;
    else
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,flag=0;
        double min1,min2,max1,max2;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%lf",&a[i]);
        if(a[0]<=a[1])
        {
            min1=a[0];
            min2=a[1];
            max1=a[1];
            max2=a[0];
        }
        if(a[0]>=a[1])
        {
            min1=a[1];
            min2=a[0];
            max1=a[0];
            max2=a[1];
        }
        for(i=2;i<n;i++)
        {
          if((s(min1+min2)==1)||(s(min1+a[i])==1)||(s(min2+a[i])==1)||(s(max1+max2)==1)||(s(max1+a[i])==1)||(s(max2+a[i])==1))
          {
            flag=1;
            break;
          }
          if(a[i]<=min2 && a[i]>=min1)
          min2=a[i];
          else if(a[i]<=min1)
          {
            min2=min1;
            min1=a[i];
          }
          if(a[i]>=max2 && a[i]<=max1)
          max2=a[i];
          else if(a[i]>=max1)
          {
            max2=max1;
            max1=a[i];
           }
        }
        if(flag==1)
        printf("found\n");
        else
        printf("not found\n");
    }
    return 0;
}
