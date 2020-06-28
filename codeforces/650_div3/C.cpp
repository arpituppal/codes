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
#define MAX 1000000

int main() {

	int t;
	cin>>t;
	while(t--) {

		int n, k, i, lhs[1000000], rhs[1000000], ans = 0, lastone = -1;
		char s[200005];

		cin>>n>>k;
		
		scanf("%s",s);

		lhs[0] = -1;
		for(i = 1 ; i < n; i++) {
			if(s[i-1] == '1') lhs[i] = i-1;
			else lhs[i] = lhs[i-1];
		}

		rhs[n-1] = -1;

		for(i = n-2 ; i >= 0; i--) {
			if(s[i+1] == '1') rhs[i] = i+1;
			else rhs[i] = rhs[i+1];
		}

		for(i = 0 ; i < n; i++) {

			if(s[i] == '1') {
				lastone = i;
				continue;
			}

			if(lastone == -1 && rhs[i] == -1) {
				ans++;
				lastone = i;

			} else if(lastone == -1 && rhs[i] - i > k) {
				ans++;
				lastone = i;
			}
			
			else if(rhs[i] == -1 && i-lastone > k) {
				ans++;
				lastone = i;

			}

			else if(i-lastone > k && rhs[i] - i > k) {
				ans++;
				lastone = i;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}