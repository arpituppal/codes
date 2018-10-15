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

int main() {

	int t;
	scanf("%d", &t);
	while(t--) {

		vector<pair<int, int>> vec;
		int n, l, w, i, ans = 1;
		scanf("%d", &n);
		
		for(i = 0; i < n; i++){
			scanf("%d %d", &l, &w);
			vec.PB(MP(l, w));
		}

		sort(vec.begin(), vec.end());

		for(i = 1; i < vec.size(); i++) {

			if(vec[i].first < vec[i - 1].first || vec[i].second < vec[i - 1].second) {
				ans++;
			}
		}

		printf("%d\n", ans);
	}
	
	return 0;
}