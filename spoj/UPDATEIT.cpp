#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define getcx getchar_unlocked
using namespace std;
inline void inp(long long &n) // Fast Input
{
	n=0;
	long long ch=getcx();long long sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
} 
void output(long long int x)  // Fast Output
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	long long int len=0,data[10];
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
void update(long long int arr[],long long int n,long long int idx,long long int val)
{   
    while(idx<=n)
    {   
        arr[idx]+=val;
        idx+=(idx & -idx);
    }
}
long long int query(long long int arr[],long long int n,long long int idx)
{
       long long int sum=0;
       while(idx>0)
       {
            sum+=arr[idx];
            idx-=(idx & -idx);
       }
      return sum;
}         
/*void pointrange(long long int arr[],long long int n)
{
    long long int idx,val,start,end,q;
    inp(q);
    while(q--)
    {
        inp(idx);
        inp(val);
        update(arr,n,idx,val);
         
  */ 
 void rangepoint(long long int arr[],long long int n)
 {
        long long int u,q,start,end,val,idx;
        inp(u);
        while(u--)
        {
             inp(start);
             inp(end);
             inp(val);
             update(arr,n,start+1,val);
             update(arr,n,end+2,-1*val);
         }
             inp(q);
             while(q--)
             {
                inp(idx);
                output(query(arr,n,idx+1));
             }
  }                       
              
int main()
{
     long long int arr[1000000],n,t,i;
     inp(t);
     while(t--)
     {
        inp(n);
        for(i=0;i<=n;i++)     
        arr[i]=0;
        rangepoint(arr,n);
     }
     return 0;
 }