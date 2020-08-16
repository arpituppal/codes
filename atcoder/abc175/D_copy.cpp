#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MSV(A,a) memset(A, a, sizeof(A))
#define MP make_pair
#define PB push_back
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define MOD 1000000007
#define MAX 100005
#define in(x) scanf("%d", &x)
#define inl(x) scanf("%lld", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define inl2(x, y) scanf("%lld %lld", &x, &y)
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

vector<LL> vec[5001], vrev[5001];
vector<LL> connectedNodes[5001];
stack<LL>stk;

LL visited[5001], c[5001], p[5001];
LL n, k, ans = -(INFL);


void dfs(int curr)
{
	int i;
	visited[curr]=1;
	for(i=0;i<vec[curr].size();i++)
	{
		if(!visited[vec[curr][i]])
		dfs(vec[curr][i]);
	}
	stk.push(curr);
}
void dfsr(int curr,int num)
{
	int i;
	visited[curr]=1;
	connectedNodes[num].PB(curr);

	for(i=0;i<vrev[curr].size();i++)
	{
		if(!visited[vrev[curr][i]])
		dfsr(vrev[curr][i],num);
	}
}


int main() {

	cin>>n>>k;
	int i, num = 0;
	
	for(i = 0 ; i < n;i++) {
		cin>>p[i];
	}

	for(i = 0 ; i < n;i++) {
		cin>>c[i];
		ans = max(ans, c[i]);
	}

	for(i = 0 ; i < n; i++) {
		vec[i].PB(p[i]-1);
		vrev[p[i]-1].PB(i);
	}

	for(i=0;i<n;i++)
	{
		if(!visited[i])
		dfs(i);
	}

	for(i=0;i<n;i++)
	visited[i]=0;
	
	while(!stk.empty()) {
		int curr=stk.top();
		stk.pop();
		if(!visited[curr])
			dfsr(curr,num++);
	}


	for(i = 0; i < num; i++) {
	
		vector<LL> cost;
		LL sum = 0, lmax = -(INFL);

		for(j = 0; j < connectedNodes[i].size(); j++) {	
			cost.PB(c[connectedNodes[i][j]]);
		}

		sort(cost.begin(), cost.end());

		for(j = cost.size() -1; j>=0; j--) {

			
		}

	}
}