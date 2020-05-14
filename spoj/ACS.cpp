#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define getcx getchar_unlocked
using namespace std;
inline void inp(int &n) // Fast Input
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}
void output(int x)  // Fast Output
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
    int len=0,data[10];
	while(x)
	{
		data[len++]=x%10;
		x/=10;
	}
	if(!len)
		data[len++]=0;
	while(len--)
		putchar(data[len]+48);
	putchar('\n');
}
int main()
{
 	char ch;
 	int x,y,t,z,row[1234], col[5678],i,j,r,c,ans=0;
 	for(i=0;i<1234;i++)
 		row[i]=i;
 	for(i=0;i<5678;i++)
 		col[i]=i;
 	while(scanf("%c",&ch)!=EOF)
 	{
 		if(ch=='R')
 		{
 			inp(x);
 			inp(y);
 			t=row[x-1];
 			row[x-1]=row[y-1];
 			row[y-1]=t;
 		}
 		if(ch=='C')
 		{
 			inp(x);
 			inp(y);
 			t=col[x-1];
 			col[x-1]=col[y-1];
 			col[y-1]=t;
 		}
 		if(ch=='Q')
 		{
 			inp(x);
 			inp(y);
 			ans=(row[x-1])*5678+col[y-1]+1;
 			output(ans);
 		}
 		if(ch=='W')
 		{
 			inp(z);
 			z=z-1;
 			r=z/5678;
 			c=z%5678;
 			for(i=0;i<1234;i++)
 			{
 				if(row[i]==r)
 				{
 					printf("%d ",i+1);
 					break;
 				}
 			}
 			for(i=0;i<5678;i++)
 			{
 				if(col[i]==c)
 				{
 					printf("%d\n",i+1);
 					break;
 				}
 			}
 		}
 	}
 	return 0;
 }