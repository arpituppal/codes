#include<stdio.h>
#include<string.h>
int freq[26];
int main()
{
    char s[100000],ans[100000];
    char vow[]={'a','e','i','o','u'};
    char cons[]={'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
    int position[]={0,0,1,2,1,3,4,5,2,6,7,8,9,10,3,11,12,13,14,15,4,16,17,18,19,20};
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,l,k=0,pos=0;
        scanf("%s",s);
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            freq[s[i]-97]++;
            if(s[i]=='a' || s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                k=freq[s[i]-97];
                k=k-1;
                pos=position[s[i]-97];
                ans[i]=cons[(((5*k)+pos)%21)];
            }
           else
           {
               k=freq[s[i]-97];
               k=k-1;
               pos=position[s[i]-97];
               ans[i]=vow[(((21*k)+pos)%5)];
           }
       }
       ans[i]='\0';
       printf("%s\n",ans);
       for(i=0;i<26;i++)
        freq[i]=0;
    }
    return 0;
}
