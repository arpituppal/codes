#include<stdio.h>
#include<string.h>
int main()
{
char a[250];
int i,j,s,d,b,sum,r,f,z,y,v,l;
while(scanf("%s",a)!=EOF)
{
    s=0,sum=0,r=0;
    f=0;
    l=strlen(a);
    for(i=0;i<l;i++)
    s=s+(a[i]-48);
 for(i=0;i<l;i++)
 {
     b=a[i]-48;
     if(b==1)
     f++;
     else if(b==2)
       {
             if((a[l-1]-48)%2==0)
             f++;
       }
     else if(b==3)
       {
           if(s%3==0)
           f++;
       }
     else if(b==4)
      {
           r=0;
           if(l==1 && b%4==0)
           f++;
           else if(l>=2)
             {
                 r=((a[l-2]-48)*10)+(a[l-1]-48);
                 if(r%4==0)
                 f++;
            }
      }
     else if(b==5)
        {
             if((a[l-1]-48)==0 || (a[l-1]-48)==5)
             f++;
        }
        else if(b==6)
        {
            if(((a[l-1]-48)%2==0) && (s%3==0))
             f++;
        }
        else if(b==7)
        {
            d=a[0]-48;
            if(l==1 && d%7==0)
            f++;
            for(j=0;j<l-1;j++)
            {
                sum=(d*3)+(a[j+1]-48);
                d=sum%7;
            }
            if(d==0)
            f++;
        }
        else if(b==8)
        {
            r=0;
            if(l==1)
            {
                if((a[0]-48)%8==0)
                    f++;
            }
            else if(l==2)
            {
                r=((a[0]-48)*10)+(a[1]-48);
                if(r%8==0)
                f++;
            }
            else if(l>=3)
            {
                z=(a[l-3]-48);
                y=(a[l-2]-48);
                v= (a[l-1]-48);
                r=z*100+y*10+v;
                 if(r%8==0)
                   f++;
          }
      }
        else if(b==9)
        {
            if(s%9==0)
            f++;
        }
  }
 printf("%d\n",f);
}
return 0;
}
