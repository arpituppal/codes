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
#define MAX 1000001
#define in(x) scanf("%d", &x)
#define inl(x) scanf("%lld", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define inl2(x, y) scanf("%lld %lld", &x, &y)
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

inline void inp( int &n ) { 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

inline void inp1( LL &n ) { 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

LL l[MAX], h[MAX], p[MAX];

bool isOverlap(LL oldL, LL w, LL newl) {
	return newl <= (oldL + w) ;
}

int main() {

	int t;
	inp(t);
	for(int x = 1; x <= t; x++) {

		LL n, k, w, al, bl, cl, dl, ah, bh, ch, dh, ans = 1;
		int i, j = 0;
		multiset<LL, greater<LL> > mset;

		inp1(n);
		inp1(k);
		inp1(w);

		for(i = 0; i < k; i++) {
			inp1(l[i]);
		}

		inp1(al);
		inp1(bl);
		inp1(cl);
		inp1(dl);

		for(i = 0; i < k; i++) {
			inp1(h[i]);
		}

		inp1(ah);
		inp1(bh);
		inp1(ch);
		inp1(dh);

		for(i = k; i < n; i++) {
			l[i] = ((al * l[i-2]) %dl + (bl * l[i-1]) %dl + cl) % dl + 1;
			h[i] = ((ah * h[i-2])% dh + (bh * h[i-1]) %dh + ch) % dh + 1;
		}

		p[0] = (2* (w + h[0])) % MOD;
		mset.insert(h[0]);
		ans = p[0];

		for(i = 1; i < n; i++) {
			
			bool overlap = isOverlap(l[i-1], w, l[i]);

			if(!overlap) {
				mset.clear();
				j = i;
			} else {
				while(j < i) {
				
					if(l[j] + w >= l[i]) break;
					
					mset.erase(mset.find(h[j]));
					j++;
				}
			}

			LL topval = (*mset.begin());
			// p[i] = p[i-1];

			// if(overlap) {

			// 	LL hdiff;
			// 	if(h[i] <= topval) hdiff = 0;
			// 	else hdiff = h[i] - topval;

			// 	p[i] = (p[i] + (2 * (l[i] - l[i-1] + hdiff))) %MOD;

			// } else {
			// 	p[i] = (p[i] + (2 * (w + h[i])))%MOD;
			// }

			p[i] = (p[i-1] + (overlap ? (2 * (l[i] - l[i-1] + (h[i] <= topval ? 0 : (h[i] - topval)))) : (2 * (w + h[i]))) % MOD) % MOD;
			mset.insert(h[i]);

			ans = (ans * p[i]) % MOD;
		}

		// for(i = 0 ; i < n; i++) {
		// 	ans = (ans * p[i]) % MOD;
		// }

		printf("Case #%d: %lld\n", x, ans);

		//cout<<"Case #"<<x<<": "<<ans<<en;
	}

	return 0;
}