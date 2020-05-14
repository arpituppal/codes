#include <stdio.h>
#define N 1000001
int entry[N],exit[N];
int main()
{
    int t,i,n,en,ex,m=0,sum=0,min,max;
    scanf("%d",&t);
    while(t--)
    {
        m=0; sum=0;
        scanf( "%d", &n);
        min = 10000000;
        max = 0;
        for(i=0;i<n;i++)
         {
            scanf( "%d%d",&en,&ex);
            entry[en]=1;
            exit[ex]=1;
            if(en<min)
             min = en;
            if(ex > max )
                max = ex;
        }

        for(i=min;i<=max;i++)
         {
            if (entry[ i ]==1)
             {
                sum++;
                entry[i]=0;
             }
            if (exit[i]==1)
             {
                --sum;
                exit[i]=0;
            }
            if ( sum > m ) {
                m =sum;
            }
        }
        printf( "%d\n", m );
    }
    return 0;
}
