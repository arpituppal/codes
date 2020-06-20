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
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define PB push_back
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))

int dp[1000001][2][2], n, k;
char s[1000001];

int solve(int pos, int last_val, int has_one_come) {

	if(pos >= n) {
		return 0;
	}

	if(dp[pos][last_val][has_one_come] != -1) {
		return dp[pos][last_val][has_one_come];
	}

	int ans;
	if(s[pos] == '1') {

		if(last_val == 1) {
			ans = solve(pos + k, 1, 1);
		} else {

			if(has_one_come == 1) {
				ans = 1 + solve(pos + k, 0, 1);
			} else {
				ans = min(1+solve(pos+k, 0, 0), solve(pos+k, 1, 1));
			}
		}

	} else {

		if(last_val == 1) {
			ans = min(1 + solve(pos + k, 1, 1), solve(pos+k, 0, 1));
		} else {

			if(has_one_come == 1) {
				ans = solve(pos+k, 0, 1);
			} else {

				ans = min(solve(pos+k, 0, 0), 1+solve(pos+k, 1, 1));
			}
		}
	}

	dp[pos][last_val][has_one_come] = ans;
	return dp[pos][last_val][has_one_come];

}

int main() {

	int t;
	cin>>t;
	while(t--) {
		int i, totalone = 0, ans = INF;
		
		cin>>n>>k;
		scanf("%s", s);

		for(i = 0 ; i < n; i++ ) {
			dp[i][0][0] = -1;
			dp[i][0][1] = -1;
			dp[i][1][0] = -1;
			dp[i][1][1] = -1;
		}


		for(i = 0 ; i < n ; i++) {
			if(s[i] == '1') totalone++;
		}

		for(i = 0 ; i < k; i++) {

			int set_one = 0;
			for(int j = i; j<n; j+=k) {
				if(s[j] == '1') {
					set_one++;
				}
			}

			ans = min(ans, solve(i, 0, 0) + (totalone - set_one)); 
		}

		cout<<ans<<endl;
 	}

	return 0;
}