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

stack<int>stk;
int mass(char c)
{
	if(c=='H')
	return 1;
	if(c=='C')
	return 12;
	if(c=='O')
	return 16;
} 
int main()
{

	char s[110];
	scanf("%s",s);
		int i,l,ans=0,m,sum=0;
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(s[i]=='C' || s[i]=='H' || s[i]=='O')
				{
				 stk.push(mass(s[i]));
				// printf("%d\n",stk.top());
				 }
			if(s[i]>=48 && s[i]<=57)
			{
				m=stk.top();
				stk.pop();
				stk.push(m*(s[i]-48));
				//printf("%d\n",stk.top());
			}
			if(s[i]=='(')
			{
				stk.push(-1);
				//printf("%d\n",stk.top());
			}
			if(s[i]==')')
			{
				sum=0;
				while(!stk.empty() && stk.top()!=-1)
				{
					
					sum+=stk.top();
					//printf("%d sum=%d\n",stk.top(),sum);
					stk.pop();
				}
				stk.pop();
				//printf("%d\n",sum);
				stk.push(sum);
			}
		}
		while(!stk.empty())
		{
			ans+=stk.top();
			stk.pop();
		}
		printf("%d\n",ans);
	return 0;
}