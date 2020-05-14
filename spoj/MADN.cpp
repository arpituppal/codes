#include<stdio.h>
#include<algorithm>
int main()
{
    int t,x;
    char v[250],c[250];
    scanf("%d",&t);
    char vowel[]={'A','U','E','O','I'};
    char cons[]={'J','S','B','K','T','C','L','D','M','V','N','W','F','X','G','P','Y','H','Q','Z','R'};
    for(x=1;x<=t;x++)
    {
        int n,i,j=0,k=0,vcount=0,ccount=0,y=0,z=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            if(i%2==1)
            {
                v[j++]=vowel[y];
                vcount++;
                if(vcount==21)
                {
                    vcount=0;
                    y++;
                }
            }
            else
            {
                c[k++]=cons[z];
                ccount++;
                if(ccount==5)
                {
                    ccount=0;
                    z++;
                }
           }
        }
        std::sort(v,v+j);
        std::sort(c,c+k);
        j=0;
        k=0;
        printf("Case %d: ",x);
        for(i=1;i<=n;i++)
        {
          if(i%2==1)
             printf("%c",v[j++]);
          else
             printf("%c",c[k++]);
        }
        printf("\n");
     }
     return 0;
 }
                