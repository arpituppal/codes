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

vector<int> vec[1001];
int h, w, cx, cy, dx, dy, ans[1001][1001];
char s[1001][1001];

priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, greater<pair<int, pair<int,int> > > > pq;

bool isValid(int x, int y) {
	return x >=0 && x < h && y >=0 && y < w && s[x][y] == '.';
}

void dijsktra(int sx, int sy) {

	ans[sx][sy] = 0;
	pq.push(MP(0, MP(sx, sy)));

	while(!pq.empty()) {

		int currcost = pq.top().first;
		int currx = pq.top().second.first;
		int curry = pq.top().second.second;
		pq.pop();

		//cout<<currx << " " <<curry<< " " <<currcost << endl;

		int nextx, nexty, newcost;
		nextx = currx - 1;
		nexty = curry;
		newcost = currcost;

		if(isValid(nextx, nexty) && newcost < ans[nextx][nexty]) {
			ans[nextx][nexty] = newcost;
			pq.push(MP(newcost, MP(nextx, nexty)));
		}
		
		nextx = currx + 1;
		nexty = curry;
		
		if(isValid(nextx, nexty) && newcost < ans[nextx][nexty]) {
			ans[nextx][nexty] = newcost;
			pq.push(MP(newcost, MP(nextx, nexty)));
		}

		nextx = currx;
		nexty = curry - 1;
		
		if(isValid(nextx, nexty) && newcost < ans[nextx][nexty]) {
			ans[nextx][nexty] = newcost;
			pq.push(MP(newcost, MP(nextx, nexty)));
		}

		nextx = currx;
		nexty = curry + 1;
		
		if(isValid(nextx, nexty) && newcost < ans[nextx][nexty]) {
			ans[nextx][nexty] = newcost;
			pq.push(MP(newcost, MP(nextx, nexty)));
		}

		for(int i = -2; i <=2 ;i++) {
			for(int j = -2; j <= 2; j++) {
				if(!(i ==0 && j==0)) {
					nextx = currx + i;
					nexty = curry + j;
					newcost = currcost + 5;

					if(isValid(nextx, nexty) && newcost < ans[nextx][nexty]) {
						ans[nextx][nexty] = newcost;
						pq.push(MP(newcost, MP(nextx, nexty)));
					}
				}
			}
		}
	}
}

int main() {

	int i, j, k;

	in2(h,w);
	in2(cx,cy);
	in2(dx, dy);

	for(i = 0; i < h; i++) {
		scanf("%s", s[i]);
	}

	for(i = 0; i < h; i++) {
		for(j = 0; j < w; j++) {
			ans[i][j] = INF;
		}
	}

	dijsktra(cx-1, cy-1);

	if(ans[dx-1][dy-1] == INF) cout<<"-1"<<en;
	else cout<<ans[dx-1][dy-1]/5<<en;

	return 0;
}