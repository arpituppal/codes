#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
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
int arr[1000010],ans[1000010];
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
 void rangepoint(int a[],int n)
 {
        int u,q,start,end,val;
        inp(u);
        while(u--)
        {
             inp(start);
             inp(end);
             
             update(a,n,start,1);
             update(a,n,end+1,-1*1);
        }
           
  }                       
              
int main()
{
        int n,i;
        inp(n);
        for(i=0;i<=n;i++)     
        arr[i]=0;
        rangepoint(arr,n);
        for(i=1;i<=n;i++)
        {
          ans[i-1]=query(arr,n,i);
        } 
         std::sort(ans,ans+n);
        // for(i=0;i<n;i++)
         //printf("%d ",ans[i]);
         //printf("\n");
         
         output(ans[(n/2)]);                
       
     return 0;
 }