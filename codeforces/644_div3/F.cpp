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
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MP make_pair
#define PB push_back
#define getcx getchar_unlocked
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


void solve() {
	int n, m, i, j, flag = 0;
	vector<string> inpvec;
	string s, ans = "";

	cin>>n>>m;
	for(i = 0 ; i < n ; i++) {
		cin>>s;
		inpvec.PB(s);
	}

	ans = inpvec[0];
	for(i = 0 ; i < m; i++) {
		
		int oldchar = ans[i];

		for(j = 0; j < 26; j++) {

			ans[i] = (j+'a');
			flag = 0;
	
			for(int k = 0; k < n; k++) {

				int mismatch = 0;

				for(int x = 0 ; x < m; x++) {

					if(inpvec[k][x] != ans[x]) mismatch++;
				}

				if(mismatch > 1) {
					flag = 1;
					break;
				}

			}

			if(flag == 0) {
				cout<<ans<<endl;
				return;
			}
		}

		ans[i] = oldchar;
	}

	cout<<"-1"<<endl;
}

int main() {

	int t;
	cin>>t;
	while(t--) {

		solve();
	}

	return 0;
}