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

	int t;
	in(t);
	while(t--) {

		int n, i, ans = 0, idxarr[2*MAX];
		string s;
		
		in(n);
		cin>>s;

		int j = n-1;

		idxarr[0] = 1;

		set<int> s0;
		set<int> s1;
		set<int>::iterator s0itr;
		set<int>::iterator s1itr;


		if(s[0] == '0') {
			s0.insert(1);
		} else {
			s1.insert(1);
		}

		int cnt = 2;

		for(i = 1; i < n; i++) {

			if(s[i] == '1') {	

				if(s0.empty()) {
					idxarr[i] = cnt;
					s1.insert(cnt);
					cnt++;
				} else {

					s0itr = s0.begin();
					idxarr[i] = *s0itr;
					s1.insert(*s0itr);
					s0.erase(s0itr);
				} 

			} else {


				if(s1.empty()) {
					idxarr[i] = cnt;
					s0.insert(cnt);
					cnt++;
				} else {

					s1itr = s1.begin();
					idxarr[i] = *s1itr;
					s0.insert(*s1itr);
					s1.erase(s1itr);
				} 
			}
		}

		for(i = 0 ; i < n; i++) {
			ans = max(ans, idxarr[i]);
		}

		cout<<ans<<en;
		for(i = 0; i < n; i++) {
			cout<<idxarr[i]<< " ";
		}

		cout<<en;

	}

	return 0;
}