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

LL sumn(LL n, LL mod) {
	return (((n%mod)*((n+1)%mod))%mod)/2;
}


LL calculate(LL n, LL mod) {

	LL lastele = n % mod;

	LL sum = (((n/mod)%MOD) * ((sumn(mod-1, (2*MOD)))%MOD)%MOD);
	LL remsum = (sumn(lastele, (2*MOD))%MOD);

	return ((sum + remsum)%MOD);
}

int main() {


	LL l, r, mod, leftsum = 0, rightsum = 0, midsum = 0, ans = 0;
	scanf("%lld %lld %lld", &l, &r, &mod);

	ans = ((calculate(r, mod) - calculate(l-1, mod) + MOD)%MOD);
	printf("%lld\n", ans);

	return 0;
}