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


LL arr[1000010], cumsum[1000010];

int main() {

	int t;
	scanf("%d", &t);
	while(t--) {
		
		int i, j ,n;
		LL ans = 0, numpersons = 1;

		scanf("%d", &n);

		for(i = 1 ; i <=n; i++) {
			scanf("%d", &arr[i]);
			cumsum[i] = cumsum[i-1] + arr[i];
		}

		i = 1;
		while(i <= n && numpersons <n) {

			ans++;
			numpersons += cumsum[i];
			i += cumsum[i];
		}

		printf("%d\n", ans);
	}

	return 0;
}