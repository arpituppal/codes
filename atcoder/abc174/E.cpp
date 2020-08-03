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
#define finish(x) {cout<<x<<'\n'; return;}
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';


void solve() {
	LL n, k;
	inl2(n, k);
	
	LL a[n];
	for(int i=0;i<n;i++) inl(a[i]);
	
	if(k == 0) {
		LL maxi = -1;
		for(int i=0;i<n;i++) maxi = max(maxi, a[i]);
		finish(maxi);
	}
	
	LL low=1, high=1e9 + 5, ans = 0;
	while(low <= high) {
		LL mid = (low+high) >> 1; //every log of max "mid" length
		LL cuts = 0;
		for(int i=0;i<n;i++) {
			if(a[i] >= mid) cuts += (a[i]/mid);
			if(a[i] > 0 && a[i] % mid == 0) cuts--;
		}
		
		if(cuts > k) {
			low = mid + 1;
		} else {
			ans = mid;
			high = mid - 1;
		}
	}
	
	cout<<ans<<en;
}

int main() {

	solve();
	return 0;
}