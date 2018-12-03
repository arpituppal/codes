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
#define MOD 1000000007
	
LL ans[1010][11];
LL mulfac[10] = {0,1,5,4,3,2,2,2,2,2};

int main () {

	int i, j, t, n;
	LL sum = 0;

	for(i = 1; i < 10; i++) {
		ans[1][i] = 1;
	}

	for(i = 2 ; i < 1001; i++) {

		for(j = 1; j < 10; j++) {
			ans[i][j] = ((ans[i-1][j] * mulfac[j]) % MOD);
		}
	}

	scanf("%d", &t);



	while(t--) {

		scanf("%d", &n);
		sum = 0;

		for(i = 1; i <10; i++) {
			sum = ((sum + ans[n][i]) % MOD);
		}

		printf("%lld\n", sum);
	}

	return 0;
}
