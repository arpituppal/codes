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
inline void inp1( LL &n )
{
n=0; LL ch=getcx();LL sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
n=n*sign;
}

char s[50][50],arr[50][50],sans[50][50];
int ans[50][50],r,c;

int safe(int x,int y)
{
	if(x>=0 && x<r && y>=0 && y<c)
	return 1;
	return 0;
}
int main()
{
	int i,j,firstx,lastx,flag=0,cnt=0,lcnt=0;
	inp(r);
	inp(c);
	for(i=0;i<r;i++)
	scanf("%s",s[i]);
	
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			//arr[i][j]='.';
			if(s[i][j]=='.')
			arr[i][j]=s[i][j];
			else
			{
				int one=safe(i,j+1);
				if(one==0)
				one=1;
				else
				{ 
					if(s[i][j+1]=='.') one=1; 
					else one=0;
				}
				int two=safe(i,j-1);
				if(two==0)
				two=1;
				else
				{ 
					if(s[i][j-1]=='.') two=1; 
					else two=0;
				}
				int three=safe(i-1,j);
				if(three==0)
				three=1;
				else
				{ 
					if(s[i-1][j]=='.') three=1; 
					else three=0;
				}
				int four=safe(i+1,j);
				if(four==0)
				four=1;
				else
				{ 
					if(s[i+1][j]=='.') four=1; 
					else four=0;
				}
				if(one+two+three+four>=3)
				arr[i][j]='.';
				else
				arr[i][j]='X';
			}
		}
	}
	//printf("%c\n",arr[0][0]);
	
	/*for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		printf("%c",arr[i][j]);
		printf("\n");
	}
	*/
	//rowwise
	for(i=0;i<r;i++)
	{
		firstx=-1;
		lastx=-1;
		for(j=0;j<c;j++)
		{
			if(arr[i][j]=='X')
			{firstx=j;break;}
		}
		for(j=c-1;j>=0;j--)
		{
			if(arr[i][j]=='X')
			{lastx=j;break;}
		}
		
		if(firstx==-1)
		continue;
			
		for(j=firstx;j<=lastx;j++)
		ans[i][j]=1;
	}

	//remove unnecesary rows above 1st necessary row	
 	for(i=0;i<r;i++)
 	{
		cnt=0;
		for(j=0;j<c;j++)
		{
			if(ans[i][j]==1)
			cnt++;
		}
		if(cnt==0 && lcnt==0) //we can remove this row		
		{
			for(j=0;j<c;j++)
			ans[i][j]=-1;
		}
		lcnt=cnt;
		if(cnt!=0)
		break;
	}
	
	
	//removing uneccesary rows below last necesaryy row
	lcnt=0;
	for(i=r-1;i>=0;i--)
 	{
		cnt=0;
		for(j=0;j<c;j++)
		{
			if(ans[i][j]==1)
			cnt++;
		}
		if(cnt==0 && lcnt==0) //we can remove this row		
		{
			for(j=0;j<c;j++)
			ans[i][j]=-1;
		}
		lcnt=cnt;
		if(cnt!=0)
		break;
	}
	
	//removing unecearry column before 1st necesarry column
	lcnt=0;
	for(i=0;i<c;i++)
	{
		cnt=0;
		for(j=0;j<r;j++)
		{
			if(ans[j][i]==1)
			cnt++;
		}
		if(cnt==0 && lcnt==0)
		{
			for(j=0;j<r;j++)
			ans[j][i]=-1;
		}
		lcnt=cnt;
		if(cnt!=0)
		break;
	}

	//after last necesaary column
	lcnt=0;
	lcnt=0;
	for(i=c-1;i>=0;i--)
	{
		cnt=0;
		for(j=0;j<r;j++)
		{
			if(ans[j][i]==1)
			cnt++;
		}
		if(cnt==0 && lcnt==0)
		{
			for(j=0;j<r;j++)
			ans[j][i]=-1;
		}
		lcnt=cnt;
		if(cnt!=0)
		break;
	}
	
	
	int row=0,col=0;
/*	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(ans[i][j]!=-1)
			sans[row][col++]=arr[i][j];
		}
		row++;
		col=0;
	}
	printf("row= %d col=%d\n",row,col);
	/*for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		printf("%c",sans[i][j]);
		printf("\n");
	}*/

	for(i=0;i<r;i++)
	{
		flag=0;
		for(j=0;j<c;j++)
		{
			if(ans[i][j]!=-1)
			{flag=1; printf("%c",arr[i][j]);}
		}
		if(flag==1)
		{flag=0; printf("\n");}
	}
		
	return 0;
}