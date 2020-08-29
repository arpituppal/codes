#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define getcx getchar_unlocked
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

multiset<int> row[3*MAX];
multiset<int> col[3*MAX];
int main() {

	int h, w, a, b, i, m, mxr = -1, mxc = -1, r = 0, c = 0, ans1, ans2;

	in2(h,w);
	in(m);

	for(i = 0 ; i < m ; i++) {
		in(a);
		in(b);
		row[a].insert(b);
		col[b].insert(a);
	}

	for(i = 1; i <= h; i++) {
		int sz = row[i].size();
		if(sz > mxr) {
			mxr = sz;
			r = i;
		}
	}

	for(i = 1 ; i <= w ;i++) {
		
		int sz = col[i].size();

		if(row[r].find(i) != row[r].end()) {
			sz--;
		} 

		mxc = max(mxc,sz);
		
	}

	ans1 = mxr + (mxc == -1 ? 0 : mxc);
	
	mxr = -1;
	mxc = -1;
	for(i = 1; i <= w; i++) {
		int sz = col[i].size();
		if(sz > mxc) {
			mxc = sz;
			c = i;
		}
	}

	for(i = 1 ; i <= h ;i++) {
		
		int sz = row[i].size();

		if(col[r].find(i) != col[r].end()) {
			sz--;
		} 

		mxr = max(mxr,sz);	
	}

	ans2 = mxr + (mxc == -1 ? 0 : mxc);

	cout<<max(ans1, ans2)<<en;

	return 0;
}