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
#define MAX 1000000
#define in(x) scanf("%d", &x)
#define inl(x) scanf("%lld", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define inl2(x, y) scanf("%lld %lld", &x, &y)
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

int main() {

	int t,x;
	in(t);

	for(x = 1 ; x<= t; x++) {

		string in, out;
		char ans[60][60];

		int n, i, j;

		in(n);
		cin>>in;
		cin>>out;

		for(i = 0; i < n; i++) {

			ans[i+1][i+1] = 'Y';

			if(out[i] == 'N') {

				for(j = 1; j<=n; j++) {
					if(i+1!=j) ans[i+1][j] = 'N';
				}
			} else {

				for(j = i-1; j >= 0; j--) {

					if(in[j] != 'N') ans[i+1][j+1] = 'Y';
					else break;

					if(out[j] == 'N') {j--; break;}
				}

				for(; j>=0; j--) {
					ans[i+1][j+1] = 'N';
				}


				for(j = i+1; j < n; j++) {

					if(in[j] != 'N') {
						ans[i+1][j+1] = 'Y';
					}
					else break;

					if(out[j] == 'N') { j++; break;}
				}

				for(; j<n; j++) {
					ans[i+1][j+1] = 'N';
				}
			}

		}

		cout<<"Case #"<<x<<":"<<en;

		for(i = 1; i <=n ;i++) {
			for(j = 1; j <=n; j++) cout<<ans[i][j];

			cout<<en;
		}
	}

	return 0;
}