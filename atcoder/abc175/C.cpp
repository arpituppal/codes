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


int main() {

	LL x, k, d, ans = 0;
	
	cin>>x>>k>>d;

	if(x == 0) {

		if(k % 2 == 0) cout<<0<<endl;
		else cout<<x+d<<endl;

		return 0;
	}

	if(x < 0) x = -x;



		LL q = min(k, x/d);
		k-=q;
		x = x - q*d;

		if(k % 2 == 0) cout<<x<<endl;
		else cout<<min(x + d, abs (x-d))<<endl;

		return 0;
	

	
}