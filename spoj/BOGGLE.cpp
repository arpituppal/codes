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
int score(string s2)
{
	int l1=s2.length();
	if(l1<=4)
	return 1;
	if(l1==5)
	return 2;
	if(l1==6)
	return 3;
	if(l1==7)
	return 5;
	if(l1>7)
	return 11;
}

int main()
{
	int n,i,j,k,sum,maxi=-1;
	string s,s1;
	map<string,int>m;
	vector<vector<string> >vec;
	vector<string>v1;
	inp(n);
	for(i=0;i<n;i++)
	{
		getline(cin,s);
		j=0;
		s1="";
		int l=s.length();
		while(j<l)
		{
			if(s[j]==' ')
			{
				v1.PB(s1);
				m[s1]++;
				s1="";
			}
			else
			   s1+=s[j];
			if(j==l-1)
			{
			  	v1.PB(s1);
			  	m[s1]++;
     		      }
			j++;
		}
		vec.PB(v1);
		v1.clear();
		s="";
	}
	for(i=0;i<vec.size();i++)
	{
		sum=0;
		for(j=0;j<vec[i].size();j++)
		{
			if(m[vec[i][j]]==1)
			   sum+=score(vec[i][j]);
		}
		if(sum>maxi)
		maxi=sum;
	}
	printf("%d\n",maxi);
	return 0;
}
