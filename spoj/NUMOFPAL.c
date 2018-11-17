#include<stdio.h>
#include<string.h>
char s[1001];
int main()
{
    int l,k,i,j;
    long long int p1=0,p2=0;
    scanf("%s",s);
    l=strlen(s);
    for(k=0;k<l;k++)
    {
        i=k-1;j=k+1;
        while(i>=0 && j<l)
        {
            if(s[i]!=s[j])
            break;
            p1++;
            i--;
            j++;
        }
        i=k;
        j=k+1;
        while(i>=0 && j<l)
        {
            if(s[i]!=s[j])
            break;
            p2++;
            i--;
            j++;
        }
    }
    printf("%lld\n",(p1+p2+l));
    return 0;
}
