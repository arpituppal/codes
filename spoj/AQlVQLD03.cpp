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
int arr[1000000];
void update(int arr[],int n,int idx,int val)
{
    while(idx<=n)
    {
        arr[idx]+=val;
        idx+=(idx & -idx);
    }
}
int query(int arr[],int n,int idx)
{
       int sum=0;
       while(idx>0)
       {
            sum+=arr[idx];
            idx-=(idx & -idx);
       }
      return sum;
}

int main()
{
     char s[10000];
     int n,q,i,a,b,ans1,ans2,ans;
     inp(n);
     inp(q);
     while(q--)
     {
          scanf("%s",s);
          inp(a);
          inp(b);
          if(s[0]=='f')
          {
              ans1=query(arr,n,b);
              ans2=query(arr,n,a-1);
              ans=ans1-ans2;
              output(ans);
          }
          else if(s[0]=='a')
          update(arr,n,a,b);
      }
      return 0;
 }
