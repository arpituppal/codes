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

LL gcd(LL a, LL b) {

	if(a < b) return gcd(b,a); 
	if(b == 0) 	return a;
	return gcd(b, a %b);
}


int main() {

	LL n, i, j, ans = 0;
	inl(n);

	vector<LL> vec;
	queue<LL> q;

	if(n >=4) q.push(4);
	if(n >=7) q.push(7);

	while(!q.empty()) {

		LL num = q.front();
		q.pop();

		vec.PB(num);

		if(num * 10 + 4 <= n) q.push(num * 10 + 4);
		if(num * 10 + 7 <= n) q.push(num * 10 + 7);
	}

	int sz = vec.size();

	for(i = 0 ; i < sz; i++) {

		for(j = i+1; j < sz; j++) {

			if(gcd(vec[i], vec[j]) == 1) ans++;
		}
	}

	cout<<ans<<endl;
	return 0;
}