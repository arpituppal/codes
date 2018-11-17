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

int main()
{
    int t;
    scanf("%d",&t);
    char ch=getchar();
    //cout<<t;
    while(t--)
    {
    		
    		
        	string s;
        	int l,i,j,gamen=0,gamed=0,pointn=0,pointd=0,advn=0,advd=0,tien=0,tied=0,flag=0;
       	getline(cin,s);
       	//cout<<s<<endl;
       	l=s.length();
       	//cout<<s<<endl;
       	for(i=0;i<l;i++)
       	{
       		//cout<<s[i];
       		if(flag==0)
       		{	//no tiebreaker going on
       		
       		if(s[i]=='N')
       		{
       			if(pointn!=3)
       			pointn++;
       			
       			else if(pointn==3 && pointd!=3)	//if nadal was on 40, he win game if djoko was not on 40 not on advantage
       			{
       				pointn=0;
       				gamen++;
       				pointd=0;
       				advn=0;
       				advd=0;
       			}
       			else if(pointn==3 && pointd==3)
       			{
       				if(advn==1)   //he was on adv
       				{
       					advn=0;
       					pointd=0;
       					pointn=0;
       					advd=0;
       					gamen++;
       				}
       				else    //nadal was on 40 but not on advantage
       				{
       					//2 cases- either djoker was on advntge or it was deuce 
       					if(advd==1)
       					advd=0;
       					else
       					advn=1;
       				}
       			}
       			
       			if(gamen==6 && gamed==6)
       			flag=1;
       		}
       		else if(s[i]=='D')
       		{
       		
       			if(pointd!=3)
       			pointd++;
       			
       			else if(pointd==3 && pointn!=3)	//if nadal was on 40, he win game if djoko was not on 40 not on advantage
       			{
       				pointd=0;
       				gamed++;
       				pointn=0;
       			}
       			else if(pointd==3 && pointn==3)
       			{
       				if(advd==1)   //he was on adv
       				{
       					advd=0;
       					pointd=0;
       					pointn=0;
       					gamed++;
       				}
       				else    //nadal was on 40 but not on advantage
       				{
       					//2 cases- either djoker was on advntge or it was deuce 
       					if(advn==1)
       					advn=0;
       					else
       					advd=1;
       				}
       			}
       			
       			if(gamen==6 && gamed==6)
       			flag=1;
       		}
       	}
       	
       	else if(flag==1)
       	{
       		if(s[i]=='N')
       		{
       			tien++;
       			if(tien>tied && tien>=7 && (tien-tied)>=2)
       			{
       				gamen++;
       			
       				advn=0;
       				advd=0;
       				pointn=0;
       				pointd=0;
       			}
       		}
       		else if(s[i]=='D')
       		{
       			tied++;
       			if(tied>tien && tied>=7 && (tied-tien)>=2)
       			{
       				gamed++;   		
       				advn=0;
       				advd=0;
       				pointn=0;
       				pointd=0;
       			}
       		}
       	}
       }
       
    if(flag==0)	//no tie breaker
       {
       	if(gamen >gamed)
       	printf("N %d\nD %d\n",gamen,gamed);
       	else
       	printf("D %d\nN %d\n",gamed,gamen);
       }
       else if(flag==1)
       {
       	if(gamen==7)	//tiebreaker won by nadal
       	printf("N %d (%d-%d)\nD %d\n",gamen,tien,tied,gamed);
       	else
       	printf("D %d (%d-%d)\nN %d\n",gamed,tied,tien,gamen);
       }
      }
      return 0;
     }

       	
       		
       			
