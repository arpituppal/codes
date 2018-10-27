#include<stdio.h>
#define N 10000000
double a[N];
void buildup(int x,double w)
{
    int par,i=x;
    par=x/2;
    a[i]=w;
    while(i>1)
    {
       // printf("i=%d par=%d val=%lf parval=%lf\n",i,par,a[i],a[par]);
        if(i%2==1 && par%2==1)
        w=4*w;
        else
        w=2*w;
        a[par]=w;
        i=par;
        par=i/2;
    }
}
void builddown(int y,double w)
{
    int i,lchild,rchild;
    double w1,w2;
    for(i=1;;i++)
    {

        lchild=2*i;
        rchild=2*i+1;
        w1=a[i];
        if(i%2==0)
        {
                a[lchild]=w1/2;
                a[rchild]=w1/2;
        }
        else
        {
            a[lchild]=w1/2;
            a[rchild]=w1/4;
        }
        if(lchild==y || rchild==y)
        break;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,y;
        double w;
        scanf("%d %d %lf",&x,&y,&w);
        buildup(x,w);
        builddown(y,w);
        printf("%.6lf\n",a[y]);
     }
     return 0;
}
