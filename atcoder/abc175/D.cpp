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

vector<LL> vec[5001];
LL visited[5001], c[5001], p[5001];
LL n, k, ans = -(INFL);

void dfs(LL currnode, LL currsum, LL k) {

	if(k == 0) return;

	visited[currnode] = 1;

	ans = max(ans, currsum + c[currnode]);

	for(int i =0 ; i< vec[currnode].size(); i++) {
		if(!visited[vec[currnode][i]]) {
			dfs(vec[currnode][i], currnode + c[currnode], k-1);
		}
	}
}

int main() {

	cin>>n>>k;
	int i;
	
	for(i = 0 ; i < n;i++) {
		cin>>p[i];
	}

	for(i = 0 ; i < n;i++) {
		cin>>c[i];
		ans = max(ans, c[i]);
	}

	for(i = 0 ; i < n; i++) {
		vec[i].PB(p[i]-1);
	}

	for(i = 0; i < n; i++) {
		if(!visited[i]) {
			dfs(i, 0, k);
		}
	}

	cout<<ans<<endl;
	return 0;
}

