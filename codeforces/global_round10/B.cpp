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


int main() {

	int t;
	in(t);
	while(t--) {
		LL n, i, k, arr[2*MAX], mx = -(INFL), mx2 = (-INFL);
		
		inl2(n, k);

		for(i = 0; i < n; i++) {
			inl(arr[i]);
			mx = max(mx, arr[i]);
		}

		for(i = 0; i < n; i++) {
			arr[i] = (mx - arr[i]);
			mx2 = max(mx2, arr[i]);
		}

		if(!(k & 1)) {
			for(i = 0 ; i < n; i++) {
				arr[i] = (mx2 - arr[i]);
			}
		}

 		for(i = 0; i < n; i++) {
 			cout<<arr[i] << " ";
 		}

 		cout<<en;
	}

	return 0;
}