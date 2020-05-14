#include<stdio.h>
#include<string.h>
int main()
{
  int p,x;
  scanf("%d",&p);
  for(x=1;x<=p;x++)
  {
     int n,d,i;
     int b=0,c=0,e=0,f=0,g=0,h=0,y=0,z=0;
     char a[45];
     scanf("%d",&n);
     scanf("%s",a);
     d=strlen(a);
     for(i=0;i<d-2;i++)
     {
       if(a[i]=='T'&& a[i+1]=='T' && a[i+2]=='T')
       b++;
       else if(a[i]=='T'&& a[i+1]=='T' && a[i+2]=='H')
       c++;
       else if(a[i]=='T'&& a[i+1]=='H' && a[i+2]=='T')
       e++;
       else if(a[i]=='T'&& a[i+1]=='H' && a[i+2]=='H')
       f++;
       else if(a[i]=='H'&& a[i+1]=='T' && a[i+2]=='T')
       g++;
       else if(a[i]=='H'&& a[i+1]=='T' && a[i+2]=='H')
       h++;
       else if(a[i]=='H'&& a[i+1]=='H' && a[i+2]=='T')
       y++;
       else if(a[i]=='H'&& a[i+1]=='H' && a[i+2]=='H')
       z++;
     }
      printf("%d %d %d %d %d %d %d %d %d\n",n,b,c,e,f,g,h,y,z);
    }
     return 0;
     }
