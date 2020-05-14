#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
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
long long int arr[1000001],hash[20000002];
int main()
{
	long long int t;
	inp(t);
	int mid=10000000;
	while(t--)
	{
		int i;
		long long int ans=0,n;
		inp(n);
		inp(arr[0]);
		hash[mid+arr[0]]++;
		//min=(mid+arr[0]);
		//max=(mid+arr[0]);
		for(i=1;i<n;i++)
		{
			inp(arr[i]);
		      	arr[i]+=arr[i-1];
			hash[mid+arr[i]]++;
		//	if((mid+arr[i])<min)
		//	min=mid+arr[i];
		//	if((mid+arr[i])>max)
		//	max=mid+arr[i];
		}
		for(i=0;i<=20000000;i++)
		{
			if(hash[i]!=0)
			{
				if(i!=mid)
			    	  ans+=hash[i]*(hash[i]-1)/2;
			    	  else
			    	  ans+=hash[i]+hash[i]*(hash[i]-1)/2;
			     hash[i]=0;
			}
	      }
	      output(ans);
	 }
	 return 0;
	}