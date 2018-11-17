#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<bitset>
#include<stack>
#include<stdio.h>
#include<queue>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define in(x) scanf("%d",&x)
#define inll(x) scanf("%lld", &x)
#define MOD 1000000007 // 10**9 + 7
#define INF 1e9
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define For(i, a, b) for (int i = a; i <b; i++)
#define Rfor(i, b, a) for (int i = b; i> a; i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long l;
using namespace std;
const double pi = acos(-1.0);
int main()
{
int n;
scanf("%d",&n);
vector<pair<int,int> >v;
int arr[100003]={0};
while(n--)
{
int a,b;
scanf("%d%d",&a,&b);
v.pb(mp(a,b));
}
sort(v.begin(),v.end());
ll ans=0;
for(int i=v.size()-1;i>=0;i--)
{
int d=v[i].second;
while(d)
{
if(!arr[d])
{
arr[d]=1;
ans+=v[i].first;
break;
}
else
d--;
}
}
printf("%lld\n",ans);
return 0;
}
