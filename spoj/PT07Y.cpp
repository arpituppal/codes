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
int visited[10010],count,flag;
struct node
{
    int data;
    struct node *next;
};
struct node *start[10010];

struct node *insert(struct node *start,int val)
{   
    struct node *p=start;
    while(p!=NULL)
     {
        if(p->data==val)
        {
            flag=1;
            return start;
        }
        p=p->next;
     }
     struct node *temp=(struct node *)malloc(sizeof(struct node));
     temp->data=val;
     temp->next=start;
     start=temp;
     return start;
 }
 void dfs(struct node *startx,int u)
 { 
    if(startx==NULL)
    return ;
    if(visited[u]==1)
    {
        flag=1;
        return ;
    }
    visited[u]=1;
    count++;
    struct node *p=startx;
    while(p!=NULL)
    {
        if(visited[p->data]==0)
        dfs(start[p->data],p->data);
        p=p->next;
    }
 }
int main()
{
    int n,e,u,v,min=1000000;
    inp(n);
    inp(e);
    if(e==0)
    {
        if(n==1)
        puts("YES");
        else
        puts("NO");
        return 0;
    }
    if(e!=n-1)
    {
        while(e--)
        {
            inp(u);
            inp(v);
        }
        puts("NO");
        return 0;
    }
    while(e--)
    {   
        inp(u);
        inp(v);
        if(u==v)
        flag=1;
        if(u<min)
        min=u;
        if(v<min)
        v=min;
        start[u]=insert(start[u],v);
        start[v]=insert(start[v],u);
     }
     if(flag==1)
     puts("NO");
     else
     {
        dfs(start[min],min);
        if(count==n)
        puts("YES");
        else
        puts("NO");
    }
    return 0;
 }