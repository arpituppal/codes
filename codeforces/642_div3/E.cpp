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

int cntlt[1000001], cntrt[1000001],dp[1000001], n, k, lastone = -1;
char s[1000001];

int solve(int currpos) {

	if(dp[currpos] != -1) {
		return dp[currpos];
	}

	//k = 3

	// 0 0 1 0 0 

	//1 0 0 0 0 0 

	// k
	// 1 0 

	int ans;
	//printf("currpos %d nextpos %d cntnext %d cntcur %d\n", currpos, nextpos, cnt[nextpos], cnt[currpos]);

	if(s[currpos] == '1') {

		if(currpos + k >= n ){
			ans = cntrt[currpos];
			//printf("YES curr %d %d\n", currpos, ans);
		} else {

			ans  = ((cntlt[currpos + k] - cntlt[currpos] - 1) + solve(currpos + k));
		}

	} else {

		int toadd = cntrt[currpos] == 0 ? 0 : 1;

		if(currpos + k >=n ) {
			ans = cntrt[currpos] + toadd;
		} else {

			ans = ((cntlt[currpos + k] - cntlt[currpos]) + toadd + solve(currpos + k));
		}
	}

	dp[currpos] = ans;
	return dp[currpos];
}

int main() {

	int t;
	cin>>t;
	while(t--) {
		int i;
		
		cin>>n>>k;
		scanf("%s", s);

		for(i = 0 ; i < n ; i++) {
			dp[i] = -1;
			cntlt[i] = 0;
			cntrt[i] = 0;
		}

		lastone = -1;

		cntlt[0] = 0;

		for(i = 0 ;i < n-1; i++) {
			if(s[i] == '0') {
				cntlt[i+1] = cntlt[i];
			} else {
				cntlt[i+1] = cntlt[i] + 1;
			}
		}

		for(i = n-1;i>=0; i--) {
			if(s[i+1] == '1') {
				cntrt[i] = cntrt[i+1] + 1;

				if(lastone == -1) {
					lastone = i+1;
				}

			} else {
				cntrt[i] = cntrt[i+1];
			}
		}

		cntrt[n-1] = 0;
		
		//<<dp[0] << " blah " << cntlt[0] <<endl;


		for(i = 0 ; i < n; i++) {
			solve(i);
		}

		// cout<<endl;
		// for(i = 0 ;i < n ; i++) {
		// 	printf("%d ", dp[i]);
		// }
		//cout<<dp[0] << " blah " << cntlt[0] <<endl;
		int mini = dp[0] + cntlt[0];

		for(i = 1; i < n; i++) {
			mini = min(mini, dp[i] + cntlt[i]);
 		}

 		cout<<mini<<endl;
 	}

	return 0;
}