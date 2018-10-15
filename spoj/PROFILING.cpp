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
#define N 100010
 
LL fib[100010];

int main() {

	int i;
	fib[0] = 1;
	fib[1] = 1;

	for(i = 2 ; i <N; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	int t;
	scanf("%d", &t);
	while(t--) {
		int n, k;
		LL ans;

		scanf("%d %d", &n, &k);

		if(k > n) {
			printf("0\n");
			continue;
		}

		if(k == 0) {
			k = 2;		
		}

		printf("%lld\n", fib[n-k]);

	}

	return 0;

}