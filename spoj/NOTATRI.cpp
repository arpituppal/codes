#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
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
int search(int a[],int val,int low,int high)
{
    int mid,x;
    while(low<=high)
    {
            mid=(low+high)/2;
            if(a[mid]==val)
            low=mid+1;
            else if(a[mid]<val)
            low=mid+1;
            else
            high=mid-1;
    }
   if(a[mid]<=val)
    return(mid+1);
    else
    return mid;
}
int main()
{

   int n,i,j,k,ans=0,x,a[2001];
    while(1)
    {
        ans=0;
        inp(n);
        if(n==0)
        break;
        for(i=0;i<n;i++)
        inp(a[i]);
        sort(a,a+n);
        for(i=0;i<n-2;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                k=a[i]+a[j];
                x=search(a,k,j+1,n-1);
                ans+=(n-x);
            }
        }
        output(ans);
    }
    return 0;
}
