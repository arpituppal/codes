#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <sstream>
#include <utility>
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;
typedef long long LL;
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define PB push_back
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))
inline void inp( int &n )
{
n=0; int ch=getcx();int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
} 
int hash(char s[])
{
	int i,res=0;
	for(i=0;s[i]!='\0';i++)
	res+=((int)s[i]*(i+1));
	return (19*res)%101;
}
int main()
{
	int t;
	inp(t);
	while(t--)
	{
		int n,i,j;
		
		inp(n);
		map<string,int>si;
		map<int,string>is;
		for(i=1;i<=n;i++)
		{
		char op[3],key[1000],s[1000];
			scanf("%s",s);
			int l=strlen(s);
			for(j=0;j<3;j++)
			op[j]=s[j];
			op[j]='\0';
			for(j=4;j<l;j++)
			key[j-4]=s[j];
			key[j-4]='\0';
			//printf("key== %s op==%s\n",key,op);
			if(op[0]=='A')
			{
				if((si.find(key)!=(si.end())))  //already existing key
				continue;
				for(j=0;j<20;j++)
				{
					int value=(j*j+ 23*j+ hash(key))%101;
					if(!(is.find(value)!=(is.end())))  //if doesn't exist
					{
						si[key]=value;
						is[value]=key;
						break;
					}
				}
			}
			else
			{
				if(!(si.find(key)!=(si.end()))) // if key to be deleted doesn't exists
				continue;
				int value=si[key];
				si.erase(key);
				is.erase(value);
			}
		}
		printf("%d\n",is.size());
		  for (map<int,string>::iterator i=(is).begin(); i != (is).end(); ++i)
		cout<<i->first<<":"<<i->second<<endl;
	}
	return 0;
}