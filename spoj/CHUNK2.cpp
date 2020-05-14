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
#define N 10000000


int isprime[N], parent[100010];
vector<int> primes;


int find(int u) {

	if(u == parent[u]) return u;

	int root = find(parent[u]);
	parent[u] = root;
	return root;
}

void uni(int u, int v) {

	int parentu = find(u);
	int parentv = find(v);
	if(parentu != parentv) {
		parent[parentu] = parentv;
	}

}

void sieve() {

	int i, j;

	for(i = 2; i*i < N; i++) {

		if(!isprime[i]) {
			primes.PB(i);

			for(j = i*i; j < N; j += i) {
				isprime[j] = 1;
			}

		}
	}

	for(; i < N; i++) {
		if(!isprime[i]) {
			primes.PB(i);
		}
	}
}



int main() {
	int t;

	sieve();
	scanf("%d", &t);

	while(t--) {

		int n, u, v, m, mxsize = -1, i;

		int ans[100010] = {0};

		scanf("%d %d", &n, &m);

		for(i = 1; i <=n; i++) {
			parent[i] = i;
		}

		for(i = 1; i <=m ;i++) {

			scanf("%d %d", &u, &v);
			uni(u,v);
		}


		if(m == 0) {
			printf("-1\n");
			continue;
		}

		for(i = 1; i <= n; i++) {

			int par = find(i);
			ans[par]++;
		}

		for(i = 1; i <=n ;i++) {
			mxsize = MAX(mxsize, (ans[i]));
		}

		printf("%d\n", primes[mxsize-1]);
	}

	return 0;
}
