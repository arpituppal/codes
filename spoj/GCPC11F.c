#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d\n",&t);
    char s[1050],s1[1050];
    int a[26]={0};
    while(t--)
    {
        int l,i,pos,key,ans,d,max1=0,max2=0;
        gets(s);
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            d=(int)s[i];
            if(d!=32)
            a[(d-65)]++;
        }
        
        for(i=0;i<26;i++)
        {
         	if(a[i]>max2 && a[i]<=max1)
                max2=a[i];
            else if(a[i]>max1)
            {
                max2=max1;
                max1=a[i];
                pos=i;
            }
               a[i]=0;
        }
        if(max1==max2)
        printf("NOT POSSIBLE\n");
         else if(max1!=max2)
            {
            	key=pos-4;
                if(key<0)
                key=key+26;
                printf("%d ",key);
                for(i=0;i<l;i++)
                 {
                    d=(int)s[i];

                        if(d!=32)
                        {
                            ans=d-key;
                            if(ans<65)
                            ans=91-(65-ans);
                            s1[i]=(int)ans;
                         }
                         if(d==32)
                            s1[i]=' ';
                    
                   printf("%c",s1[i]);
                 }
                 printf("\n");
            }
            }
            return 0;
    }

