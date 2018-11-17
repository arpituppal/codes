#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define getcx getchar_unlocked
using namespace std;
inline void inp(long long int &n) // Fast Input
{
	n=0;
	long long int ch=getcx();long long int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}
int main()
{
     long long int t;
     inp(t);
     while(t--)
     {
           long long int n,i,j,m,flag=0;
           inp(n);
           m=sqrt(n);
           i=0;j=m;
           while(i<=j)
           {
                if((i*i)+(j*j)==n)
                {
                    flag=1;
                    break;
                }
                else if((i*i)+(j*j)<n)
                i++;
                else
                j--;
          }
          if(flag==1)
          printf("Yes\n");
          else
          printf("No\n");
      }
      return 0;
 }      