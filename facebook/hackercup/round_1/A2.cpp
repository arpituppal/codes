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

LL l[MAX], h[MAX], p[MAX], w[MAX];
int main() {

	int t;
	in(t);
	for(int x = 1; x <= t; x++) {

		LL i, n, k, al, bl, cl, dl, ah, bh, ch, dh, aw, bw, cw, dw, ans = 1, j = 0, minst = -1, mxend = -1;
		
		set<pair<LL,LL> > startset;
		set<pair<LL,LL > > endset;

		inl2(n, k);

		for(i = 0; i < k; i++) {
			inl(l[i]);
		}

		inl2(al, bl);
		inl2(cl, dl);

		for(i = 0 ; i < k ; i++) {
			inl(w[i]);
		}

		inl2(aw, bw);
		inl2(cw, dw);

		for(i = 0; i < k; i++) {
			inl(h[i]);
		}

		inl2(ah, bh);
		inl2(ch, dh);

		for(i = k; i < n; i++) {
			l[i] = ((al * l[i-2]) %dl + (bl * l[i-1]) %dl + cl) % dl + 1;
			w[i] = ((aw * w[i-2]) %dw + (bw * w[i-1]) %dw + cw) % dw + 1;
			h[i] = ((ah * h[i-2])% dh + (bh * h[i-1]) %dh + ch) % dh + 1;
		}

		p[0] = (2 * (w[0] + h[0])) % MOD;
		minst = l[0];
		mxend = l[0] + w[0];
		startset.insert(MP(l[0], l[0] + w[0]));
		endset.insert(MP(l[0] + w[0], l[0]));

		for(i = 1; i < n; i++) {

			if(l[i] + w[i] < minst || l[i] > mxend) {
				p[i] = (p[i-1] + 2 * (w[i] + h[i])) % MOD;
				minst = min(l[i], minst);
				mxend = max(mxend, l[i] + w[i]);
				startset.insert(MP(l[i], l[i] + w[i]));
				endset.insert(MP(l[i] + w[i], l[i]));

				continue;
			} 

			auto low = lower_bound(endset.begin(), endset.end(), MP(l[i], l[i]+w[i]));
			auto high = upper_bound(startset.begin(), startset.end(), MP(l[i] + w[i], l[i]));
			
			if(low != endset.end() && high != startset.end() && (*low).first == (*high).first && (*low).second == (*high).second) {
				//non-overlap
				p[i] = (p[i-1] + 2 * (w[i] + h[i])) % MOD;
				minst = min(l[i], minst);
				mxend = max(mxend, l[i] + w[i]);
				startset.insert(MP(l[i], l[i] + w[i]));
				endset.insert(MP(l[i] + w[i], l[i]));

			} else {

				p[i] = p[i-1];

				while(true) {
					auto nxt = low++;

					if(nxt == high) {
						p[i] = p[i] + (l[i] + w[i] - (*low).first);

						break;
					}

					p[i] = p[i] + (*nxt).second - (*low).first;
					startset.erase(low);
					endset.erase(low);
					low = cnt;
				}

				startset.insert()

			}

		}
	}

}