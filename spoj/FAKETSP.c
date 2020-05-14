#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[1000000];
    int l;
    double x1,x2,y1,y2,sum=0.0;
    scanf("%*[^(] (%lf, %lf).",&x1,&y1);
    //printf("%.3lf %.3lf\n",x1,y1);
    while(scanf("%*[^(](%lf, %lf).",&x2,&y2)!=EOF)
    {
        sum+=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        x1=x2;
        y1=y2;
        printf("The salesman has traveled a total of %.3lf kilometers.\n",sum);
    }
    return 0;
}
