#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<stdio.h>
#define getcx getchar_unlocked
#define clr(x) memset(x,0,sizeof(x))
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
struct Node
{
    int next[10];
    int flag;
};
Node nodes[100010];
int allocated=1;
int insert(char *str)
{
    int curr=0,idx=0,i;
    while(str[idx]!='\0')
    {
        if(nodes[curr].next[str[idx]-'0']==0)
        {   
            nodes[curr].next[str[idx]-'0']=allocated++;
            curr=allocated-1;
        }
        else
        {
            curr=nodes[curr].next[str[idx]-'0'];
            if(nodes[curr].flag==1)
            return 1;
        }
        idx++;
    }
     for(i=0;i<10;i++)
     {
        if(nodes[curr].next[i]>0)
        return 1;
     }
     nodes[curr].flag=1;
       
    return 0;
}        
        
int main()
{
    int t,i,s,val,f=0;
    char str[50];
    inp(t);
    while(t--)
    {
        f=0;
        clr(nodes);
        inp(i);
        while(i--)
        {
            
            scanf("%s",str);
            val=insert(str);
            if(val==1)
            f=1;
        }
        if(f==1)
        puts("NO");
        else
        puts("YES");    
        allocated=1;
    }   
    return 0;
}