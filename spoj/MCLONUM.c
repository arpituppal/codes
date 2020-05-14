#include<stdio.h>
#include<string.h>
int hash[10],hash1[10];
char a[100],b[100],gre[100],less[100];
int main()
{
    int i,l1,l2,k=0,j=0,flag=0,h,h1,z,flag2=0,flag3=0,flag4=0,great,sm;
    scanf("%s %s",a,b);
    l2=strlen(b);
    l1=strlen(a);
    for(i=0;i<l2;i++)
      {
          hash[b[i]-48]++;
          hash1[b[i]-48]++;
      }
    int first=a[0]-48;
    if(hash[first]==0)    //if first digit of a is not in b
    {
        for(i=first+1;i<10;i++)   //finding just greater digit than first digit of 'a'
        {
            if(hash[i]>0)
            {
                flag=1;
                 gre[0]=i+48;
                 hash[i]--;
                 h1=i;
                break;
            }
        }
        if(flag==1)
        {
            j=1;
            for(i=0;i<10;i++)        //making just greater number than a
            {
                h=hash[i];
                while(h>0)
                {
                    gre[j++]=i+48;
                    h--;
                }
            }
            gre[j++]='\0';
             hash[h1]++;
        }
        else      //if just greater digit doesn't exist
        {
            gre[0]='0';
            gre[1]='\0';
        }
        flag=0;
        for(i=first-1;i>0;i--)     //finding just smallest digit
        {
            h=hash[i];
            if(h>0)
            {
                flag=1;
                less[0]=i+48;
                hash[i]--;
                h1=i;
               break;
            }
        }
        if(flag==1)
        {
            k=1;
            for(i=9;i>=0;i--)
            {
                h=hash[i];
                while(h>0)
                {
                    less[k++]=i+48;
                    h--;
                }
            }
            less[k++]='\0';
             hash[h1]++;
        }
        else
        {
            less[0]='0';
            less[1]='\0';
        }
    }              //working fine
    else           //1st digit same as b
    {
       flag=1;
       int digit,flag1=0;
       for(i=0;i<l1;i++)
       {
          // printf("%d\n",l1);
           digit=a[i]-48;
           //printf("%c %d\n",a[i],digit);
           if(hash[digit]>0)     //making eqaul as far as possible
           {
               gre[j++]=digit+48;
               less[k++]=digit+48;
               hash[digit]--;
               hash1[digit]--;
           }
           else
           {
               flag=0;
               break;
           }
       }
      // printf("flag %d\n",flag);
        if(flag==0)             //case 1 breaks out in middle
        {
           // printf("digit=%d\n",digit);
            for(i=digit+1;i<10;i++)    //search for next higher digit for greater
            {
                if(hash[i]>0)       //case 1.1 available
                {
                    flag1=1;
                    gre[j++]=i+48;    //insert it
                    h1=i;
                    hash[i]--;
                    break;
                }
            }
            if(flag1==1)
            {
                for(i=0;i<10;i++)       //making greater number for case 1.1
                {
                    h=hash[i];
                    while(h>0)
                    {
                        gre[j++]=i+48;
                        h--;
                    }
                }
                gre[j++]='\0';
                hash[h1]++;
            }   //greater number made for case 1.1
            for(i=digit-1;i>=0;i--)  //finding next smallest digit
            {
                if(hash[i]>0)   //next smaleest digit found
                {
                    h1=i;
                    flag3=1;
                    less[k++]=i+48;
                    hash[i]--;
                    break;
                }
            }
            if(flag3==1)   //case 1.1 available
            {
                for(i=9;i>=0;i--)
                {
                    h=hash[i];
                    while(h>0)
                    {
                        less[k++]=i+48;
                        h--;
                    }
                }
                less[k++]='\0';
                hash[h1]++;
            }
        }
        if(flag1==0 && flag!=1)  //case 1.2 case 2 NEW!=original or next higher digit not available for greater
            {
               // printf("Yes for j=%d\n",j);
                j=j-1;
                while(j>=0)  //backtrack
                {
                    digit=gre[j]-48;
                    hash[digit]++;
                    for(z=digit+1;z<10;z++) //finding next higher digit
                    {
                        if(hash[z]>0)  //next higher digit found while backtracking
                        {
                            h1=z;
                            flag2=1;
                            gre[j++]=z+48;
                            hash[z]--;
                            break;
                        }
                    }
                    if(flag2==1)
                    {
                        for(z=0;z<10;z++)
                        {
                            h=hash[z];
                            while(h>0)
                            {
                                gre[j++]=z+48;
                                h--;
                            }
                        }
                        gre[j++]='\0';
                        hash[h1]++;
                        break;
                    }
                    j--;
                }
                if(flag2==0)
                {
                    gre[0]='0';
                    gre[1]='\0';
                }
            }  //GREATER NO MADE BY ALL POSSIBLE CASEs
        if(flag==1 || flag3==0)   //case 1.2 or case 2 for less
        {
           // printf("yesfor k=%d\n",k);
            k=k-1;
            while(k>=0)  //backtrack
            {
               // printf("1=%d 3=%d\n",hash[1],hash[3]);
                digit=less[k]-48;
                hash1[digit]++;
                for(z=digit-1;z>=0;z--)
                {
                    if(hash1[z]>0)
                    {
                       // printf("dig=%d k=%d\n",z,k);
                        h1=z;
                        flag4=1;
                        less[k++]=z+48;
                        hash1[z]--;
                        break;
                    }
                }
                if(flag4==1)
                {
                    for(z=9;z>=0;z--)
                    {
                        h=hash1[z];
                        while(h>0)
                        {
                            less[k++]=z+48;
                            h--;
                        }
                    }
                    less[k++]='\0';
                    hash1[h1]++;
                    break;
                }
                k--;
            }
            if(flag4==0)
            {
                less[0]='0';
                less[1]='\0';
            }
        }   //LESSER NO MADE BY ALL POSSIBLE CASE
    }
printf("%s\n%s\n",gre,less);
return 0;
}
